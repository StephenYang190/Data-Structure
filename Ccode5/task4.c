//
// Created by HP on 2019/11/12.
//
#include <stdlib.h>
#include <stdio.h>
#include "BinaryTree.h"
#include "Queue.h"

statue TreeFull(BinaryTree t)
{
    if(BiTreeEmpty(t))
    {
        printf("Empty.\n");
        return true;
    }
    Queue q;
    InitQueue(&q);
    statue flag = true;
    int last_site = 0;
    EnQueue(&q,t.root,1);
    while(!QueueEmpty(q))
    {
        PointNode p;
        int e;
        DeQueue(&q,&p,&e);
        if(p->site != last_site + 1)
        {
            flag = false;
            break;
        }
        if(p->Left)
        {
            EnQueue(&q,p->Left,e + 1);
        }
        if(p->Right)
        {
            EnQueue(&q,p->Right,e + 1);
        }
        last_site = p->site;
    }
    DestroyQueue(&q);
    if(flag)
        printf("it is full.\n");
    else
        printf("NO.\n");
    printf("\nCompare End.\n");
    return true;
}