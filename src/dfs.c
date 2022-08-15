#include "dfs.h"

dfSearcher *initDfSearcher(graph *g) {
    dfSearcher *searcher = (dfSearcher *) malloc(sizeof(dfSearcher));
    searcher->s = createStack();
    searcher->g = g;
    searcher->travelled = createStack();
    if (searcher->travelled == NULL) {
        fprintf(stderr, "Cannot allocate travelled array for df searcher\n");
        exit(EXIT_FAILURE);
    }
    return searcher;
}

void freeDfSearcher(dfSearcher *searcher) {
    printf("Freeing DfSearcher\n");
    freeStack(searcher->s);
    freeStack(searcher->travelled);
    free(searcher);
}

void dfs_search(dfSearcher *searcher, int src, int target) {
    searcher->src = src;
    searcher->target = target;
    node *n = &searcher->g->adjacency_list[src];
    push(searcher->travelled, n->value);
    while (true)
    {
        while (n != NULL) {
            if (!isInStack(searcher->travelled, n->value) && !isInStack(searcher->s,n->value))  
                push(searcher->s, n->value);
            n = n->next;
        }
        if (s_isEmpty(searcher->s)) {
            fprintf(stderr ,"Cannot find path to target\n");
            exit(EXIT_FAILURE);
        }
        int travel = pop(searcher->s);
        push(searcher->travelled, travel);
        if (travel == target) {
            printf("Found path to target\n");
            return;
        }
        n = &searcher->g->adjacency_list[travel];
    }
    
}

void printDfsTravelled(dfSearcher *searcher) {
    for (int i = 0; i <= searcher->travelled->top; i++) 
        printf("%i->", searcher->travelled->arr[i]);
    printf("\n");
}