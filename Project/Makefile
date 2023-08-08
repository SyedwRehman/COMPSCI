CC = gcc
CFLAGS = -Wall -Wextra
all: main
main: main.o mymodel.o
	$(CC) $(CFLAGS) -o main main.o mymodel.o -lm -lsodium
main.o: main.c constants.h mymodel.h data.txt
	$(CC) $(CFLAGS) -c main.c
mymodel.o: mymodel.c mymodel.h
	$(CC) $(CFLAGS) -c mymodel.c

clean:
	rm -f main *.o
	rm -f mymodel*.o
