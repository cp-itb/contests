$(function() {
    $('.contest-tab').on('shown.bs.tab', function(e) {
        var target = $(e.target);
        // Remove all active class on hidden tab
        var targetContent = $(target.attr('href'));
        targetContent.parent().find('.active').not(targetContent).removeClass('active');
        // Show #overview
        targetContent.find('[data-toggle="tab"]').first().tab('show');
    });
    $('.problem-link').on('click', function(e) {
        e.preventDefault();
        $($(this).attr('href')).tab('show');
    });
    $('.problem-tab').on('shown.bs.tab', function(e) {
        var target = $(e.target);
        // Remove all active class on hidden tab
        var targetContent = $(target.attr('href'));
        targetContent.parent().find('.active').not(targetContent).removeClass('active');
        // Show #overview
        targetContent.find('[data-toggle="list"]').first().tab('show');
    });
    $('.ajaxfileloader').on('shown.bs.tab', function(e) {
        var target = $($(e.target).attr('href'));

        // Load file
        if (target.data('fileloaded') === 'true') {
            return;
        }
        if (!target.data('filesource')) {
            return;
        }
        loadFile(target.data('filesource'), target, function(err) {
            if (!err) {
                target.data('fileloaded', 'true');
            }
        });
    });

    // Update URL hash on tab shown
    $('[data-toggle="tab"],[data-toggle="list"]').on('show.bs.tab', function (e) {
        var href = $(this).attr('href');
        location.hash = href;
    });

    // Parse URL hash and view appropriate tab, sequentially
    function showTab(url, separatorIndex) {
        var tab = url;
        if (!separatorIndex) {
            separatorIndex = url.indexOf('-');
        }
        if (separatorIndex !== -1) {
            tab = url.slice(0, separatorIndex);
        }
        function showNextTab() {
            if (separatorIndex !== -1) {
                return setTimeout(function() {
                    showTab(url, url.indexOf('-', separatorIndex + 1));
                }, 0);
            }
        }

        var elem = $('[href="#' + tab + '"]');
        if (elem.length === 0) {
            showNextTab();
        }

        function shownListener() {
            showNextTab();
            elem.off('shown.bs.tab', shownListener);
        }
        elem.on('shown.bs.tab', shownListener);
        elem.tab('show');
    }

    var hash = location.hash.replace('#', '');
    if (hash) {
        showTab(hash);
    }
});

function escapeHTML(text) {
    return $('<div/>').text(text).html();
}

function loadFile(source, target, callback) {
    $.get(source)
        .done(function(res) {
            var format = source.split('.').pop();
            if (format === 'md') {
                var html = new showdown.Converter({
                    tables: true,
                }).makeHtml(res);
                var container = $('<div/>').addClass('markdown-body').html(html);
                renderMathInElement(container.get(0), {
                    delimiters: [
                        { left: "$$", right: "$$", display: true },
                        { left: "$", right: "$", display: false },
                    ],
                });
                target.html(container);
            } else if (format === 'pdf') {
                var container = $('<iframe/>', {
                    src: source,
                    width: '100%',
                    height: '700px'
                });
                target.html(container);
            } else {
                var escaped = escapeHTML(res);
                var container = $('<pre/>').html($('<code/>').addClass(format).html(escaped));
                target.html(container);
                target.find('pre code').each(function(_, block) {
                    hljs.highlightBlock(block);
                });
            }
            if (callback) {
                callback(null, escaped);
            }
        })
        .fail(function(err) {
            if (callback) {
                callback(err);
            }
            target.html('Some error occured');
        });
}