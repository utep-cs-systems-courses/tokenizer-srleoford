CFLAGS = -g -O3
EXEC = main

all: main

main.o: tokenizer.h history.h main.c
	gcc -c $^ $(CFLAGS)

main: main.o
	gcc -o $@ $^ $(CFLAGS)
clean:
	rm -f *.o $(EXEC) *~ 
