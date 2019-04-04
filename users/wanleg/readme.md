# Updating a feature branch

First we'll update your local master branch. Go to your local project and check out the branch you want to merge into (your local master branch)
```bash
$ git checkout master
```

Fetch the remote, bringing the branches and their commits from the remote repository.
You can use the -p, --prune option to delete any remote-tracking references that no longer exist in the remote. Commits to master will be stored in a local branch, remotes/origin/master
```bash
$ git fetch -p origin
```

Merge the changes from origin/master into your local master branch. This brings your master branch in sync with the remote repository, without losing your local changes. If your local branch didn't have any unique commits, Git will instead perform a "fast-forward".
```bash
$ git merge origin/master
```

Check out the branch you want to merge into
```bash
$ git checkout <feature-branch>
```

Merge your (now updated) master branch into your feature branch to update it with the latest changes from your team.
```bash
$ git merge master
```

Depending on your git configuration this may open vim. Enter a commit message, save, and quit vim e.g. press "a" to enter insert mode and append text following current cursor position, press Esc key to enter command mode, press :wq to write the file to disk and quit.

This only updates your local feature branch. To update it on GitHub, push your changes.
```bash
$ git push origin <feature-branch>
```

# Delete Git branch locally and remotely

Executive Summary
```bash
$ git push --delete <remote_name> <branch_name>
$ git branch -d <branch_name>
```
Note that in most cases the remote name is origin.

Delete Local Branch
To delete the local branch use one of the following:
```bash
$ git branch -d branch_name
$ git branch -D branch_name
```
Note: The -d option is an alias for --delete, which only deletes the branch if it has already been fully merged in its upstream branch. You could also use -D, which is an alias for --delete --force, which deletes the branch "irrespective of its merged status." [Source: man git-branch]

Delete Remote Branch [Updated on 8-Sep-2017]
As of Git v1.7.0, you can delete a remote branch using
```bash
$ git push <remote_name> --delete <branch_name>
```
which might be easier to remember than
```bash
$ git push <remote_name> :<branch_name>
```
which was added in Git v1.5.0 "to delete a remote branch or a tag."

Starting on Git v2.8.0 you can also use `git push` with the `-d` option as an alias for `--delete`.

Therefore, the version of Git you have installed will dictate whether you need to use the easier or harder syntax.