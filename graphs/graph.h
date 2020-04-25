#include <stdio.h>

typedef struct {
    int vertices;
    int edges;
    
    struct vertex {
        int size;
        int cap;
        int list[];
    } * adj_list[];
    
} graph;