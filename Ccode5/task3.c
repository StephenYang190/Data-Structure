//
// Created by HP on 2019/11/12.
//
#include <stdlib.h>
#include <stdio.h>
#include "BinaryTree.h"
#include "Queue.h"

statue DeleteElemTree(BinaryTree * t,int elem)
{
    if(BiTreeEmpty(*t))
    {
        printf("Empty.\n");
        return true;
    }
    Queue q;
    InitQueue(&q);
    EnQueue(&q,t->root,1);
    while(!QueueEmpty(q))
    {
        PointNode p;
        int e;
        DeQueue(&q,&p,&e);
        if(p->data == elem)
        {
            BinaryTree tree_pause;
            tree_pause.root = p;
            PointNode parent_node = Parent(t,p->site);

            if(parent_node)
                if(parent_node->Left == p)
                    parent_node->Left = NULL;
                else
                    parent_node->Right = NULL;
            DestroyBiTree(&tree_pause);
            continue;
        }
        if(p->Left)
        {
            EnQueue(&q,p->Left,e + 1);
        }
        if(p->Right)
        {
            EnQueue(&q,p->Right,e + 1);
        }
    }
    DestroyQueue(&q);
    printf("\nDelet End.\n");
    return true;
}

