.PHONY: help build install uninstall clean

help:
	@printf "make:\n    build\n    install\n    uninstall\n    clean\n"

build:
	@echo "<< BUILDING ST >>"
	@cd st 		&& make && cd ..
	@echo "<< BUILDING DMENU >>"
	@cd dmenu 	&& make && cd ..
	@echo "<< BUILDING DWM >>"
	@cd dwm 	&& make && cd ..

install: build
	@echo "<< INSTALLING ST >>"
	@cd st 		&& make install && cd ..
	@echo "<< INSTALLING DMENU >>"
	@cd dmenu 	&& make install && cd ..
	@echo "<< INSTALLING DWM >>"
	@cd dwm 	&& make install && cd ..

uninstall:
	@echo "<< UNINSTALLING ST >>"
	@cd st 		&& make uninstall && cd ..
	@echo "<< UNINSTALLING DMENU >>"
	@cd dmenu 	&& make uninstall && cd ..
	@echo "<< UNINSTALLING DWM >>"
	@cd dwm 	&& make uninstall && cd ..

clean:
	@echo "<< CLEANING >>"
	@cd st 		&& make clean && cd ..
	@cd dmenu 	&& make clean && cd ..
	@cd dwm 	&& make clan && cd ..
