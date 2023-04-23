test: maintest.o graph.o queue.o minheap.o
	gcc -Wall -O0 -g  -o test graph.o queue.o minheap.o maintest.o
test2: maintest2.o graph.o queue.o minheap.o
	gcc -Wall -O0 -g  -o test2 graph.o queue.o minheap.o maintest2.o -lm
app: main.o graph.o queue.o minheap.o
	gcc -Wall -O0 -g  -o app graph.o queue.o minheap.o main.o
app2: main2.o graph.o queue.o minheap.o
	gcc -Wall -O0 -g  -o app2 graph.o queue.o minheap.o main2.o -lm
main.o: main.c
	gcc -Wall -O0 -g  -c -o main.o main.c
main2.o: main2.c
	gcc -Wall -O0 -g  -c -o main2.o main2.c
maintest.o: maintest.c
	gcc -Wall -O0 -g -c -o maintest.o maintest.c
maintest2.o: maintest2.c
	gcc -Wall -O0 -g -c -o maintest2.o maintest2.c
queue.o: queue.c
	gcc -Wall -O0 -g  -c -o queue.o queue.c
graph.o: graph.c
	gcc -Wall -O0 -g  -c -o graph.o graph.c
minheap.o: minheap.c
	gcc -Wall -O0 -g -c -o minheap.o minheap.c

clean: 
	rm *.o
