#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

void Dijkstra(Graph * g,int stn)
{
    statue * D = (statue *)malloc(sizeof(statue) * g->node_nowsite);
    int * T = (int *)malloc(sizeof(int) * g->node_nowsite);
    for(int i = 0;i < g->node_nowsite;i++)
    {
        T[i] = g->edge[stn - 1][i];
        D[i] = false;
    }
    int p = stn - 1;
    while(p != -1)
    {
        int p_last = p;
        int min = -1;
        //find the closest node
        for(int i = 0;i < g->node_nowsite;i++)
        {
            if(i == p_last || D[i] == true)
                continue;
            if(min == -1)
            {
                min = g->edge[p_last][i];
                p = i;
                continue;
            }
            if(g->edge[p_last][i] < min)
            {
                p = i;
                min = g->edge[p_last][i];
            }
        }
        //don't have , break
        if(p == p_last)
        {
            p = -1;
            continue;
        }
        //renew the distance
        for(int i = 0;i < g->node_nowsite;i++)
        {
            if(i == p_last || D[i] == true || i == stn - 1)
                continue;
            if(T[i] > g->edge[p_last][i] + T[p_last])
            {
                T[i] =  g->edge[p_last][i] + T[p_last];
            }
        }
        D[p] = true;
    }

    for(int i = 0;i < g->node_nowsite;i++)
    {
        printf("( %c , %c , %d ) \n",g->node[stn - 1].data,g->node[i].data,T[i]);
    }

}
int main() {
    Graph g;
    CreateGraph(&g);
    Dijkstra(&g,1);

    printf("Hello, World!\n");
    return 0;
}