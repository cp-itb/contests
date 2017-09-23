$(function() {
    $('.contest-tab').on('shown.bs.tab', function(e) {
        var target = $(e.target);
        var relatedTarget = $(e.relatedTarget);
        // Remove all active class on hidden tab
        $(relatedTarget.attr('href')).find('.active').removeClass('active');
        // Show #overview
        $(target.attr('href')).find('[data-toggle="tab"]').first().tab('show');
    });
    $('.problem-link').on('click', function(e) {
        e.preventDefault();
        console.log($(this).attr('href'));
        $($(this).attr('href')).tab('show');
    });
    $('.ajaxfileloader').on('shown.bs.tab', function(e) {
        var target = $($(e.target).attr('href'));

        // Load file
        if (target.data('fileloaded') === 'true') {
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
            var format = source.split('.').pop();
            if (format === 'md') {
                target.html(new showdown.Converter({
                    tables: true,
                }).makeHtml(res));
            } else {
                target.html('<pre><code class="' + format + '">' + res + '</code></pre>');
                target.find('pre code').each(function(_, block) {
                    hljs.highlightBlock(block);
                });
            }
            if (callback) {
                callback(null, res);
            }
        })
        .fail(function(err) {
            if (callback) {
                callback(err);
            }
        });
}