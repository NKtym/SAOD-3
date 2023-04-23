#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "graph.h"
#include "queue.h"
#include "minheap.h"

struct graph *graph_create(int nvertices)
{
    struct graph *g;
    g = malloc(sizeof(*g));
    g->nvertices = nvertices;
    g->m = malloc(sizeof(int) * nvertices * nvertices);
    g->visited = malloc(sizeof(int) * nvertices);
    graph_clear(g); 
    g->D = (int *)calloc(nvertices + 1, sizeof(int));
    g->H = (int *)calloc(nvertices + 1, sizeof(int));
    g->prev = (int *)calloc(nvertices + 1, sizeof(int));
    return g;
}

void graph_clear(struct graph *g)
{
    g->m = (int **)malloc(g->nvertices * sizeof(int *));
    for (int i = 0; i < g->nvertices; i++) {
    	g->m[i] = (int *)calloc(g->nvertices, sizeof(int));
  }
}

void graph_free(struct graph *g)
{
    free(g->m);
    free(g->visited);
    free(g->D);
    free(g->H);
    free(g->prev);
    free(g);
}

void graph_set_edge(struct graph *g, int i, int j, int w)
{
    g->m[i][j] = g->m[j][i] = w;
    g->m[0][g->nvertices - 1] = g->m[g->nvertices - 1][0] = w;
}

int graph_get_edge(struct graph *g, int i, int j)
{
    return g->m[j][i];
}

void graph_dfs(struct graph *g, int v)
{
    int i;
    g->visited[v - 1] = 1;
    printf("Vertex %d\n", v);
    for (i = 0; i < g->nvertices; i++)
    if (g->m[(v - 1) * g->nvertices + i] > 0 && g->visited[i] == 0)
    graph_dfs(g, i + 1);
}

void graph_bfs(struct graph *g, int v)
{
    int i, j;
    struct queue *q;
    for (i = 0; i < g->nvertices; i++){
    	g->visited[i] = 0;
    }
    q = queue_create(g->nvertices); // Создаём очередь
    g->visited[v - 1] = 1; // Обрабатываем стартовую вершину
    printf("Vertex %d\n", v);
    queue_enqueue(q, v - 1);
    while (queue_size(q) > 0) {
	i = queue_dequeue(q);
	for (j = 0; j < g->nvertices; j++) {
	    if (g->m[i * g->nvertices + j] > 0 && g->visited[j] == 0) {
	        queue_enqueue(q, j);
		g->visited[j] = 1;
		printf("Vertex %d\n", j + 1);
	    }
	}
    }
    queue_free(q);
}

void Dijekstra(struct graph *graph, int src) {
  struct heap *Q = heap_create(20 > 100*100? 20 : 100*100);
  graph->H[src] = src;
  graph->D[src] = 0;
  graph->prev[src] = -1;
  heap_insert(Q, graph->D[src], src);
  for (int i = 1; i < graph->nvertices + 1; i++) {
    if (i != src) {
      graph->H[i] = 0;
      graph->D[i] = INT_MAX;
      graph->prev[i] = -1;
      heap_insert(Q, graph->D[i], i);
    }
  }
  for (int i = 1; i < graph->nvertices + 1; i++) {
    // for (int ii = 1; ii <= Q->nnodes; ii++) {
    // printf("{%d, %d} ", h->nodes[ii].key, h->nodes[ii].value);
    //}
    struct heapnode v = heap_extract_min(Q);
    // printf(" -> {%d, %d}", v.key, v.value);
    // printf("\n");
    int vertex = v.value;
    graph->H[vertex] = vertex;

    for (int j = 1; j < graph->nvertices + 1; j++) {
      if (graph->m[vertex - 1][j - 1] && !graph->H[j]) {
        if (graph->D[vertex] + graph->m[vertex - 1][j - 1] < graph->D[j]) {
          graph->D[j] = graph->D[vertex] + graph->m[vertex - 1][j - 1];
          heap_decrease_key(Q, j, graph->D[j]);
          graph->prev[j] = vertex;
        }
      }
    }
  }
}

