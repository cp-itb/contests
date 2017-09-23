#!/bin/bash

# Abort script if there is a non-zero error
set -e

git checkout --orphan gh-pages
node index.js
git add -A
git commit --allow-empty -m "Deploy [ci skip]"
git push --force --quiet origin gh-pages > /dev/null 2>&1

echo "Finish!"