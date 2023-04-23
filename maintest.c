#include <stdio.h>
#include <sys/time.h>

#include "minheap.h"
#include "graph.h"

int main() 
{
    int src = 1;
    struct graph *g;
    g = graph_create(5);
    for(int i=0;i<5;i++){
	for(int j=i+1;j<5;j+=2)
    	    graph_set_edge(g, i, j, 1);
    }
    printf("DFS:\n");
    graph_dfs(g, 1);
    printf("BFS:\n");
    graph_bfs(g, 2);
    double t = wtime();
    Dijekstra(g, src);
    printf("time = %.10lf \n",wtime()-t);
    printf("Graph | vertex: %d\n", g->nvertices);
    for(int i=0;i<5;i++){
	for(int j=0;j<5;j++)
    	    printf("%d",g->m[i][j]);
	printf("\n");
    }
    for (int i = 0; i < g->nvertices && i < 5; i++) {
    	printf("%2.1d ", g->D[i + 1]);
    }
    printf("\n");
    for (int i = 0; i < g->nvertices && i < 5; i++) {
    	printf("%2.1d ", g->prev[i + 1]);
    }
    printf("\n");
    graph_free(g);
    return 0;
}
