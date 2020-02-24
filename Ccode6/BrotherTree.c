//
// Created by 97927 on 2019/11/26.
//
#include <stdio.h>
#include <stdlib.h>

/*The data difinit*/
#ifndef STATUE
typedef enum  {false,true} statue;
#define STATUE
#endif
typedef struct TREE_ADT
{
    int layer;
    int site;
    int data;
    struct TREE_ADT * child;
    struct TREE_ADT * brother;
}BrotherTree,*PointTree;

statue InitBitree(BrotherTree * t)
{
    t = NULL;

    return true;
}
statue CreateBiTree(PointTree * t,int n)
{
    PointTree p = (PointTree)malloc(sizeof(BrotherTree));

    p->child = NULL;
    p->brother = NULL;
    p->data = n;
    p->layer = 1;
    p->site = 1;

    *t = p;

    return true;
}
statue Assign(BrotherTree * t,int layer,int n)
{
    if(layer < 2)
        return false;
    PointTree p = t;

    while(p->layer < layer)
    {
        if(p->child == NULL)
            break;
        p = p->child;
    }
    PointTree q = (PointTree)malloc(sizeof(BrotherTree));
    q->child = NULL;
    q->brother = NULL;
    q->data = n;

    if(p->layer < layer)
    {
        q->layer = p->layer + 1;
        q->site = 1;
        p->child = q;
    }
    else
    {
        while(p->brother)
        {
            p = p->brother;
        }
        q->site = p->site + 1;
        p->brother = q;
        q->layer = layer;
    }

    printf("\nAssign End.\n");
    return true;
}
statue ShowTreeL(BrotherTree t,int layer)
{
    PointTree p = &t;

    while(p->layer < layer)
    {
        if(p->child == NULL)
            break;
        p = p->child;
    }
    if(p->layer < layer)
    {
        printf("layer is too big.\n");
        return false;
    }
    while(p)
    {
        printf("site%d : %d\n",p->site,p->data);
        p = p->brother;
    }

    return true;
}
int main()
{
    PointTree Ptree;
    InitBitree(Ptree);
    printf("Enter the data of root : ");
    int num;
    scanf("%d",&num);
    CreateBiTree(&Ptree,num);
    while(1)
    {
        printf("Enter the layer : ");
        int layer;
        if(scanf("%d",&layer) != 1)
            break;
        printf("Enter the data : ");
        scanf("%d",&num);
        Assign(Ptree,layer,num);
    }
    ShowTreeL(*Ptree,3);

    return 0;
}