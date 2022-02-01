#ifndef NODES_H
#define NODES_H

#include <stdlib.h>
#include <stdio.h>
#include "edges.h"

typedef struct GRAPH_NODE_ {
    int node_num;
    int num_edges;
    pedge *edges;               //Array of pedges
} node_t, *pnode;

//Create new node
pnode new_node(int node_num);
//Delete node
int delete_node(pnode node);
//Add edge
int add_edge(pnode node, pedge edge);
//Delete edge with endpoint==node_num
int remove_edge(pnode node, int node_num);
//Remove all edges
void delete_edges(pnode node);

#endif //NODES_H