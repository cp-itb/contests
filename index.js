const _ = require('lodash');
const fs = require('fs');
const path = require('path');

const listProblems = (roundPath) => {
    const problems = fs.readdirSync(roundPath)
        .map((file) => {
            if (fs.statSync(path.join(roundPath, file)).isDirectory()) {
                return;
            }
            const matches = /^(\w+)\-?/.exec(file);
            if (matches) {
                return matches[1];
            }
        });
    return _.sortedUniq(_.filter(problems));
    // TODO: compare with problems (and possibly get the problem's name too)
}

const contests = [];
fs.readdirSync(__dirname)
    .map((dir) => {
        if (dir.startsWith('.') || dir === 'template' || dir === 'node_modules') {
            return;
        }
        if (!fs.statSync(dir).isDirectory()) {
            return;
        }

        // parse year from directory name
        let name = dir, year = null;
        const matches = /^(.*)(\d{4})$/.exec(dir);
        if (matches) {
            name = matches[1];
            year = matches[2];
        }

        // Search down for one more level to determine rounds.
        // If no directory is found, then it is the only round in the contest.
        let rounds = [];
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
                    name: subdir,
                    problems: listProblems(roundPath),
                });
            });
        if (rounds.length === 0) {
            rounds.push({
                name: '.',
                problems: listProblems(contestPath),
            });
        }

        contests.push({
            name,
            year,
            rounds,
        });
    });

console.log(JSON.stringify(contests, null, 2));
