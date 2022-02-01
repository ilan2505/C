#ifndef EDGES_H
#define EDGES_H 

#include <stdlib.h>
#include <stdio.h>

typedef struct GRAPH_NODE_ *pnode;

typedef struct edge_ {
    int weight;
    pnode endpoint;
} edge_t, *pedge;

//Create new edge
pedge new_edge(int weight, pnode endpoint);
//Delete edge
int delete_edge(pedge edge);

#endif //EDGES_H