all: app

app: main.o graph.o queue.o
	gcc -Wall -O0 -g  -o app graph.o queue.o main.o 
main.o: main.c
	gcc -Wall -O0 -g  -c -o main.o main.c
queue.o: queue.c
	gcc -Wall -O0 -g  -c -o queue.o queue.c
graph.o: graph.c
	gcc -Wall -O0 -g  -c -o graph.o graph.c


clean: 
	rm *.o
