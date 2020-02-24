//
// Created by HP on 2019/11/16.
//

#include "Graph.h"
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Stack.h"

statue CreateGraph(GraphPoint g)
{
    int Node_num;
    printf("enter the number of nodes : ");
    scanf("%d",&Node_num);
    g->edge = (int **)malloc(sizeof(int *) * Node_num);
    for(int i = 0;i < Node_num;i++)
    {
        g->edge[i] = (int *)malloc(sizeof(int) * Node_num);
        for(int k = 0;k < Node_num;k++)
        {
            g->edge[i][k] = 0;
        }
    }
    g->node = (PointNode)malloc(sizeof(GraphNode) * Node_num);
    g->node_length = Node_num;
    g->node_nowsite = 0;
    for(int i =0;i < Node_num;i++)
    {
        printf("Add node : (p to break)");
        char node_data;
        node_data = getchar();
        while(getchar() == '\n');
        g->node[g->node_nowsite].data = node_data;
        g->node[g->node_nowsite].site = g->node_nowsite + 1;
        g->node_nowsite++;
    }

    printf("\n");
    do{
        printf("Add edge : (p to break)");
        int node1;
        int node2;
        int distance;
        if(!scanf("%d",&node1))
            break;
        if(!scanf("%d",&node2))
            break;
        printf("enter wight :");
        scanf("%d",&distance);
        g->edge[node1 - 1][node2 - 1] = distance;
        g->edge[node2 - 1][node1 - 1] = distance;
    }while(1);

    for(int i = 0;i < Node_num;i++)
    {
        for(int j = 0;j < Node_num;j++)
            {
            if(i == j)
            {
                g->edge[i][j] = MAX_NUMBER;
                printf("%d\t",g->edge[i][j]);
                continue;
            }
            if(g->edge[i][j] == 0)
            {
                g->edge[i][j] = MAX_NUMBER;
            }
            printf("%d ",g->edge[i][j]);
        }
        printf("\n");
    }
    /*while(getchar() == '\n');*/

    return true;
}
statue DestroyGraph(GraphPoint g)
{
    free(g->edge);
    free(g->node);
    g->edge = NULL;
    g->node = NULL;
    g->node_nowsite = 0;
    g->node_length = 0;

    return true;
}
int LocateVex(Graph g,char elem)
{
    int i = 0;
    for(;i < g.node_nowsite;i++)
    {
        if(g.node[i].data == elem)
            break;
    }
    if(g.node[i].data == elem)
        return g.node[i].site;
    return -1;
}
char GetVex(Graph g,int site)
{
    if(site > g.node_nowsite)
        return -1;
    return g.node[site - 1].data;
}
statue PutVex(GraphPoint g,int site,char elem)
{
    if(site > g->node_nowsite)
        return false;
    g->node[site - 1].data = elem;
    return true;
}
PointNode FirstAdjVex(GraphPoint g,int site)
{
    for(int i = 0;i < g->node_nowsite;i++)
    {
        if(i == site - 1)
            continue;
        if(g->edge[site - 1][i] == 1)
            return &g->node[i];
    }

    return NULL;
}
PointNode NextAdjVex(GraphPoint g,int node1,int node2)
{
    for(int i = node2;i < g->node_nowsite;i++)
    {
        if(i == node1 - 1)
            continue;
        if(g->edge[node1 - 1][i] == 1)
            return &g->node[i];
    }

    return NULL;
}
statue InsertVex(GraphPoint g)
{
    char num;
    printf("enter the data : ");
    scanf("%c",&num);
    g->node[g->node_nowsite].data = num;
    g->node[g->node_nowsite].site = g->node_nowsite + 1;
    g->node_nowsite ++;
    if(g->node_nowsite == g->node_length)
    {
        g->node = realloc(g->node,sizeof(PointNode)*(g->node_length + ADD_LONG));
        g->node_length += ADD_LONG;
    }
    return true;
}
statue DeleteVex(GraphPoint g,int site) {
    for (int i = site; site < g->node_nowsite; i++) {
        g->node[site - 1] = g->node[site];
    }
    g->node_nowsite--;
    for (int i = 0; i < g->node_nowsite; i++)
    {
        g->edge[site - 1][i] = MAX_NUMBER;
        g->edge[i][site - 1] = MAX_NUMBER;
    }

    return true;
}
statue InsertArc(GraphPoint g,int node1,int node2)
{
    g->edge[node1 - 1][node2 - 1] = 1;
    g->edge[node2 - 1][node1 - 1] = 1;

    return true;
}
statue DFSTraverse(Graph g)
{
    int * D = (int *)malloc(sizeof(int) * g.node_nowsite);
    for(int i = 0;i < g.node_nowsite;i++)
    {
        D[i] = 1;
    }
    for(int i = 0;i < g.node_nowsite;i++)
    {
        if(D[i] == 0)
            continue;
        printf("%dth : %c\n",g.node[i].site,g.node[i].data);
        D[i] = 0;
        int now_s = i;
        int last_s;
        statue flag = false;
        Stack s;
        InitStack(&s);
        Push(&s,i);
        while(!StackEmpty(s))
        {
            int next_s = -1;
            int k = 0;
            if(flag)
            {
                flag = false;
                k = last_s + 1;
            }
            for(;k < g.node_nowsite;k++)
            {
                if(k == now_s)
                    continue;
                if(g.edge[now_s][k] == 1)
                {
                    if(D[k])
                    {
                        next_s = k;
                        break;
                    }
                    continue;
                }
            }
            if(next_s != -1)
            {
                printf("%dth : %d\n",g.node[k].site,g.node[k].data);
                D[next_s] = 0;
                Push(&s,next_s);
                now_s = next_s;
            }
            else
            {
                last_s = now_s;
                Pop(&s,&now_s);
                flag = true;
            }
        }
    }

    return true;
}
statue BFSTraverse(Graph g)
{
    int * D = (int *)malloc(sizeof(int) * g.node_nowsite);
    for(int i = 0;i < g.node_nowsite;i++)
    {
        D[i] = 1;
    }
    for(int i = 0;i < g.node_nowsite;i++)
    {
        if(D[i] == 0)
            continue;
        printf("%dth : %c\n",g.node[i].site,g.node[i].data);
        D[i] = 0;

        Queue q;
        InitQueue(&q);
        for(int k = 0;k < g.node_nowsite;k++)
        {
            if(k == i)
                continue;
            if(g.edge[i][k] == 1 && D[k])
            {
                EnQueue(&q,k);
                D[k] = 0;
            }
        }
        while(!QueueEmpty(q))
        {
            int now_site;
            DeQueue(&q,&now_site);
            printf("%dth : %c\n",g.node[now_site].site,g.node[now_site].data);
            D[now_site] = 0;
            for(int k = 0;k < g.node_nowsite;k++)
            {
                if(k == i)
                    continue;
                if(g.edge[now_site][k] == 1 && D[k])
                {
                    EnQueue(&q,k);
                    D[k] = 0;
                }
            }
        }

    }

    return true;
}
