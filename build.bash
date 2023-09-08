#!/usr/bin/env bash

programs=('dwm' 'st' 'dmenu' 'slock' 'dwmblocks')

Build='make'
Install='make install'
Clean='make clean'
Uninstall='make uninstall'
Help='build.bash [build|install|uninstall|clean]\n    Use `PREFIX="your_prefix" ./build.bash` to install to another location'

Action="$1"
case $Action in
	'build')     Action="$Build";;
	'install')   Action="$Install";;
	'uninstall') Action="$Uninstall";;
	'clean')     Action="$Clean";;
	*)           printf "$Help\n"; exit 1;;
esac


for p in ${programs[@]}; do

	cd $p

	if [ "$p" = "slock" ]; then
		if [ ! "$(whoami)" = "root" ]; then
			[ -z "$(which sudo)" ] \
				&& Doer=doas \
				|| Doer=sudo

				echo "WARNING: slock requires root to be built as it needs suid, using $Doer to aquire privilege"
			$Doer $Action
		fi
		$Action
	else
		$Action
	fi

	cd ..
done
