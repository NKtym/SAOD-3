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
    free(g);
}

void graph_set_edge(struct graph *g, int i, int j, int w)
{
    g->m[i][j] = g->m[j][i] = w;
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

void Dijekstra(struct graph *g, struct heap *Q, int src, int size) {
  Q->H[src] = src;
  Q->D[src] = 0;
  Q->prev[src] = -1;
  heap_insert(Q, Q->D[src], src);
  for (int i = 1; i < g->nvertices + 1; i++) {
    if (i != src) {
      Q->H[i] = 0;
      Q->D[i] = INT_MAX;
      Q->prev[i] = -1;
      heap_insert(Q, Q->D[i], i);
    }
  }
  for (int i = 1; i < g->nvertices + 1; i++) {
    struct heapnode v = heap_extract_min(Q);
    int vertex = v.value;
    Q->H[vertex] = vertex;
    for (int j = 1; j < g->nvertices + 1; j++) {
      if (g->m[vertex - 1][j - 1] && !Q->H[j]) {
        if (Q->D[vertex] + g->m[vertex - 1][j - 1] < Q->D[j]) {
          Q->D[j] = Q->D[vertex] + g->m[vertex - 1][j - 1];
          heap_decrease_key(Q, j, Q->D[j]);
          Q->prev[j] = vertex;
        }
      }
    }
  }
}

