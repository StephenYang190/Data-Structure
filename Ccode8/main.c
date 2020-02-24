#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

PointTree TreeLocate(PointTree t,int n)
{
    PointTree p = t;
    while(1)
    {
        if(!p || p->data == n)
            break;
        if(n > p->data)
            p = p->Right;
        else
            p = p->Left;
    }

    return p;
}
PointTree TreeParent(PointTree t,int n)
{
    PointTree p = t;
    while(1)
    {
        if(!p)
            break;
        if(p->Left->data == n)
            break;
        if(p->Right->data == n)
            break;
        if(n > p->data)
            p = p->Right;
        else
            p = p->Left;
    }
    return p;
}
PointTree TreeLeft(PointTree t)
{
    PointTree p = t->Left;
    while(p->Right)
    {
        p = p->Right;
    }

    return p;
}
statue TreeAppend(PointTree t,int n)
{
    PointTree p = t;
    int direction = 0;
    while(1)
    {
        if(!p || p->data == n)
            break;
        if(n > p->data)
        {
            if(!p->Right)
            {
                direction = 1;
                break;
            }
            p = p->Right;
        }
        else
        {
            if(!p->Left)
            {
                direction = 0;
                break;
            }
            p = p->Left;
        }
    }
    if(!p || p->data == n)
        return false;
    PointTree q = (PointTree)malloc((sizeof(BinaryTree)));
    q->Left = NULL;
    q->Right = NULL;
    q->site = p->site * 2;
    q->data = n;
    switch (direction) {
        case 0: {
            p->Left = q;
        }
            break;
        case 1: {
            p->Right = q;
            q->site += 1;
        }
            break;
        default:;
            break;
    }

    return true;

}
statue TreeDelete(PointTree t,int n)
{
    PointTree p = TreeLocate(t,n);
    if(!p)
        return false;
    if(p == t)
    {
        if(!p->Left && !p->Right)
        {
            free(p);
            return true;
        }
        if(!p->Left)
        {
            t = t->Right;
            return true;
        }
        PointTree q = TreeLeft(p);
        if(q->Left)
        {
            TreeParent(t,q->data)->Right = q->Left;
        }
        t->data = q->data;

        free(q);

        return true;
    }
    else{
        PointTree parent = TreeParent(t,n);;
        if(!p->Left && !p->Right)
        {
            if(parent->Left == p)
                parent->Left = NULL;
            else
                parent->Right = NULL;
            free(p);
            return true;
        }
        if(!p->Left)
        {
            if(parent->Left == p)
                parent->Left = p->Right;
            else
                parent->Right = p->Right;
            free(p);
            return true;
        }
        PointTree q = TreeLeft(p);
        if(q->Left)
        {
            PointTree pa = TreeParent(t,q->data);
            if(pa->Left == q)
                pa->Left = q->Left;
            else
                pa->Right = q->Left;
        }
        else{
            PointTree pa = TreeParent(t,q->data);
            if(pa->Left == q)
                pa->Left = NULL;
            else
                pa->Right = NULL;
        }
        p->data = q->data;

        free(q);

        return true;
    }
}
int main() {
    BinaryTree tree;
    InitBitree(&tree);
    while(1)
    {
        int num;
        printf("number : ");
        if(!scanf("%d",&num))
            break;
        TreeAppend(&tree,num);
    }
    LevelOrderTraverse(tree);

    TreeDelete(&tree,6);
    LevelOrderTraverse(tree);
    printf("Hello, World!\n");
    return 0;
}