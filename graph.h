#pragma once

struct graph 
{
    int nvertices; 
    int **m; 
    int *visited;
    int *D;        /*/   кратчайшие пути     /*/
    int *H;
    int *prev; 
};

struct graph *graph_create(int nvertices);
void graph_clear(struct graph *g);
void graph_free(struct graph *g);
void graph_set_edge(struct graph *g, int i, int j, int w);
void graph_dfs(struct graph *g, int v);
void graph_bfs(struct graph *g, int v);
void Dijekstra(struct graph *graph, int src);
