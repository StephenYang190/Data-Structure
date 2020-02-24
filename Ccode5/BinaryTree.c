//
// Created by HP on 2019/11/9.
//
#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "Queue.h"

PointNode LocalNode(BinaryTree * t,int e)
{
    if(BiTreeEmpty(*t))
    {
        printf("Wrong.\n");
        return NULL;
    }
    Queue q;
    int a = 1;
    PointNode p = NULL;
    InitQueue(&q);
    EnQueue(&q,t->root,a);

    while(!QueueEmpty(q))
    {
        DeQueue(&q,&p,&a);
        if(p->site == e)
            break;
        if(p->Left)
        {
            EnQueue(&q,p->Left,a + 1);
        }
        if(p->Right)
        {
            EnQueue(&q,p->Right,a + 1);
        }
    }
    DestroyQueue(&q);
    if(p->data != e)
        return NULL;
    return p;

}
statue InitBitree(BinaryTree * t)
{
    t->root = NULL;
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
    InitQueue(&q);
    EnQueue(&q,t->root,1);
    while(!QueueEmpty(q))
    {
        PointNode p;
        int e;
        DeQueue(&q,&p,&e);
        if(p->Left)
        {
            EnQueue(&q,p->Left,e + 1);
        }
        if(p->Right)
        {
            EnQueue(&q,p->Right,e + 1);
        }
        free(p);
    }
    t->root = NULL;
    DestroyQueue(&q);
    return true;
}
statue CreateBiTree(BinaryTree * t,int n)
{
    PointNode p = (PointNode)malloc(sizeof(Node));
    p->Right = NULL;
    p->Left = NULL;
    p->data = n;
    t->root = p;
    p->site = 1;

    return true;
}
statue ClearBiTree(BinaryTree * t)
{
    int n = t->root->data;
    DestroyBiTree(t);
    CreateBiTree(t,n);

    return 0;
}
statue BiTreeEmpty(BinaryTree t)
{
    if(!t.root)
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
    InitQueue(&q);
    EnQueue(&q,t.root,e);

    while(!QueueEmpty(q))
    {
        PointNode p;
        DeQueue(&q,&p,&e);
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
    InitQueue(&q);
    EnQueue(&q,t->root,e);

    while(!QueueEmpty(q))
    {
        PointNode p;
        DeQueue(&q,&p,&e);
        if(p->site == c)
        {
            p->data = n;
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
    }
    if(QueueEmpty(q))
    {
        DestroyQueue(&q);
        return false;
    }
    DestroyQueue(&q);
    printf("\nAssign End.\n");
    return true;
}
PointNode Parent(BinaryTree * t,int e)
{
    if(BiTreeEmpty(*t))
    {
        printf("Wrong.\n");
        return NULL;
    }
    Queue q;
    int c = 1;
    PointNode p = NULL;
    InitQueue(&q);
    EnQueue(&q,t->root,c);

    while(!QueueEmpty(q))
    {
        DeQueue(&q,&p,&c);
        if(p->Left)
        {
            EnQueue(&q,p->Left,c + 1);
            if(p->Left->site == e)
                break;

        }
        if(p->Right)
        {
            EnQueue(&q,p->Right,c + 1);
            if(p->Right->site == e)
                break;

        }
    }
    if(QueueEmpty(q))
    {
        DestroyQueue(&q);
        return NULL;
    }

    printf("\nParent End.\n");
    return p;
}
PointNode LeftChilde(BinaryTree * t,int e)
{
    if(BiTreeEmpty(*t))
    {
        printf("Wrong.\n");
        return NULL;
    }
    Queue q;
    int c = 1;
    PointNode p = NULL;
    InitQueue(&q);
    EnQueue(&q,t->root,c);

    while(!QueueEmpty(q))
    {
        DeQueue(&q,&p,&c);
        if(p->site == e)
            break;
        if(p->Left)
        {
            EnQueue(&q,p->Left,c + 1);
        }
        if(p->Right)
        {
            EnQueue(&q,p->Right,c + 1);
        }
    }
    DestroyQueue(&q);
    if(p->site != e)
        return NULL;
    printf("\nLeftChilde End.\n");
    return p->Left;
}
PointNode RightChilde(BinaryTree * t,int e)
{
    if(BiTreeEmpty(*t))
    {
        printf("Wrong.\n");
        return NULL;
    }
    Queue q;
    int c = 1;
    PointNode p = NULL;
    InitQueue(&q);
    EnQueue(&q,t->root,c);

    while(!QueueEmpty(q))
    {
        DeQueue(&q,&p,&c);
        if(p->site == e)
            break;
        if(p->Left)
        {
            EnQueue(&q,p->Left,c + 1);
        }
        if(p->Right)
        {
            EnQueue(&q,p->Right,c + 1);
        }
    }
    DestroyQueue(&q);
    if(p->site != e)
        return NULL;
    printf("\nRightChilde End.\n");
    return p->Right;
}
PointNode LeftSibling(BinaryTree * t,int e)
{
    if(BiTreeEmpty(*t))
    {
        printf("Wrong.\n");
        return NULL;
    }
    PointNode p = Parent(t,e);
    if(!p)
    {
        printf("Wrong.\n");
        return NULL;
    }
    if(p->Left->site == e)
        return NULL;
    return p->Left;
}
PointNode RightSibling(BinaryTree * t,int e)
{
    if(BiTreeEmpty(*t))
    {
        printf("Wrong.\n");
        return NULL;
    }
    PointNode p = Parent(t,e);
    if(!p)
    {
        printf("Wrong.\n");
        return NULL;
    }
    if(p->Right->site == e)
        return NULL;
    return p->Right;
}
statue InserChild(BinaryTree * t,int e,int LR,BinaryTree * c)
{
    if(BiTreeEmpty(*t))
    {
        printf("Wrong.\n");
        return false;
    }
    Queue q;
    int a = 1;
    PointNode p = NULL;
    InitQueue(&q);
    EnQueue(&q,t->root,a);

    while(!QueueEmpty(q))
    {
        DeQueue(&q,&p,&a);
        if(p->site == e)
            break;
        if(p->Left)
        {
            EnQueue(&q,p->Left,a + 1);
        }
        if(p->Right)
        {
            EnQueue(&q,p->Right,a + 1);
        }
    }
    DestroyQueue(&q);
    if(p->site != e)
        return false;
    switch (LR)
    {
        case 1:
        {
            c->root->site = p->site * 2;
            if(p->Left)
            {
                PointNode pause = p->Left;
                p->Left = c->root;
                c->root->Right = pause;
            }
            else
            {
                p->Left = c->root;
            }
        }
        break;
        case 2:
        {
            c->root->site = p->site * 2 + 1;
            if(p->Right)
            {
                PointNode pause = p->Right;
                p->Right = c->root;
                p->Right->Right = pause;
            }
            else
            {
                p->Right = c->root;
            }
        }
        break;
        default:
            return false;
    }
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
    PointNode p = NULL;
    InitQueue(&q);
    EnQueue(&q,t->root,a);

    while(!QueueEmpty(q))
    {
        DeQueue(&q,&p,&a);
        if(p->site == e)
            break;
        if(p->Left)
        {
            EnQueue(&q,p->Left,a + 1);
        }
        if(p->Right)
        {
            EnQueue(&q,p->Right,a + 1);
        }
    }
    DestroyQueue(&q);
    if(p->site != e)
        return false;
    switch (LR)
    {
        case 1:
        {
            BinaryTree pause_tree;
            pause_tree.root = p->Left;
            DestroyBiTree(&pause_tree);
            p->Left = NULL;
        }
        break;
        case 2:
        {
            BinaryTree pause_tree;
            pause_tree.root = p->Right;
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
    PointNode p;
    Stack s;
    InitStack(&s);
    printf("%d : %d\n", t.root->site,t.root->data);
    if (t.root->Left) {
        Push(&s, t.root, 1);
        p = t.root->Left;
    } else if (t.root->Right) {
        Push(&s, t.root, 2);
        p = t.root->Right;
    } else{
        printf("\nPreOrderTraverse End.\n");
        return false;
    }
    while(!StackEmpty(s))
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
                Pop(&s,&p);
                p = NULL;
            }
            continue;
        }
        printf("%d : %d\n",p->site,p->data);
        if (p->Left) {
            Push(&s, p, 1);
            p = p->Left;
        } else if (p->Right) {
            Push(&s, p, 2);
            p = p->Right;
        } else{
            if(s.Frst[s.top - 1].flag == 1)
            {
                p = s.Frst[s.top - 1].t->Right;
                s.Frst[s.top - 1].flag = 2;
            }
            else
            {
                Pop(&s,&p);
                p = NULL;
            }
        }
    }
    DestroyStack(&s);
    printf("\nPreOrderTraverse End.\n");
    return true;
}
statue InOrderTraverse(BinaryTree t)
{
    if (BiTreeEmpty(t)) {
        printf("Empty.\n");
        return true;
    }
    PointNode p = t.root;
    statue f = false;
    Stack s;
    InitStack(&s);
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
                if(Pop(&s,&p))
                    f = true;
                continue;
            }
        }
        if(p->Left)
        {
            Push(&s,p,1);
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
                if(Pop(&s,&p))
                    f = true;
            }
        }
    }while(!StackEmpty(s) || f);
    DestroyStack(&s);
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
    PointNode p;
    Stack s;
    InitStack(&s);
    statue f = false;
    if(t.root->Left)
    {
        Push(&s,t.root,1);
        p = t.root->Left;
    }
    else if(t.root->Right)
    {
        Push(&s,t.root,2);
        p = t.root->Right;
    }
    else
    {
        printf("%d : %d\n",t.root->site,t.root->data);
        return true;
    }
    while(!StackEmpty(s) || f)
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
                if(Pop(&s,&p))
                    f = true;
                continue;
            }
        }
        if(!p)
        {
            Pop(&s,&p);
            f = true;
            continue;
        }
        if(p->Left)
        {
            Push(&s,p,1);
            p = p->Left;
        }
        else if(p->Right)
        {
            Push(&s,p,2);
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
                    if(Pop(&s,&p))
                        f = true;
                }
            }
    }
    DestroyStack(&s);
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
    InitQueue(&q);
    EnQueue(&q,t.root,1);
    while(!QueueEmpty(q))
    {
        PointNode p;
        int e;
        DeQueue(&q,&p,&e);
        printf("%d : %d\n",p->site,p->data);
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
    printf("\nLevelOrderTraverse End.\n");
    return true;
}
statue PreOder(PointNode t)
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
statue InOrder(PointNode t)
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
statue PostOrder(PointNode t)
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