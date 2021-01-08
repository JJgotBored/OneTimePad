CC = gcc
CFLAGS = -Wall -std=c11
LDFLAGS = -L.

INC = include/
SRC = src/
BIN = bin/

#builds .so for One Time Pad
library: $(BIN)libonetimepad.so

$(BIN)libonetimepad.so: $(BIN)OneTimePadAPI.o
	$(CC) -shared -o $(BIN)libonetimepad.so $(BIN)OneTimePadAPI.o

$(BIN)OneTimePadAPI.o: $(SRC)OneTimePadAPI.c $(INC)OneTimePadAPI.h 
	$(CC) $(CFLAGS) -c -fpic -I$(INC) $(SRC)OneTimePadAPI.c -o $(BIN)OneTimePadAPI.o

clean:
	rm -rf $(BIN)*.o $(BIN)*.so $(BIN)testMain $(BIN)demo

#build test harness
buildtest:
	$(CC) $(CFLAGS) src/testMain.c -Lbin -lonetimepad -I$(INC) -o bin/testMain

runtest:
	./bin/testMain

memtest:
	valgrind ./bin/testMain

#build demo
builddemo:
	$(CC) $(CFLAGS) src/OTPDemo.c -Lbin -lonetimepad -I$(INC) -o bin/demo

rundemo:
	./bin/demo

# export LD_LIBRARY_PATH=/home/jason/OneTimePad/bin