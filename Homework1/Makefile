CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: myshell myhead myuniq

myshell: myshell.o
	$(CC) $(CFLAGS) -o myshell myshell.o

myhead: myhead.o
	$(CC) $(CFLAGS) -o myhead myhead.o

myuniq: myuniq.o
	$(CC) $(CFLAGS) -o myuniq myuniq.o

# Compile all C files
myshell.o: myshell.c
	$(CC) $(CFLAGS) -c myshell.c

myhead.o: myhead.c
	$(CC) $(CFLAGS) -c myhead.c

myuniq.o: myuniq.c
	$(CC) $(CFLAGS) -c myuniq.c

clean:
	rm -f myshell myhead myuniq *.o
