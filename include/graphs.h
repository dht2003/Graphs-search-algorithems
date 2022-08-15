#ifndef GRAPH_H
#define GRAPH_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "common.h"




typedef struct graph_struct {
    size_t num_nodes;
    node *adjacency_list; 
} graph;


graph *createGraph(size_t num_nodes);

void addEdge(graph *g,int src, int dst);

void removeEdge(graph *g, int src, int dst);

void freeGraph(graph *g);

void printGraph(graph *g);

#endif