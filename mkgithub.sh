#!/bin/bash


email=${email:-"omerfrank6@gmail.com"}
gituser=omerfrank
dryrun=

function Usage() {
	echo "Usage: $(basename $0) <git repo name>"
	echo "  -e|--email <email>    [$email]"
	echo "  -u|--user <gituser>   [$gituser]"
	echo "  -d|--dryrun"
	echo 
	echo "	Example:"
	echo " 		$(basename $0) --email omerfrank6@gmail.com --user omerfrank c-tut"
	echo
	exit 1
}

while [[ "$1" =~ ^-.* ]]; do
	echo "Processing $1"
	case $1 in
	--email | -e)
		email=$2
		shift 1
		;;
	--user | -u)
		gituser=$2
		shift 1
		;;
	--dryrun | -d)
		dryrun=yes
		;;
	*)
		echo "Warning: ignore $1" > /dev/stderr
		;;
	esac
	shift 1
done

repo=$1

[ -z "$dryrun" ] || Usage
[ "$repo" ] || Usage

ssh-keygen -C ${email} -f ~/.ssh/github-"$repo"

[ -f ~/.ssh/config ] && cp ~/.ssh/config ~/.ssh/"config.$(date +%s)"

cat >> ~/.ssh/config <<-EOF
Host github-$repo
  HostName github.com
  User git
  IdentityFile $HOME/.ssh/github-$repo
  IdentitiesOnly yes
EOF

chmod 600 ~/.ssh/config

echo "# Add the following key to the $repo deploy keys with write perm!"
cat $HOME/.ssh/github-"$repo".pub

echo "# And then either clone the repo by:"
echo git clone git@github-"$repo":$gituser/"$repo".git

echo
echo "# Or push an existing git to it by:"
echo git remote add -m master -t master github git@github-"$repo":$gituser/"$repo".git
echo git push github


