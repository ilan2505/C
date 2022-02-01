#define  _POSIX_C_SOURCE 200809L
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 1024

void display_menu(void);
int action_menu(pgraph graph, char get_char);
int compare_command(char *cmd, const char *UPPER_CASE, const char *LOWER_CASE);
int is_new_command(char *token);

int main(void){
    pgraph graph = NULL;
    char *buffer;
    char *cmd;
    size_t bufsize = BUFF_SIZE;

    //Allocate memory for buffer
    buffer = (char*) malloc(BUFF_SIZE * sizeof(char));
    //Get line from console
    getline(&buffer, &bufsize, stdin);
    //Tokenize string
    cmd = strtok(buffer, " \n");
    while(cmd){
        int new_command = 0;
        //Build graph
        if (compare_command(cmd, "A", "a")){
            int num_nodes;
            char *tmp;
            //Get number of nodes
            tmp = strtok(NULL, " \n");
            if (tmp == NULL){
                break;
            }
            num_nodes = atoi(tmp);
            graph = build_graph_cmd(graph, num_nodes);
        } else if (compare_command(cmd, "N", "n")){         //New edge
            int origin_node;
            int dest_node;
            int weight;
            char *tmp;
            //Get origin node
            tmp = strtok(NULL, " \n");
            if (tmp == NULL){
                break;
            }
            if (is_new_command(tmp)){
                new_command = 1;
                cmd = tmp;
            } else {
                origin_node = atoi(tmp);        //Get origin node
                while(!new_command){
                    tmp = strtok(NULL, " \n");
                    if (tmp == NULL){
                        break;
                    }
                    if (is_new_command(tmp)){
                        new_command = 1;
                        cmd = tmp;
                        break;
                    }
                    dest_node = atoi(tmp);      //get dest_node
                    tmp = strtok(NULL, " \n");
                    if (tmp == NULL){
                        break;
                    }
                    if (is_new_command(tmp)){
                        new_command = 1,
                        cmd = tmp;
                        break;
                    }
                    weight = atoi(tmp);     //Get weight
                    //Add new edge
                    insert_edge(graph, origin_node, dest_node, weight);
                }
            }
        } else if (compare_command(cmd, "B", "b")){     //Create new vertex
            int new_node;
            int dest_node;
            int weight;
            char *tmp;
            tmp = strtok(NULL, " \n");
            if (tmp == NULL){
                break;
            }
            if (is_new_command(tmp)){
                new_command = 1;
                cmd = tmp;
            } else {
                new_node = atoi(tmp);   //Get number of new node
                //Add new node
                insert_node_cmd(graph, new_node);
                while(!new_command){
                    tmp = strtok(NULL, " \n");
                    if (tmp == NULL){
                        break;
                    }
                    if (is_new_command(tmp)){
                        new_command = 1,
                        cmd = tmp;
                        break;
                    }
                    dest_node = atoi(tmp);  //Get dest_node
                    tmp = strtok(NULL, " \n");
                    if (tmp == NULL){
                        break;
                    }
                    if (is_new_command(tmp)){
                        new_command = 1;
                        cmd = tmp;
                        break;
                    }
                    weight = atoi(tmp); //Get weight
                    //Add edge
                    insert_edge(graph, new_node, dest_node, weight);
                }
            }
        } else if (compare_command(cmd, "D", "d")){ //Delete node
            int node_num;
            char *tmp;
            tmp = strtok(NULL, " \n");
            if (tmp == NULL){
                break;
            }
            node_num = atoi(tmp); //Get node to delete
            delete_node_cmd(graph, node_num);
        } else if (compare_command(cmd, "S", "s")){ //shortest path
            int origin_node;
            int dest_node;
            char *tmp;
            tmp = strtok(NULL, " \n");
            if (tmp == NULL){
                break;
            }
            origin_node = atoi(tmp);
            tmp = strtok(NULL, " ");
            if (tmp == NULL){
                break;
            }
            dest_node = atoi(tmp);
            shortsPath_cmd(graph, origin_node, dest_node);
        } else if (compare_command(cmd, "T", "t")){     //TSP problem
            int nodes[10];
            int origin_node;
            char *tmp;
            int num_tsp_nodes = 0;
            tmp = strtok(NULL, " \n");
            if (tmp == NULL){
                break;
            }
            origin_node = atoi(tmp);
            tmp = strtok(NULL, " \n");
            if (tmp == NULL){
                break;
            }
            while (!is_new_command(tmp)){
                nodes[num_tsp_nodes++] = atoi(tmp);
                tmp = strtok(NULL, " \n");
                if (tmp == NULL){
                    break;
                }
            }
            TSP_cmd(graph, origin_node, nodes, num_tsp_nodes);
            cmd = tmp;
            new_command = 1;
        } else if (compare_command(cmd, "P", "p")){
            printGraph_cmd(graph);
        }
        if (!new_command){  //Command got in new Edge
            cmd = strtok(NULL, " \n");   //Get next command
        }
        new_command = 0;
    }
    free(buffer);
    deleteGraph_cmd(graph);

};

int compare_command(char *cmd, const char *UPPER_CASE, const char *LOWER_CASE){
    if (!(strcmp(cmd, UPPER_CASE)) || !(strcmp(cmd, LOWER_CASE))){
        return 1;
    }else{
        return 0;
    }
}

int is_new_command(char *token){
    if (compare_command(token, "A", "a")){
        return 1;
    } else if (compare_command(token, "N", "n")){
        return 1;
    } else if (compare_command(token, "B", "b")){
        return 1;
    } else if (compare_command(token, "D", "d")){
        return 1;
    } else if (compare_command(token, "S", "s")){
        return 1;
    } else if (compare_command(token, "T", "t")){
        return 1;
    } else if (compare_command(token, "P", "p")){
        return 1;
    }
    else {
        return 0;
    }
}

void display_menu(void){
    //Display menu
    printf("A: generate new graph\n");
    printf("B: Create new vertex\n");
    printf("D: Delete vertex\n");
    printf("S: Print shortest path between 2 vertexes\n");
    printf("T: Traveling salesman problem\n");
    printf("Q: Exit program\n");
   return;
}
