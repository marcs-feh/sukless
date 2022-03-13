.PHONY: help build install uninstall clean

help:
	@printf "make:\n      build\n      install\n      uninstall\n      clean\n"

build:
	@printf 	"\033[1;33m<< BUILDING ST >>\033[0m\n"
	@cd st 		&& make && cd ..
	@printf 	"\033[1;33m<< BUILDING DMENU >>\033[0m\n"
	@cd dmenu 	&& make && cd ..
	@printf 	"\033[1;33m<< BUILDING DWM >>\033[0m\n"
	@cd dwm 	&& make && cd ..
	@printf 	"\033[1;33m<< BUILDING DWMBLOCKS >>\033[0m\n"
	@cd dwmblocks	&& make && cd ..

install: build
	@printf 	"\033[1;32m<< INSTALLING ST >>\033[0m\n"
	@cd st 		&& make install && cd ..
	@printf 	"\033[1;32m<< INSTALLING DMENU >>\033[0m\n"
	@cd dmenu 	&& make install && cd ..
	@printf 	"\033[1;32m<< INSTALLING DWM >>\033[0m\n"
	@cd dwm 	&& make install && cd ..
	@printf 	"\033[1;32m<< INSTALLING DWMBLOCKS >>\033[0m\n"
	@cd dwmblocks	&& make install && cd ..

uninstall:
	@printf 	"\033[1;31m<< UNINSTALLING ST >>\033[0m\n"
	@cd st 		&& make uninstall && cd ..
	@printf 	"\033[1;31m<< UNINSTALLING DMENU >>\033[0m\n"
	@cd dmenu 	&& make uninstall && cd ..
	@printf 	"\033[1;31m<< UNINSTALLING DWM >>\033[0m\n"
	@cd dwm 	&& make uninstall && cd ..
	@printf 	"\033[1;31m<< UNINSTALLING DWMBLOCKS >>\033[0m\n"
	@cd dwmblocks	&& make uninstall && cd ..

clean:
	@printf 	"\033[1;35m<< CLEANING >>\033[0m\n"
	@cd st 		&& make clean && cd ..
	@cd dmenu 	&& make clean && cd ..
	@cd dwm 	&& make clean && cd ..
	@cd dwmblocks 	&& make clean && cd ..
