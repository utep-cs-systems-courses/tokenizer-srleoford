CFLAGS = -g -O3
EXEC = main tester

all: main tester

main.o: tokenizer.c history.c main.c
	gcc -c $^ $(CFLAGS)
tester.o: tokenizer.h history.h tester.c
	gcc -c $^ $(CFLAGS)

main: main.o
	gcc -o $@ $^ $(CFLAGS)
tester: tester.o
	gcc -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o *~ *.h.gch $(EXEC) 
