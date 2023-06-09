#include <stdio.h>
#include <stdio.h>
#include <math.h>

#include "minheap.h"
#include "graph.h"

int main() 
{
    int src = 1;
    struct graph *g;
    struct heap *Q = heap_create(9);
    g = graph_create(9);
    for (int i = 0; i < sqrt(g->nvertices); i++) {
    	for (int j = 0; j < sqrt(g->nvertices); j++) {
      	    int vertex = i * sqrt(g->nvertices) + j;
      	    if (j + 1 < sqrt(g->nvertices)) {
        	graph_set_edge(g, vertex, vertex+1, rand()%100);
 		graph_set_edge(g, vertex+1, vertex, rand()%100);
      	    }
      	    if (i + 1 < sqrt(g->nvertices)) {
        	graph_set_edge(g, vertex, vertex + sqrt(g->nvertices), rand()%100);
        	graph_set_edge(g, vertex + sqrt(g->nvertices), vertex, rand()%100);
      	    }
    	}
    }
    double t = wtime();
    Dijekstra(g, Q, src, 9);
    printf("time = %.10lf \n",wtime()-t);
    printf("Graph | vertex: %d\n", g->nvertices);
    for(int i=0;i<9;i++){
	for(int j=0;j<9;j++)
    	    printf("%d ",g->m[i][j]);
	printf("\n");
    }
    printf("\n");
    printf("D:");
    for (int i = 0; i < g->nvertices && i < 9; i++) {
    	printf("%2.1d ", Q->D[i + 1]);
    }
    printf("\n");
/*    printf("prev:");
    for (int i = 0; i < g->nvertices && i < 9; i++) {
    	printf("%2.1d ", Q->prev[i + 1]);
    }
*/
    printf("path:");
    Search_shortest_path(Q,g,src,9);
    printf("\n");
    graph_free(g);
    return 0;
}
