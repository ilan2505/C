#include "graph.h"

pgraph build_graph_cmd(pgraph graph, int num_nodes){
    //Delete previous graph if exists
    if (graph != NULL){
        deleteGraph_cmd(graph);
    }
    //Allocate memory for graph
    graph = (pgraph) malloc(sizeof(graph_t));
    //Allocate memory for array of nodes
    graph->nodes = (pnode*) malloc(num_nodes * sizeof(pnode));
    if (graph->nodes == NULL){
        fprintf(stderr, "Error, Can´t allocate memorie for graph");
        return NULL;
    }
    for (int i=0; i<num_nodes; i++){
        graph->nodes[i] = new_node(i);
    }
    graph->num_nodes = num_nodes;
    return graph;
}

int insert_edge(pgraph graph, int num_node, int node_dest, int weight){
    pedge edge;
    if (graph == NULL){
        fprintf(stderr, "%s", "Error, cant add edge to NULL graph\n");
        return 1;
    }
    if ((num_node > graph->num_nodes) || (num_node < 0)) {
        fprintf(stderr, "Error, invalid origin node: %0d", num_node);
        return 1;
    }
    if ((node_dest > graph->num_nodes) || (node_dest < 0)){
        fprintf(stderr, "Error, Invalid node_dest: %0d", node_dest);
        return 1;
    }
    if (graph->nodes[num_node] == NULL){
        fprintf(stderr, "Error, Origin node is null: %0d", num_node);
        return 1;
    }
    if (graph->nodes[node_dest] == NULL){
        fprintf(stderr, "Error, node_dest is null: %0d", node_dest);
        return 1;    
    }
    //Create edge
    edge = new_edge(weight, graph->nodes[node_dest]);
    //Add edge to node
    add_edge(graph->nodes[num_node], edge);
    return 0;
}

void insert_node_cmd(pgraph graph, int num_node){
    if (num_node >= graph->num_nodes){  //New node
        graph->nodes = (pnode*) realloc(graph->nodes, ((num_node+1) * sizeof(pnode)));
        //Create new nodes
        for (int i=graph->num_nodes; i<=num_node; i++){
            graph->nodes[i] = new_node(i);
        }
        graph->num_nodes = num_node+1;
    }else { //Delete previous node edges
        if (graph->nodes[num_node] != NULL) {
            delete_edges(graph->nodes[num_node]);
        } else {
            graph->nodes[num_node] = new_node(num_node);
        }
    }

}

void delete_node_cmd(pgraph graph, int num_node){
    if ((num_node >= graph->num_nodes) || (num_node < 0)){
        fprintf(stderr, "Error, Invalid node to delete: %0d", num_node);
        return;
    }
    if (graph->nodes[num_node] == NULL){
        fprintf(stderr, "Error, can´t delete null node: %0d", num_node);
    }
    //Remove edges that go to this node
    for (int i=0; i<graph->num_nodes; i++){
        if (graph->nodes[i] != NULL){
            for (int j=0; j<graph->nodes[i]->num_edges; j++){
                //TODO: remove edge using node function
                if (graph->nodes[i]->edges[j]->endpoint->node_num == num_node){
                    remove_edge(graph->nodes[i], num_node);
                }
            }
        }
    }
    delete_node(graph->nodes[num_node]);
    graph->nodes[num_node] = NULL;
}

void printGraph_cmd(pgraph graph){
    int num_endpoint;
    int weight;
    for (int i=0; i<graph->num_nodes; i++){
        if (graph->nodes[i] != NULL){
            printf("Node: %0d ", i);
            printf("Edges: %0d: ", graph->nodes[i]->num_edges);
            for (int j=0; j<graph->nodes[i]->num_edges; j++){
                if (graph->nodes[i]->edges[j] != NULL){
                    num_endpoint = graph->nodes[i]->edges[j]->endpoint->node_num;
                    weight = graph->nodes[i]->edges[j]->weight;
                    printf(" %dW%d ", num_endpoint, weight);
                }
            }
            printf("\n");
        }
    }

}

void deleteGraph_cmd(pgraph graph){
    if (graph == NULL){
        printf("Warning Can´t delete NULL graph\n");
        return;
    }
    //Remove nodes
    if (graph->num_nodes > 0){
        for(int i=0; i<graph->num_nodes; i++ ){
            if (graph->nodes[i] != NULL){
                delete_node(graph->nodes[i]);
            }
        }
    }
    free(graph->nodes);
    //Delete graph
    free(graph);
    return;
}

void shortsPath_cmd(pgraph graph, int origin_node, int dest_node){
    int min_distance;
    min_distance = djikstra(graph, origin_node, dest_node);
    printf("Dijsktra shortest path: %d \n", min_distance);
}

void TSP_cmd(pgraph graph, int origin_node, int nodes[], int num_tsp_nodes){
    int min_distance;
    min_distance = tsp(graph, origin_node, nodes, num_tsp_nodes);
    printf("TSP shortest path: %d \n", min_distance);
}
