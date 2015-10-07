INSTALL_PATH = /usr/local
SRC = src

all:
	

install: all
	#copy the executables
	sudo cp bin/* $(INSTALL_PATH)/bin/$*
