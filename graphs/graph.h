#include <stdio.h>
#include <stdlib.h>

struct edge_list {
    int vertex;
    struct edge_list* next;
};

typedef struct edge_list edge_list;

void print_graph(edge_list** graph, int size);
edge_list* init_graph(int size);
void add_edge(edge_list** graph, int v1, int v2);