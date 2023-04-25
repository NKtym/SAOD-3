#include <stdio.h>
#include <sys/time.h>

#include "minheap.h"
#include "graph.h"

int main() 
{
    int src = 1;
    struct graph *g;
    g = graph_create(5);
    graph_set_edge(g, 0, 1, 10);
    graph_set_edge(g, 0, 4, 100);
    graph_set_edge(g, 0, 3, 30);
    graph_set_edge(g, 1, 2, 50);
    graph_set_edge(g, 2, 3, 20);
    graph_set_edge(g, 1, 4, 10);
    graph_set_edge(g, 3, 4, 60);	
    printf("DFS:\n");
    graph_dfs(g, 1);
    printf("BFS:\n");
    graph_bfs(g, 2);
    double t = wtime();
    Dijekstra(g, src, 5);
    printf("time = %.10lf \n",wtime()-t);
    printf("Graph | vertex: %d\n", g->nvertices);
    printf("\n");
    for(int i=0;i<5;i++){
	for(int j=0;j<5;j++)
    	    printf("%d ",g->m[i][j]);
	printf("\n");
    }
    printf("\n");
    printf("D:");
    for (int i = 0; i < g->nvertices && i < 5; i++) {
    	printf("%2.1d ", g->D[i + 1]);
    }
    printf("\n");
    printf("prev:");
    for (int i = 0; i < g->nvertices && i < 5; i++) {
    	printf("%2.1d ", g->prev[i + 1]);
    }
    printf("\n");
    graph_free(g);
    return 0;
}
