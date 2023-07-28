CC = gcc
CFLAGS = -Wall -Wextra
all: main
main: main.o readFile_randWord.o functions.o
	$(CC) $(CFLAGS) -o main main.o readFile_randWord.o functions.o
main.o: main.c constants.h functions.h readFile_randWord.h words_alpha.txt
	$(CC) $(CFLAGS) -c main.c
readFile_randWord.o: readFile_randWord.c readFile_randWord.h
	$(CC) $(CFLAGS) -c readFile_randWord.c
functions.o: functions.c functions.h
	$(CC) $(CFLAGS) -c functions.c

clean:
	rm -f main *.o
	rm -f functions*.o
	rm -f readFile_randWord*.o
