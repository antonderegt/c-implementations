#include "graph.h"

int main() {
    int size = 10;
    edge_list* graph = init_graph(size);

    add_edge(&graph, 0, 1);
    add_edge(&graph, 1, 2);

    print_graph(&graph, 10);

    return 0;
}