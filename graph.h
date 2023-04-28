#pragma once
#include "minheap.h"

struct graph 
{
    int nvertices; 
    int **m; 
    int *visited;
};

struct graph *graph_create(int nvertices);
void graph_clear(struct graph *g);
void graph_free(struct graph *g);
void graph_set_edge(struct graph *g, int i, int j, int w);
void graph_dfs(struct graph *g, int v);
void graph_bfs(struct graph *g, int v);
void Dijekstra(struct graph *g, struct heap *Q, int src, int size);
void Search_shortest_path(struct heap *Q, struct graph *g, int src, int dst);
