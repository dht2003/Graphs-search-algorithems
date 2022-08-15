#include <stdio.h>
#include "graphs.h"
#include "bfs.h"
#include "dfs.h"

int main(int argc, char *argv[]) {
    graph * g = createGraph(5);
    bfSearcher *bf_searcher  = initBfSearcher(g);
    dfSearcher *df_searcher = initDfSearcher(g);
    addEdge(g, 0, 1);
    addEdge(g, 0, 4);
    addEdge(g, 1, 2);
    addEdge(g, 1, 3);
    addEdge(g, 1, 4);
    addEdge(g, 2, 3);
    addEdge(g, 3, 4);
    printGraph(g);
    printf("\n");
    bfs_search(bf_searcher,0,2);
    printBfsTravelled(bf_searcher);
    dfs_search(df_searcher,0,2);
    printDfsTravelled(df_searcher);
    //print_graph(g);
    freeBfSearcher(bf_searcher);
    freeDfSearcher(df_searcher);
    freeGraph(g);
    return 0;
}