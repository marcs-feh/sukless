#!/usr/bin/env bash

programs=('dwm' 'st' 'dmenu' 'slock' 'dwmblocks')

Build() { make; }
Install() { make install; }
Clean() { make clean; }
Uninstall() { make uninstall; }
Help() { echo 'build.bash [build|install|uninstall|clean]'; exit 1; }

action="$1"
case $action in
	'build') action=Build;;
	'install') action=Install;;
	'uninstall') action=Uninstall;;
	'clean') action=Clean;;
	*) action=Help ;;
esac

for p in ${programs[@]}; do
	cd $p
	$action
	cd ..
done
