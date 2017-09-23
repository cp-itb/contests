#!/bin/bash

# Abort script if there is a non-zero error
set -e

# Get a new clean gh-pages branch
git config --global user.email "ahmadzaky003@gmail.com" > /dev/null 2>&1
git config --global user.name "Ahmad Zaky" > /dev/null 2>&1
if git rev-parse --verify gh-pages > /dev/null 2>&1
then
    git branch -D gh-pages
fi
git checkout --orphan gh-pages

# Run the generator
node generator.js

# Publish the result
git add -A > /dev/null 2>&1
git commit --allow-empty -m "Deploy [ci skip]"
git push --force --quiet origin gh-pages

# Don't know what's this for, but locally it is neat to finish on master
git checkout master

echo "Finish!"