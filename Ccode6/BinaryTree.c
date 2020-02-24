//
// Created by HP on 2019/11/9.
//
#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>
#include "TreeStack.h"
#include "TreeQueue.h"

PointTree LocalNode(BinaryTree * t,int e)
{
    if(BiTreeEmpty(*t))
    {
        printf("Wrong.\n");
        return NULL;
    }
    Queue q;
    int a = 1;
    PointTree p = NULL;
    InitTQueue(&q);
    EnTQueue(&q,t,a);

    while(!TQueueEmpty(q))
    {
        DeTQueue(&q,&p,&a);
        if(p->site == e)
            break;
        if(p->Left)
        {
            EnTQueue(&q,p->Left,a + 1);
        }
        if(p->Right)
        {
            EnTQueue(&q,p->Right,a + 1);
        }
    }
    DestroyTQueue(&q);
    if(p->data != e)
        return NULL;
    return p;

}
statue InitBitree(BinaryTree * t)
{
    t = NULL;

    return true;
}
statue DestroyBiTree(BinaryTree * t)
{
    if(BiTreeEmpty(*t))
    {
        printf("Empty.\n");
        return true;
    }
    Queue q;
    InitTQueue(&q);
    EnTQueue(&q,t,1);
    while(!TQueueEmpty(q))
    {
        PointTree p;
        int e;
        DeTQueue(&q,&p,&e);
        if(p->Left)
        {
            EnTQueue(&q,p->Left,e + 1);
        }
        if(p->Right)
        {
            EnTQueue(&q,p->Right,e + 1);
        }
        free(p);
    }
    t = NULL;
    DestroyTQueue(&q);
    return true;
}
statue CreateBiTree(BinaryTree * t,int n,int w)
{
    PointTree p = (PointTree)malloc(sizeof(BinaryTree));
    p->Right = NULL;
    p->Left = NULL;
    p->data = n;
    t = p;
    p->site = 1;
    p->weight = w;

    return true;
}
statue ClearBiTree(BinaryTree * t)
{
    int n = t->data;
    int w = t->weight;
    DestroyBiTree(t);
    CreateBiTree(t,n,w);

    return 0;
}
statue BiTreeEmpty(BinaryTree t)
{
    if(!&t)
        return true;
    return false;
}
int BiTreeDepth(BinaryTree t)
{
    if(BiTreeEmpty(t))
    {
        printf("Empty.\n");
        return 0;
    }
    Queue q;
    int e = 1;
    InitTQueue(&q);
    EnTQueue(&q,&t,e);

    while(!TQueueEmpty(q))
    {
        PointTree p;
        DeTQueue(&q,&p,&e);
        if(p->Left)
        {
            EnTQueue(&q,p->Left,e + 1);
        }
        if(p->Right)
        {
            EnTQueue(&q,p->Right,e + 1);
        }
    }
    DestroyTQueue(&q);
    printf("\nDepth End.\n");
    return e;
}
statue Assign(BinaryTree * t,int c,int n)
{
    if(BiTreeEmpty(*t))
    {
        printf("Wrong.\n");
        return false;
    }
    Queue q;
    int e = 1;
    InitTQueue(&q);
    EnTQueue(&q,t,e);

    while(!TQueueEmpty(q))
    {
        PointTree p;
        DeTQueue(&q,&p,&e);
        if(p->site == c)
        {
            p->data = n;
            break;
        }
        if(p->Left)
        {
            EnTQueue(&q,p->Left,e + 1);
        }
        if(p->Right)
        {
            EnTQueue(&q,p->Right,e + 1);
        }
    }
    if(TQueueEmpty(q))
    {
        DestroyTQueue(&q);
        return false;
    }
    DestroyTQueue(&q);
    printf("\nAssign End.\n");
    return true;
}
PointTree Parent(BinaryTree * t,int e)
{
    if(BiTreeEmpty(*t))
    {
        printf("Wrong.\n");
        return NULL;
    }
    Queue q;
    int c = 1;
    PointTree p = NULL;
    InitTQueue(&q);
    EnTQueue(&q,t,c);

    while(!TQueueEmpty(q))
    {
        DeTQueue(&q,&p,&c);
        if(p->Left)
        {
            EnTQueue(&q,p->Left,c + 1);
            if(p->Left->site == e)
                break;

        }
        if(p->Right)
        {
            EnTQueue(&q,p->Right,c + 1);
            if(p->Right->site == e)
                break;

        }
    }
    if(TQueueEmpty(q))
    {
        DestroyTQueue(&q);
        return NULL;
    }

    printf("\nParent End.\n");
    return p;
}
PointTree LeftChilde(BinaryTree * t,int e)
{
    if(BiTreeEmpty(*t))
    {
        printf("Wrong.\n");
        return NULL;
    }
    Queue q;
    int c = 1;
    PointTree p = NULL;
    InitTQueue(&q);
    EnTQueue(&q,t,c);

    while(!TQueueEmpty(q))
    {
        DeTQueue(&q,&p,&c);
        if(p->site == e)
            break;
        if(p->Left)
        {
            EnTQueue(&q,p->Left,c + 1);
        }
        if(p->Right)
        {
            EnTQueue(&q,p->Right,c + 1);
        }
    }
    DestroyTQueue(&q);
    if(p->site != e)
        return NULL;
    printf("\nLeftChilde End.\n");
    return p->Left;
}
PointTree RightChilde(BinaryTree * t,int e)
{
    if(BiTreeEmpty(*t))
    {
        printf("Wrong.\n");
        return NULL;
    }
    Queue q;
    int c = 1;
    PointTree p = NULL;
    InitTQueue(&q);
    EnTQueue(&q,t,c);

    while(!TQueueEmpty(q))
    {
        DeTQueue(&q,&p,&c);
        if(p->site == e)
            break;
        if(p->Left)
        {
            EnTQueue(&q,p->Left,c + 1);
        }
        if(p->Right)
        {
            EnTQueue(&q,p->Right,c + 1);
        }
    }
    DestroyTQueue(&q);
    if(p->site != e)
        return NULL;
    printf("\nRightChilde End.\n");
    return p->Right;
}
PointTree LeftSibling(BinaryTree * t,int e)
{
    if(BiTreeEmpty(*t))
    {
        printf("Wrong.\n");
        return NULL;
    }
    PointTree p = Parent(t,e);
    if(!p)
    {
        printf("Wrong.\n");
        return NULL;
    }
    if(p->Left->site == e)
        return NULL;
    return p->Left;
}
PointTree RightSibling(BinaryTree * t,int e)
{
    if(BiTreeEmpty(*t))
    {
        printf("Wrong.\n");
        return NULL;
    }
    PointTree p = Parent(t,e);
    if(!p)
    {
        printf("Wrong.\n");
        return NULL;
    }
    if(p->Right->site == e)
        return NULL;
    return p->Right;
}

statue DeleteChild(BinaryTree * t,int e,int LR)
{
    if(BiTreeEmpty(*t))
    {
        printf("Wrong.\n");
        return false;
    }
    Queue q;
    int a = 1;
    PointTree p = NULL;
    InitTQueue(&q);
    EnTQueue(&q,t,a);

    while(!TQueueEmpty(q))
    {
        DeTQueue(&q,&p,&a);
        if(p->site == e)
            break;
        if(p->Left)
        {
            EnTQueue(&q,p->Left,a + 1);
        }
        if(p->Right)
        {
            EnTQueue(&q,p->Right,a + 1);
        }
    }
    DestroyTQueue(&q);
    if(p->site != e)
        return false;
    switch (LR)
    {
        case 1:
        {
            PointTree pause_tree;
            pause_tree = p->Left;
            DestroyBiTree(&pause_tree);
            p->Left = NULL;
        }
        break;
        case 2:
        {
            PointTree pause_tree;
            pause_tree = p->Right;
            DestroyBiTree(&pause_tree);
            p->Right = NULL;
        }
        break;
        default:
            return false;
    }
    return true;
}
statue PreOrderTraverse(BinaryTree t) {
    if (BiTreeEmpty(t)) {
        printf("Empty.\n");
        return true;
    }
    PointTree p;
    Stack s;
    InitTStack(&s);
    printf("%d : %d\n", t.site,t.data);
    if (t.Left) {
        TPush(&s, &t, 1);
        p = t.Left;
    } else if (t.Right) {
        TPush(&s, &t, 2);
        p = t.Right;
    } else{
        printf("\nPreOrderTraverse End.\n");
        return false;
    }
    while(!TStackEmpty(s))
    {
        if(!p)
        {
            if(s.Frst[s.top - 1].flag == 1)
            {
                p = s.Frst[s.top - 1].t->Right;
                s.Frst[s.top - 1].flag = 2;
            }
            else
            {
                TPop(&s,&p);
                p = NULL;
            }
            continue;
        }
        printf("%d : %d\n",p->site,p->data);
        if (p->Left) {
            TPush(&s, p, 1);
            p = p->Left;
        } else if (p->Right) {
            TPush(&s, p, 2);
            p = p->Right;
        } else{
            if(s.Frst[s.top - 1].flag == 1)
            {
                p = s.Frst[s.top - 1].t->Right;
                s.Frst[s.top - 1].flag = 2;
            }
            else
            {
                TPop(&s,&p);
                p = NULL;
            }
        }
    }
    DestroyTStack(&s);
    printf("\nPreOrderTraverse End.\n");
    return true;
}
statue InOrderTraverse(BinaryTree t)
{
    if (BiTreeEmpty(t)) {
        printf("Empty.\n");
        return true;
    }
    PointTree p = &t;
    statue f = false;
    Stack s;
    InitTStack(&s);
    do{
        if(f)
        {
            f = false;
            printf("%d : %d\n",p->site,p->data);
            if(p->Right)
            {
                p = p->Right;
            }
            else
            {
                if(TPop(&s,&p))
                    f = true;
                continue;
            }
        }
        if(p->Left)
        {
            TPush(&s,p,1);
            p = p->Left;
        }
        else
        {
            printf("%d : %d\n",p->site,p->data);
            if(p->Right)
            {
                p = p->Right;
            }
            else
            {
                if(TPop(&s,&p))
                    f = true;
            }
        }
    }while(!TStackEmpty(s) || f);
    DestroyTStack(&s);
    printf("\nInOrderTraverse End.\n");
    return true;
}
statue PostOrderTraverse(BinaryTree t)//PostOder uses stack
{
    if(BiTreeEmpty(t))
    {
        printf("Empty.\n");
        return true;
    }
    PointTree p;
    Stack s;
    InitTStack(&s);
    statue f = false;
    if(t.Left)
    {
        TPush(&s,&t,1);
        p = t.Left;
    }
    else if(t.Right)
    {
        TPush(&s,&t,2);
        p = t.Right;
    }
    else
    {
        printf("%d : %d\n",t.site,t.data);
        return true;
    }
    while(!TStackEmpty(s) || f)
    {
        if(f)
        {
            f = false;
            printf("%d : %d\n",p->site,p->data);
            if(s.Frst[s.top - 1].flag == 1) {
                p = s.Frst[s.top - 1].t->Right;
                s.Frst[s.top - 1].flag = 2;
            }
            else
            {
                if(TPop(&s,&p))
                    f = true;
                continue;
            }
        }
        if(!p)
        {
            TPop(&s,&p);
            f = true;
            continue;
        }
        if(p->Left)
        {
            TPush(&s,p,1);
            p = p->Left;
        }
        else if(p->Right)
        {
            TPush(&s,p,2);
            p = p->Right;
        }
        else
            {
                printf("%d : %d\n",p->site,p->data);
                if(s.Frst[s.top - 1].flag == 1) {
                    p = s.Frst[s.top - 1].t->Right;
                    s.Frst[s.top - 1].flag = 2;
                }
                else
                {
                    if(TPop(&s,&p))
                        f = true;
                }
            }
    }
    DestroyTStack(&s);
    printf("\nPoseOrderTraverse End.\n");
    return true;
}
statue LevelOrderTraverse(BinaryTree t)
{
    if(BiTreeEmpty(t))
    {
        printf("Empty.\n");
        return true;
    }
    Queue q;
    InitTQueue(&q);
    EnTQueue(&q,&t,1);
    while(!TQueueEmpty(q))
    {
        PointTree p;
        int e;
        DeTQueue(&q,&p,&e);
        printf("%d : %d\n",p->site,p->data);
        if(p->Left)
        {
            EnTQueue(&q,p->Left,e + 1);
        }
        if(p->Right)
        {
            EnTQueue(&q,p->Right,e + 1);
        }
    }
    DestroyTQueue(&q);
    printf("\nLevelOrderTraverse End.\n");
    return true;
}
statue PreOder(PointTree t)
{
    if(t)
    {
        printf("%d : %d\n",t->site,t->data);
        if(t->Left)
            PreOder(t->Left);
        if(t->Right)
            PreOder(t->Right);
        return true;
    }
    return false;
}
statue InOrder(PointTree t)
{
    if(t)
    {
        if(t->Left)
            PreOder(t->Left);
        printf("%d : %d\n",t->site,t->data);
        if(t->Right)
            PreOder(t->Right);
        return true;
    }
    return false;
}
statue PostOrder(PointTree t)
{
    if(t)
    {
        if(t->Left)
            PreOder(t->Left);
        if(t->Right)
            PreOder(t->Right);
        printf("%d : %d\n",t->site,t->data);
        return true;
    }
    return false;
}