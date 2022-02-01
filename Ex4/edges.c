#include "edges.h"

pedge new_edge(int weight, pnode endpoint){
    //Allocate space for new edge
    pedge edge = (pedge) malloc(sizeof(edge_t));

    if (edge == NULL){
        fprintf(stderr, "Error, can´t allocate memory for new edge");
        return NULL;
    }

    //Set weight and endpoint
    edge->weight   = weight;
    edge->endpoint = endpoint;
    //Return new edge
    return edge;
}

int delete_edge(pedge edge){
    if (edge == NULL){
        fprintf(stderr, "%s", "Error, can´t delete null edge\n");
        return 1;
    }
    //Deallocate memory
    free(edge);
    return 0;
}
