const _ = require('lodash');
const fs = require('fs');
const ejs = require('ejs');
const path = require('path');

const escapeForID = (id) => {
    return id.replace(/\.| /g, '_');
}

const listProblems = (roundPath) => {
    const solutionFiles = _.filter(fs.readdirSync(roundPath)
        .map((file) => {
            if (!fs.statSync(path.join(roundPath, file)).isDirectory()) {
                return file;
            }
        }));
    const problemCodes = _.sortedUniq(_.filter(solutionFiles.map((s) => {
        const matches = /^(\w+)\-?/.exec(s);
        if (matches) {
            return matches[1];
        }
    })));
    let statementFiles;
    try {
        statementFiles = fs.readdirSync(path.join(roundPath, 'problems'))
            .map((file) => {
                if (!fs.statSync(path.join(roundPath, 'problems', file)).isDirectory()) {
                    return file;
                }
            });
    } catch (e) {
        statementFiles = []
    }
    const statements = _.filter(statementFiles);
    const problems = problemCodes.map((code) => {
        const solutions = _.filter(solutionFiles, (s) => s.startsWith(code))
            .map((s) => {
                const author = s.replace(`${code}-`, '');
                const escapedAuthor = escapeForID(author);
                const p = path.relative(__dirname, path.join(roundPath, encodeURIComponent(s)));
                return {
                    author,
                    escapedAuthor,
                    path: p,
                };
            });
        let statement = _.find(statements, (name) => (name.startsWith(code)));
        if (statement) {
            statement = path.relative(__dirname, path.join(roundPath, 'problems', statement));
        }
        return {
            code,
            statement,
            solutions,
        }
    });
    return problems;
    // TODO: compare with problems (and possibly get the problem's name too)
}

const contests = [];
fs.readdirSync(__dirname)
    .map((dir) => {
        if (dir.startsWith('.') || dir === 'template' || dir === 'node_modules' || dir === 'assets') {
            return;
        }
        if (!fs.statSync(dir).isDirectory()) {
            return;
        }

        // parse year from directory name
        let code = escapeForID(dir),
            name = dir,
            year = null;
        const matches = /^(.*)(\d{4})$/.exec(dir);
        if (matches) {
            name = matches[1];
            year = matches[2];
        }

        // Search down for one more level to determine rounds.
        // If no directory is found, then it is the only round in the contest.
        let rounds = [],
            onlyround = false;
        const contestPath = path.join(__dirname, dir);
        fs.readdirSync(contestPath)
            .map((subdir) => {
                const roundPath = path.join(contestPath, subdir);
                if (!fs.statSync(roundPath).isDirectory()) {
                    return;
                }
                if (subdir === 'problems') {
                    return;
                }

                rounds.push({
                    code: `${code}-${escapeForID(subdir)}`,
                    name: subdir,
                    humanizedName: `${_.upperFirst(subdir)}`,
                    humanizedFullName: `${name} ${year} - ${_.upperFirst(subdir)}`,
                    problems: listProblems(roundPath),
                });
            });
        if (rounds.length === 0) {
            rounds.push({
                code: code,
                name: '.',
                humanizedName: `${name} ${year}`,
                problems: listProblems(contestPath),
            });
            onlyround = true;
        }

        contests.push({
            code,
            name,
            year,
            rounds,
            onlyround,
        });
    });

console.log('[GENERATOR] Successfully generated contest data:', contests);

/* From https://stackoverflow.com/questions/30976477/generate-static-html-files-from-ejs-templates */
const ejs2html = (path, target, data) => {
    fs.readFile(path, 'utf8', (err, file) => {
        if (err) {
            console.log(err);
            process.exit(1);
        }
        const html = ejs.compile(file)(data);
        fs.writeFile(target, html, (err) => {
            if (err) {
                console.log(err);
                process.exit(1);
            }

            console.log('[GENERATOR] Successfully generated index.html');
        });
    });
}

ejs2html(path.join(__dirname, 'template.ejs'), path.join(__dirname, 'index.html'), {
    contests: contests,
});

