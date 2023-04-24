#include <stdio.h>
#include <stdio.h>
#include <math.h>

#include "minheap.h"
#include "graph.h"

int main() 
{
    int src = 1;
    struct graph *g;
    g = graph_create(10000);
    for (int i = 0; i < sqrt(g->nvertices); i++) {
    	for (int j = 0; j < sqrt(g->nvertices); j++) {
      	    int vertex = i * sqrt(g->nvertices) + j;
      	    if (j + 1 < sqrt(g->nvertices)) {
        	graph_set_edge(g, vertex, vertex+1, 1);
 		graph_set_edge(g, vertex+1, vertex, 1);
      	    }
      	    if (i + 1 < sqrt(g->nvertices)) {
        	graph_set_edge(g, vertex, vertex + sqrt(g->nvertices), 1);
        	graph_set_edge(g, vertex + sqrt(g->nvertices), vertex, 1);
      	    }
	    g->m[0][g->nvertices-1]=0;
	    g->m[g->nvertices-1][0]=0;
    	}
    }
    double t = wtime();
    Dijekstra(g, src,10000);
    printf("time = %.10lf \n",wtime()-t);
/*    printf("Graph | vertex: %d\n", g->nvertices);
    for (int i = 0; i < g->nvertices && i < 10000; i++) {
    	printf("%2.1d ", g->D[i + 1]);
    }
    printf("\n");
    for (int i = 0; i < g->nvertices && i < 10000; i++) {
    	printf("%2.1d ", g->prev[i + 1]);
    }
*/    printf("\n");
    graph_free(g);
    return 0;
}
