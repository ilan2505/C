#ifndef ALGO_H 
#define ALGO_H 

#include "nodes.h"
#include "edges.h"
#include "graph.h"

int djikstra(pgraph graph, int origin_node, int dest_node);
int djikstra_next_visit(pgraph node, int visited_nodes[], int weight_nodes[]);
void djikstra_update_weights(pnode node, int visited_nodes[], int weight_nodes[]);
int tsp(pgraph graph, int origin_node, int nodes[], int num_tsp_nodes);
void print_array(int arr[], int size);
void swap_array(int *a, int *b);
int tsp_permutation(pgraph graph, int origin_node, int *arr, int start, int end, int min_distance);
int calculate_tsp_min_distance(pgraph graph, int origin_node, int arr[], int size_arr, int min_distance);

#endif //ALGO_H