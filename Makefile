main: main.o cache.o collatz.o
	gcc -o main main.o cache.o collatz.o
	
main.o:
	gcc -c main.c

cache.o: cache.c
	gcc -c cache.c

collatz.o: collatz.c
	gcc -c collatz.c

clean:
	rm -f main main.o cache.o collatz.o