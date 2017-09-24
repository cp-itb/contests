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
});

function loadFile(source, target, callback) {
    $.get(source)
        .done(function(res) {
            var escaped = $('<div/>').text(res).html()
            var format = source.split('.').pop();
            if (format === 'md') {
                var html = new showdown.Converter({
                    tables: true,
                }).makeHtml(escaped);
                target.html('<div class="markdown-body">' + html + '</div>');
            } else {
                target.html('<pre><code class="' + format + '">' + escaped + '</code></pre>');
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
        });
}