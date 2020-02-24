//
// Created by HP on 2019/11/21.
//

#include <stdlib.h>
#include <stdio.h>
#include "BinaryTree.h"

#define HRMTEST
#ifndef HRMTEST
int fig[10] = {15,18,1,2,5,7,9,11,20,30};
float weight[10] = {0.1,0.05,0.2,0.3,0.15,0.04,0.06,0.01,0.07,0.02};
#endif
typedef struct Link_ADT
{
    PointTree data;
    struct Link_ADT * next;
}LinkNode,*PointLink;
typedef struct
{
    PointLink Frst,Lst;
    int Length;
}Link;
void InitList(Link * L)
{
    PointLink p = (PointLink)malloc(sizeof(PointTree));
    p->data = 0;
    p->next = NULL;
    L->Frst = p;
    L->Lst = p;
    L->Length = 0;
}
void AddLink(Link * l,int i)
{
    float weight;
    printf("weight %dth : ",i);
    scanf("%f",&weight);
    int fig;
    printf("firgure %dth : ",i);
    scanf("%d",&fig);


    PointLink new = (PointLink)malloc(sizeof(LinkNode));
    new->data = (PointTree)malloc(sizeof(BinaryTree));
    new->data->weight = (int)(weight * 100);
    new->data->data = fig;
    new->data->site = i;
    new->data->Left = NULL;
    new->data->Right = NULL;

    new->next = NULL;

    l->Lst->next = new;
    l->Lst = new;
    l->Length++;
}
statue DeleteLink(Link * l,PointTree *t)
{
    PointLink p = l->Frst->next;
    l->Frst->next = p->next;
    *t = p->data;
    free(p);

    l->Length --;

    return true;
}
statue GetElem(Link * L,int i,int *e)
{
    if(i > L->Length || i < 1)
        return false;
    LinkNode * p = L->Frst->next;
    int k = 1;
    while(k < i)
    {
        p = p->next;
        k++;
    }
    *e = p->data->weight;
}
PointLink LocateLink(Link * l,int n)
{
    PointLink p = l->Frst->next;

    for(int i = 0;i < l->Length;i++)
    {
        if(i == n - 1)
            break;
        p = p->next;
    }

    return p;
}
PointLink FindParent(Link * l,int w)
{
    PointLink p = l->Frst;
    while(p->next)
    {
        if(p->next->data->weight == w)
            return p;
        p = p->next;
    }

    return NULL;
}

PointTree ConbineTree(PointTree t1,PointTree t2,int n)
{
    PointTree p = (PointTree)malloc(sizeof(BinaryTree));
    p->weight = t1->weight + t2->weight;
    p->data = p->weight;
    p->site = n;
    p->Left = t1;
    p->Right = t2;

    return p;
}
//add delete sort problem
PointTree HRMtree()
{
    int num;
    printf("enter the number of weight :");
    scanf("%d",&num);
    Link SavingTree;
    InitList(&SavingTree);

    for(int i = 0;i < num;i++)
    {
        AddLink(&SavingTree,i);
    }
    //sort problem
    PointLink p = SavingTree.Frst;
    for(int i = 0;i < num - 1;i++)
    {
        if(p->data)
            printf("%dth : %d %d\n",p->data->site,p->data->data,p->data->weight);
        PointLink q;
        q = p->next;
        PointLink pause = NULL;
        int min = q->data->weight;
        while(q)
        {
            if(q->data->weight < min)
            {
                min = q->data->weight;
                pause = q;
            }
            q = q->next;
        }
        if(!pause)
        {
            p = p->next;
            continue;
        }
        PointLink pause_node = FindParent(&SavingTree,min);
        pause_node->next = pause->next;
        pause_node = p->next;
        p->next = pause;
        p->next->next = pause_node;
        p = p->next;
    }
    while(1)
    {
        if(SavingTree.Length < 2)
            break;
        PointTree t1;
        DeleteLink(&SavingTree,&t1);
        PointTree t2;
        DeleteLink(&SavingTree,&t2);

        PointLink newNode = (PointLink)malloc(sizeof(LinkNode));
        newNode->data = ConbineTree(t1,t2,1);
        PointLink FindPoint = SavingTree.Frst;
        while(1)
        {
            if(FindPoint->next->data->weight > newNode->data->weight)
            {
                newNode->next = FindPoint->next;
                FindPoint->next = newNode;
                break;
            }
            FindPoint = FindPoint->next;
        }
    }
    return SavingTree.Frst->next->data;
}
int main()
{
    PointTree HRM = NULL;
    HRM = HRMtree();
    LevelOrderTraverse(*HRM);
    PreOder(HRM);
}
