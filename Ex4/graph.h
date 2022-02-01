#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include "nodes.h"
#include "edges.h"

typedef struct graph_
{
    pnode *nodes;   //Array of nodes
    int num_nodes;
} graph_t, *pgraph;

extern int djikstra(pgraph graph, int origin_node, int dest_node);
extern int tsp(pgraph graph, int origin_node, int nodes[], int num_tsp_nodes);

pgraph build_graph_cmd(pgraph graph, int num_nodes);
int insert_edge(pgraph graph, int num_node, int node_dest, int weight);
void insert_node_cmd(pgraph graph, int num_node);
void delete_node_cmd(pgraph graph, int num_node);
void printGraph_cmd(pgraph graph); //for self debug
void deleteGraph_cmd(pgraph graph);
void shortsPath_cmd(pgraph graph, int origin_node, int dest_node);
void TSP_cmd(pgraph graph, int origin_node, int nodes[], int num_tsp_nodes);

#endif //GRAPH_H
