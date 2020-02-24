
//
// Created by 97927 on 2019/12/4.
//

#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

void Prim(GraphPoint g,int stn)
{
    int length = g->node_nowsite;
    statue * D = (statue *)malloc(sizeof(statue) * length);
    int ** T = (int **)malloc(sizeof(int*) * length);
    for(int i = 0;i < length;i++)
    {
        T[i] = (int*)malloc(sizeof(int) * length);
        for(int j = 0;j < length;j++)
            T[i][j] = 0;
        D[i] = false;
    }
    int cost = 0;
    D[stn - 1] = true;
    int court = 0;
    while(1)
    {
        int min_1;
        int min_2;
        int min = -1;
        //find the closest node
        for(int i = 0;i < length;i++)
        {
            if(D[i] != 0)
                continue;
            for(int j = 0;j < length;j++)
            {
                if(i == j || D[i] == true)
                    continue;
                if(min == -1)
                {
                    min = g->edge[i][j];
                    min_1 = i;
                    min_2 = j;
                    continue;
                }
                if(g->edge[i][j] < min)
                {
                    min_1 = i;
                    min_2 = j;
                    min = g->edge[i][j];
                }
            }

        }
        //don't have , break
        if(min == -1)
        {
            break;
        }
        //renew the distance
        cost += g->edge[min_1][min_2];
        court ++;
        T[min_1][min_2] = 1;
        T[min_2][min_1] = 1;
        D[min_1] = true;
        D[min_2] = true;
    }
    printf("\n%d\n",cost);
    printf("建立以下%d条水渠：",court);
    for(int i = 0; i < length;i++)
    {
        for(int j = 0;j < length;j++)
        {
            if(T[i][j] == 1)
            {
                printf("麦田%d与麦田%d,",i + 1,j + 1);
                T[i][j] = 0;
                T[j][i] = 0;
            }
        }
    }
}
int main()
{
    Graph g;
    CreateGraph(&g);
    Prim(&g,1);

    return 0;
}