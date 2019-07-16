all: lcs

lcs: lcs.o client.o compare.o node.o list.o stack.o
	gcc -std=c99 compare.c lcs.c node.c list.c stack.c client.c -o long

client.o: compare.h lcs.h client.c
	gcc -std=c99 -c client.c

compare.o: compare.c compare.h
	gcc -std=c99 -c compare.c

lcs.o: lcs.c lcs.h
	gcc -std=c99 -c lcs.c

node.o: node.c node.h
	gcc -std=c99 -c node.c

list.o: node.c node.h list.c list.h
	gcc -std=c99 -c list.c

stack.o: node.c node.h list.c list.h stack.c stack.h
	gcc -std=c99 -c stack.c

clean:
	rm *.o long