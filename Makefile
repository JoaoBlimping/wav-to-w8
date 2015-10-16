INSTALL_PATH = /usr/local
SRC = src
BIN = bin
CC = g++
OUTPUT=wavToW8

all:
	$(CC) $(SRC_DIR)/*.cc -o $(BIN_DIR)/$(OUTPUT)

install: all
	#copy the executables
	sudo cp bin/* $(INSTALL_PATH)/bin/$*
