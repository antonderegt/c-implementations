#include "graph.h"

void print_graph(edge_list** graph, int size) {
    for(int i = 0; i < size; i++) {
        edge_list* current = graph[i];
        while(current != NULL) {
            printf("%d->", current->vertex);
            current = current->next;
        }
        printf("\n");
    }
    printf("\n");
}

edge_list* init_graph(int size) {
    edge_list* graph = malloc(size * sizeof(edge_list));
    for(int i = 0; i < size; i++) {
        edge_list* vertex = malloc(sizeof(edge_list));
        vertex->next = NULL;
    }
    return graph;
}

void add_edge(edge_list** graph, int v1, int v2) {
    graph[v1]->vertex = v2;
    graph[v1]->next = NULL;
}