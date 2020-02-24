#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

int main() {

    Graph g;
    CreateGraph(&g);
    DFSTraverse(g);
    printf("\n");
    /*printf("%d\n",LocateVex(g,1));
    printf("%d\n",GetVex(g,2));
    PutVex(&g,3,10);
    DFSTraverse(g);*/
    /*InsertArc(&g,3,4);
    DFSTraverse(g);
    printf("\n");
    InsertVex(&g);
    DFSTraverse(g);
    printf("\n");*/
    BFSTraverse(g);

    DestroyGraph(&g);

    return 0;
}