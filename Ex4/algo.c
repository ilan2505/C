#include <limits.h>

#include "algo.h"

int djikstra(pgraph graph, int origin_node, int dest_node){
    int distance  = -1;
    int num_nodes = graph->num_nodes;
    int visited_nodes[num_nodes];
    int weight_nodes[num_nodes];
    pnode actual_node;
    int num_next_node;
    if (graph == NULL){
        fprintf(stderr, "Error, graph is NULL");
        return -1;
    }
    if (graph->nodes[origin_node] == NULL){
        fprintf(stderr, "Error, origin node is NULL, %0d", origin_node);
        return -1;
    }
    //Set all visited nodes to false
    //set all weight to nodes to infinite (-1)
    for (int i=0; i<num_nodes; i++){
        visited_nodes[i] = 0;
        weight_nodes[i] = -1;
    }
    //Set weight origin node = 0;
    weight_nodes[origin_node] = 0;
    //Update weights for first node
    actual_node = graph->nodes[origin_node];
    djikstra_update_weights(actual_node, visited_nodes, weight_nodes);
    //Update visited nodes
    visited_nodes[origin_node] = 1;
    num_next_node = djikstra_next_visit(graph, visited_nodes, weight_nodes);
    while(num_next_node >= 0){
        //dest node reached
        if (num_next_node == dest_node){
            distance = weight_nodes[num_next_node];
            break;
        }
        //Update weights
        actual_node = graph->nodes[num_next_node];
        djikstra_update_weights(actual_node, visited_nodes, weight_nodes);
        visited_nodes[num_next_node] = 1;
        num_next_node = djikstra_next_visit(graph, visited_nodes, weight_nodes);
    }
    return distance;
    
}

void print_array(int arr[], int size){
    for (int i=0; i<size; i++){
        printf("arr[%0d]:%0d, ", i, arr[i]);
    }
}

int djikstra_next_visit(pgraph graph, int visited_nodes[], int weight_nodes[]){
    pnode node;
    int num_next_node = -1;
    int weight_next_node = -1;
    for (int i=0; i<graph->num_nodes; i++){
        node = graph->nodes[i];
        if (node != NULL){
            if (!visited_nodes[node->node_num]){
                if ( weight_nodes[node->node_num] < (unsigned int)weight_next_node) {
                    weight_next_node = weight_nodes[node->node_num];
                    num_next_node = node->node_num;
                }
            }
        }
    }

    return num_next_node;
}

void djikstra_update_weights(pnode node, int visited_nodes[], int weight_nodes[]){
    int num_edges = node->num_edges;
    for (int i=0; i<num_edges; i++){
        pedge edge = node->edges[i];
        pnode next_node = edge->endpoint;
        int next_weight;
        if (!visited_nodes[next_node->node_num]){
            next_weight = weight_nodes[node->node_num] + edge->weight;
            if (next_weight < (unsigned int)weight_nodes[next_node->node_num]){
                weight_nodes[next_node->node_num] = next_weight;
            }
        }
    }
}

int tsp(pgraph graph, int origin_node, int nodes[], int num_tsp_nodes){
    int distance = INT_MAX;
    if (graph == NULL){
        fprintf(stderr, "Error, graph is null");
        return -1;
    }
    int best_distance = tsp_permutation(graph, origin_node, nodes, 0, num_tsp_nodes-1, distance);
    if (best_distance == INT_MAX) {
        return (-1);
    }
    return best_distance;

}

int tsp_permutation(pgraph graph, int origin_node, int *arr, int start, int end, int min_distance){
    int distance = min_distance;
    if (start == end){
        return calculate_tsp_min_distance(graph, origin_node, arr, end+1, distance);
    }
    for (int i=start; i<=end; i++){
        swap_array((arr+i), (arr+start));
        distance = tsp_permutation(graph, origin_node, arr, start+1, end, distance);
        swap_array((arr+i), (arr+start));
    }
    return distance;
}

int calculate_tsp_min_distance(pgraph graph, int origin_node, int arr[], int size_arr, int min_distance){
    int distance = 0;
    int tmp_distance;
    for (int i=1; i<size_arr; i++){
        tmp_distance = djikstra(graph, arr[i-1], arr[i-0]);
        if (tmp_distance == -1){
            distance = INT_MAX;
            break;
        } else{
            distance += tmp_distance;
        }
    }
    if (distance < (unsigned int) min_distance){
        return distance;
    } else{
        return min_distance;
    }
}

void swap_array(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
