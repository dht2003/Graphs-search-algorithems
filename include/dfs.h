#ifndef DFS_H
#define DFS_H

#include "graphs.h"
#include "stack.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct DFSearcher {
    stack *s;
    graph *g;
    stack* travelled;
    int src;
    int target;
} dfSearcher;

dfSearcher *initDfSearcher(graph *g);

void dfs_search(dfSearcher *searcher,int src, int target);

void printDfsTravelled(dfSearcher *searcher);

void freeDfSearcher(dfSearcher *searcher);


#endif 