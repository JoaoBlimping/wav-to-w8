INSTALL_PATH = /usr/local
SRC = src
BIN = bin
CC = g++
OUTPUT = wavToW8
FLAGS = -lsndfile

all:
	$(CC) $(SRC)/*.cc -o $(BIN)/$(OUTPUT) $(FLAGS)

install: all
	#copy the executables
	sudo cp bin/* $(INSTALL_PATH)/bin/$*
