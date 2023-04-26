#include <stdio.h>
#include <time.h>

#include "minheap.h"
#include "graph.h"

int main() 
{
    int src = 1;
    struct graph *g;
    struct heap *Q = heap_create(20);
    g = graph_create(20);
    for(int i=0;i<19;i++){
    	graph_set_edge(g, i, i+1, rand()%100);
    }
    graph_set_edge(g, 0, g->nvertices-1, rand()%100);
    double t = wtime();
    Dijekstra(g, Q, src,20);
    printf("time = %.10lf \n",wtime()-t);
    for(int i=0;i<20;i++){
	for(int j=0;j<20;j++)
    	    printf("%d ",g->m[i][j]);
	printf("\n");
    }
    printf("Graph | vertex: %d\n", g->nvertices);
    printf("D:");
    for (int i = 0; i < g->nvertices && i < 20; i++) {
    	printf("%2.1d ", Q->D[i + 1]);
    }
    printf("\n");
    printf("prev:");
    for (int i = 0; i < g->nvertices && i < 20; i++) {
    	printf("%2.1d ", Q->prev[i + 1]);
    }
    printf("\n");
    graph_free(g);
    return 0;
}
