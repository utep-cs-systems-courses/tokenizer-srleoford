CFLAGS = -g -O3
EXEC = tokenizer

all: tokenizer

tokenizer.o: tokenizer.h

tokenizer: tokenizer.o
	gcc -o $@ $^ $(CFLAGS)
clean:
	rm -f *.o $(EXEC) *~ 
