const _ = require('lodash');
const fs = require('fs');
const ejs = require('ejs');
const path = require('path');

const escapeForID = (id) => {
    return id.replace(/\.| /g, '_');
};

const getProblemCodePrefix = (s) => {
    const matches = /^(\w+)\-?/.exec(s);
    if (matches) {
        return matches[1];
    }
};

const extractProblemName = (code, file, dir) => {
    // try to extract directly
    const filenameMatches = new RegExp(`^${code}\\s*-\\s*(.+)\\.\\w+$`).exec(file);
    if (filenameMatches) {
        return filenameMatches[1];
    }
    // from the file content
    const content = fs.readFileSync(path.join(dir, file), 'utf-8');
    const filecontentMatches = new RegExp(`^\\s*#*\\s*${code}\\s*\\-?\\s*(.+)$`, 'gm').exec(content);
    if (filecontentMatches) {
        return filecontentMatches[1];
    }
};

const listFiles = (dir, blacklist) => {
    try {
        return _.filter(fs.readdirSync(dir)
            .map((file) => {
                if (!fs.statSync(path.join(dir, file)).isDirectory()) {
                    return file;
                }
            }), (file) => {
                if (!file) {
                    return false;
                }
                if (blacklist) {
                    return !_.some(blacklist, (pattern) => (_.toLower(file).startsWith(_.toLower(pattern))));
                }
                return true;
            });
    } catch (e) {
        return [];
    }
}

const listProblems = (roundPath) => {
    const solutionFiles = listFiles(roundPath, ['readme']);
    const statementPath = path.join(roundPath, 'problems');
    const statementFiles = listFiles(statementPath, ['readme']);
    const editorialPath = path.join(roundPath, 'editorials');
    const editorialFiles = listFiles(editorialPath, ['readme']);

    const problemCodes = _.sortBy(_.uniq(_.concat(
        solutionFiles.map(getProblemCodePrefix),
        statementFiles.map(getProblemCodePrefix)
    )));
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
        let statement = _.find(statementFiles, (name) => (name.startsWith(code)));
        let name;
        if (statement) {
            name = extractProblemName(code, statement, statementPath);
            statement = path.relative(__dirname, path.join(statementPath, statement));
        }
        let editorial = _.find(editorialFiles, (name) => (name.startsWith(code)));
        if (editorial) {
            editorial = path.relative(__dirname, path.join(editorialPath, editorial));
        }
        return {
            name,
            code,
            statement,
            solutions,
            editorial,
        };
    });
    return problems;
}

const contests = _.orderBy(_.filter(fs.readdirSync(__dirname)
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
                if (subdir === 'problems' || subdir === 'editorials') {
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
                humanizedFullName: `${name} ${year}`,
                problems: listProblems(contestPath),
            });
            onlyround = true;
        }

        return {
            code,
            name,
            year,
            rounds,
            onlyround,
        };
    })), ['year', 'code'], ['desc', 'asc']);

console.log('[GENERATOR] Successfully generated contest data:');
console.log(JSON.stringify(contests, null, 2));

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

