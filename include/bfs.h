#ifndef BFS_H
#define BFS_H

#include "graphs.h"
#include "queue.h"
#include "stack.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct BFSearcher {
    queue *q;
    graph *g;
    stack* travelled;
    int src;
    int target;
} bfSearcher;

bfSearcher *initBfSearcher(graph *g);

void bfs_search(bfSearcher *searcher,int src, int target);

void printBfsTravelled(bfSearcher *searcher);

void freeBfSearcher(bfSearcher *searcher);


#endif 