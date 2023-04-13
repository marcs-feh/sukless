#!/usr/bin/env python

from sys import argv
from os import chdir
from subprocess import call

programs = ['dwm', 'st', 'dwmblocks', 'dmenu', 'slock']

def build():
  for prog in programs:
    print(f'[Building {prog}]')
    chdir(prog)
    call(['make'])
    chdir('..')

def install():
  for prog in programs:
    print(f'[Installing {prog}]')
    chdir(prog)
    call(['make', 'install'])
    chdir('..')

def uninstall():
  for prog in programs:
    print(f'[Uninstalling {prog}]')
    chdir(prog)
    call(['make', 'uninstall'])
    chdir('..')

def clean():
  for prog in programs:
    print(f'[Cleaning {prog}]')
    chdir(prog)
    call(['make', 'clean'])
    chdir('..')

def main():
  if len(argv) < 2:
    print('./install.py [build|install|clean|uninstall]')
    return

  cmd = argv[1]

  match cmd:
    case 'build': build()
    case 'install': install()
    case 'uninstall': uninstall()
    case 'clean': clean()
    case _: 
      print('./install.py [build|install|clean|uninstall]')
      return

if __name__ == '__main__': main()
