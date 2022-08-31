.PHONY: help build install uninstall clean

help:
	@printf "make:\n\tbuild\n\tinstall\n\tuninstall\n\tclean\n"

build:
	@printf 	"\033[1;33m[ BUILDING ST ]\033[0m\n"
	@cd st 		&& make && cd ..
	@printf 	"\033[1;33m[ BUILDING DMENU ]\033[0m\n"
	@cd dmenu && make && cd ..
	@printf 	"\033[1;33m[ BUILDING DWM ]\033[0m\n"
	@cd dwm 	&& make && cd ..
	@printf 	"\033[1;33m[ BUILDING SLOCK ]\033[0m\n"
	@cd slock && make && cd ..

install: build
	@printf 	"\033[1;32m[ INSTALLING ST ]\033[0m\n"
	@cd st 		&& make install && cd ..
	@printf 	"\033[1;32m[ INSTALLING DMENU ]\033[0m\n"
	@cd dmenu && make install && cd ..
	@printf 	"\033[1;32m[ INSTALLING DWM ]\033[0m\n"
	@cd dwm 	&& make install && cd ..
	@printf 	"\033[1;32m[ INSTALLING SLOCK ]\033[0m\n"
	@cd slock && make install && cd ..

uninstall:
	@printf 	"\033[1;31m[ UNINSTALLING ST ]\033[0m\n"
	@cd st 		&& make uninstall && cd ..
	@printf 	"\033[1;31m[ UNINSTALLING DMENU ]\033[0m\n"
	@cd dmenu && make uninstall && cd ..
	@printf 	"\033[1;31m[ UNINSTALLING DWM ]\033[0m\n"
	@cd dwm 	&& make uninstall && cd ..
	@printf 	"\033[1;31m[ UNINSTALLING SLOCK ]\033[0m\n"
	@cd slock && make uninstall && cd ..

clean:
	@printf 	"\033[1;35m[ CLEANING ]\033[0m\n"
	@cd st 		&& make clean && cd ..
	@cd dmenu && make clean && cd ..
	@cd dwm 	&& make clean && cd ..
	@cd slock && make clean && cd ..
