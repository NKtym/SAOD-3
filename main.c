#include <stdio.h>
#include <time.h>

#include "minheap.h"
#include "graph.h"

int main() 
{
    int src = 1;
    struct graph *g;
    g = graph_create(20);
    for(int i=0;i<19;i++){
    	graph_set_edge(g, i, i+1, 1);
    }
    double t = wtime();
    Dijekstra(g, src);
    printf("time = %.10lf \n",wtime()-t);
    for(int i=0;i<20;i++){
	for(int j=0;j<20;j++)
    	    printf("%d",g->m[i][j]);
	printf("\n");
    }
    printf("Graph | vertex: %d\n", g->nvertices);
    for (int i = 0; i < g->nvertices && i < 20; i++) {
    	printf("%2.1d ", g->D[i + 1]);
    }
    printf("\n");
    for (int i = 0; i < g->nvertices && i < 20; i++) {
    	printf("%2.1d ", g->prev[i + 1]);
    }
    printf("\n");
    graph_free(g);
    return 0;
}
