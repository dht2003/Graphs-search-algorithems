#include "bfs.h"

bfSearcher *initBfSearcher(graph *g) {
    bfSearcher *searcher = (bfSearcher *) malloc(sizeof(bfSearcher));
    searcher->q = createQueue();
    searcher->g = g;
    searcher->travelled = createStack();
    if (searcher->travelled == NULL) {
        fprintf(stderr, "Cannot allocate travelled array for bf searcher\n");
        exit(EXIT_FAILURE);
    }
    return searcher;
}

void freeBfSearcher(bfSearcher *searcher) {
    printf("Freeing BfSearcher\n");
    freeQueue(searcher->q);
    freeStack(searcher->travelled);
    free(searcher);
}

void bfs_search(bfSearcher *searcher, int src, int target) {
    searcher->src = src;
    searcher->target = target;
    node *n = &searcher->g->adjacency_list[src];
    push(searcher->travelled, n->value);
    while (true)
    {
        while (n != NULL) {
            if (!isInStack(searcher->travelled, n->value) && !isInQueue(searcher->q,n->value))  
                enqueue(searcher->q, n->value);
            n = n->next;
        }
        if (q_isEmpty(searcher->q)) {
            fprintf(stderr ,"Cannot find path to target\n");
            exit(EXIT_FAILURE);
        }
        int travel = dequeue(searcher->q);
        push(searcher->travelled, travel);
        if (travel == target) {
            printf("Found path to target\n");
            return;
        }
        n = &searcher->g->adjacency_list[travel];
    }
    
}

void printBfsTravelled(bfSearcher *searcher) {
    for (int i = 0; i <= searcher->travelled->top; i++) 
        printf("%i->", searcher->travelled->arr[i]);
    printf("\n");
}