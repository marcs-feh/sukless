.PHONY: help build install uninstall clean

help:
	@printf "make:\n      build\n      install\n      uninstall\n      clean\n"

build:
	@echo "\033[1;33m<< BUILDING ST >>\033[0m"
	@cd st 		&& make && cd ..
	@echo "\033[1;33m<< BUILDING DMENU >>\033[0m"
	@cd dmenu 	&& make && cd ..
	@echo "\033[1;33m<< BUILDING DWM >>\033[0m"
	@cd dwm 	&& make && cd ..

install: build
	@echo "\033[1;32m<< INSTALLING ST >>\033[0m"
	@cd st 		&& make install && cd ..
	@echo "\033[1;32m<< INSTALLING DMENU >>\033[0m"
	@cd dmenu 	&& make install && cd ..
	@echo "\033[1;32m<< INSTALLING DWM >>\033[0m"
	@cd dwm 	&& make install && cd ..

uninstall:
	@echo "\033[1;31m<< UNINSTALLING ST >>\033[0m"
	@cd st 		&& make uninstall && cd ..
	@echo "\033[1;31m<< UNINSTALLING DMENU >>\033[0m"
	@cd dmenu 	&& make uninstall && cd ..
	@echo "\033[1;31m<< UNINSTALLING DWM >>\033[0m"
	@cd dwm 	&& make uninstall && cd ..

clean:
	@echo "\033[1;35m<< CLEANING >>\033[0m"
	@cd st 		&& make clean && cd ..
	@cd dmenu 	&& make clean && cd ..
	@cd dwm 	&& make clean && cd ..
