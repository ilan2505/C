#include "nodes.h"

pnode new_node(int node_num){
    //allocate memory
    pnode node = (pnode) malloc(sizeof(node_t));
    
    if (node == NULL){
        fprintf(stderr, "Error, can´t allocate memory for new node");
        return NULL;
    } 
    
    //Edges are no allocated at this point, use add_edge to create new edge
    node->node_num  = node_num;
    node->edges     = NULL;
    node->num_edges = 0;
    //Return new node
    return node;
}

int delete_node(pnode node){
    if (node == NULL){
        fprintf( stderr, "%s", "Error, cant delete null node\n");
        return 1;
    }
    //Delete edges
    if (node->num_edges > 0){
        delete_edges(node);
    }
    //Delete node
    free(node);
    return 0;
}

int add_edge(pnode node, pedge edge){
    int num_edges = node->num_edges;
    if (node == NULL){
        fprintf(stderr, "%s", "Error, can´t add edge to null node\n");
        return 1;
    }
    if (edge == NULL){
        fprintf(stderr, "%s", "Error, can´t add null edge to node\n");
        return 1;
    }
    //First edge
    if (num_edges == 0){
        //Allocate memory for new edge
        node->edges = (pedge*) malloc(sizeof(pedge));
    } else {
        //reallocate memory for new edge
        node->edges = (pedge*) realloc(node->edges, ((num_edges+1) * sizeof(pedge)));
    }
    //set new edge
    node->edges[node->num_edges] = edge;
    node->num_edges++;
    return 0;
}

void delete_edges(pnode node){
    for(int i=0; i<node->num_edges; i++){
        delete_edge(node->edges[i]);
    }
    free (node->edges);
    node->num_edges = 0;
}

int remove_edge(pnode node, int node_num){
    pedge tmp;
    int found = 0;
    if (node == NULL){
        fprintf(stderr, "Error, node is NULL");
        return 1;
    }
    for (int i = 0; i<node->num_edges; i++){
        if (node->edges[i]->endpoint->node_num == node_num){
            tmp = node->edges[i];
            node->edges[i] = node->edges[node->num_edges-1];
            node->edges[node->num_edges-1] = tmp;
            found = 1;
            break;
        }
    }
    if (!found){
        fprintf(stderr, "Error, can´t delete edge, edge not found: %0d", node_num);
        return 1;
    }
    node->num_edges--;
    delete_edge(node->edges[node->num_edges]);
    node->edges = (pedge*) realloc(node->edges, (node->num_edges * sizeof(pedge)));
    return 0;
}
