#include "graphs.h"

graph *createGraph(size_t num_nodes) {
    graph *g = (graph *) malloc(sizeof(graph)); 
    if (g == NULL) {
        fprintf(stderr,"Cannot malloc graph\n");
        exit(EXIT_FAILURE);
    }
    g->adjacency_list = (node *) malloc(sizeof(node) * num_nodes);
    if (g->adjacency_list == NULL) {
        fprintf(stderr,"Cannot malloc adjacency list\n");
        exit(EXIT_FAILURE);
    }
    g->num_nodes = num_nodes;
    for (size_t i = 0; i < num_nodes; i++) {
        g->adjacency_list[i].value = i;
        g->adjacency_list[i].next = NULL;
    }
    return g;
}

void freeGraph(graph *g) {
    for (size_t i = 0; i < g->num_nodes; i++) {
        node *n = g->adjacency_list[i].next;
        node *tmp; 
        while (n != NULL) {
            tmp = n;
            n = n->next;
            free(tmp);
        } 
    }
    free(g->adjacency_list);
    free(g);
    printf("Freed the graph\n");
}

void printGraph(graph *g) {
    for (size_t i = 0; i < g->num_nodes; i++) {
        node *n = &g->adjacency_list[i];
        while (n != NULL) {
            printf("%i -> ", n->value);
            n = n->next;
        }
        printf("\n");
    }
}

void addEdge(graph *g, int src, int dst) {
    node *new_src_node = (node *) malloc(sizeof(node));
    new_src_node->next = NULL;
    new_src_node->value = src;
    node *new_dst_node = (node *) malloc(sizeof(node));
    new_dst_node->next = NULL;
    new_dst_node->value = dst;
    node *src_node = &g->adjacency_list[src];
    while (src_node->next != NULL) src_node = src_node->next;
    src_node->next = new_dst_node;

    node *dst_node = &g->adjacency_list[dst];
    while(dst_node->next != NULL) dst_node = dst_node->next;
    dst_node->next = new_src_node;
}

void removeEdge(graph *g, int src, int dst) {
    node *src_node; 
    node *dst_node;
    for (src_node = &g->adjacency_list[src]; src_node->next->value != dst; src_node = src_node->next);
    for (dst_node = &g->adjacency_list[dst]; dst_node->next->value != src; dst_node = dst_node->next);
    node *free_src_node = src_node->next;
    src_node->next = src_node->next->next;
    free(free_src_node);

    node *free_dst_node = dst_node->next;
    dst_node->next = dst_node->next->next;
    free(free_dst_node);
}