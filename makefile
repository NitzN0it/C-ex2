CC=gcc
AR=ar
CFLAGS=-Wall
OBJ= myBank.c main.c
all: mybank
mybank: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o main
.PHONY: clean all

clean:
	rm -f *.o *.a *.so main