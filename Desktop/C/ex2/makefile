CC=gcc
AR=ar
CFLAGS=-Wall
OBJ= myBank.o myBank.h
all: mybanko mybank
mybanko: $(OBJ)
	$(CC) -c myBank.c -o myBank.o 
mybank: myBank.o
	$(CC) $(CFLAGS) myBank.o -o myBank
.PHONY: clean all

clean:
	rm -f *.o *.a *.so myBank