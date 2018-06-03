all: hello

hello: main.o graph.o algorithms.o
	gcc main.o graph.o algorithms.o -o hello

main.o: main.c
	gcc -c main.c

graph.o: graph.c
	gcc -c graph.c

algorithms.o: algorithms.c
	gcc -c algorithms.c
	
clean:
	rm *o hello