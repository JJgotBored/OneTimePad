CC = gcc
CFLAGS = -Wall -std=c11
LDFLAGS = -L.

INC = include/
SRC = src/
BIN = bin/


main: $(BIN)libonetimepad.so

$(BIN)libonetimepad.so: $(BIN)OneTimePadAPI.o
	$(CC) -shared -o $(BIN)libonetimepad.so $(BIN)OneTimePadAPI.o

$(BIN)OneTimePadAPI.o: $(SRC)OneTimePadAPI.c $(INC)OneTimePadAPI.h 
	$(CC) $(CFLAGS) -c -fpic -I$(INC)OneTimePadAPI.h $(SRC)OneTimePadAPI.c -o $(BIN)OneTimePadAPI.o