#include <stdio.h>
#include <stdlib.h>
#include "Link.h"

/*Init Finish*/
void InitList(Link * L)
{
    Listink p = (Listink)malloc(sizeof(Node));
    p->next = NULL;
    L->Frst = p;
    L->Lst = p;
    p->x1 = 0;
    p->x2 = 0;
    p->y1 = 0;
    p->y2 = 0;
    L->Length = 0;
    p->sign = 0;
}
/*Empty Finis*/
statue ListEmpty(Link * L)
{
    if(L->Lst == L->Frst)
        return true;
    return false;
}
void DestroyList(Link * L)
{
    if(!ListEmpty(L))
    {
        Listink p = L->Frst;
        while(p)
        {
            Listink q = p->next;
            free(p);
            p = q;
        }
    }
    L->Frst = NULL;
    L->Lst = NULL;
    L->Length = -1;
}
int ListLength(Link * L)
{
    return L->Length;
}
/*Get Finish*/
statue GetElem(Link * L,int i,int *e1,int *e2,int *e3,int *e4)
{
    if(i > L->Length || i < 1)
        return false;
    Node * p = L->Frst->next;
    int k = 1;
    while(k < i && p)
    {
        p = p->next;
        k++;
    }
    if(!p)
        return false;
    *e1 = p->x1 ;
    *e2 = p->x2 ;
    *e3 = p->y1 ;
    *e4 = p->y2 ;

    return true;
}
Node * PriorElem(Link * L,int i)
{
    Node * p = L->Frst->next;
    Node * q = L->Frst;
    while(p && p->sign != i)
    {
        q = p;
        p = p->next;
    }
    if(p)
    {
        return q;
        printf("!!\n");
    }
    return NULL;

}
/*Clear Finish*/
void ClearList(Link * L)
{
    if(!ListEmpty(L))
    {
        Listink p = L->Frst->next;
        while(p)
        {
            Listink q = p->next;
            free(p);
            p = q;
        }
    }
    L->Frst->next = NULL;
    L->Lst = L->Frst;
    L->Length = 0;
}
/*add Finish*/
void add(Link * l,int e1,int e2,int e3,int e4)
{
    Listink new = (Listink)malloc(sizeof(Node));
    new->x1 = e1;
    new->y1 = e2;
    new->x2 = e3;
    new->y2 = e4;
    new->sign = ++l->Length;

    new->next = l->Frst->next;
    l->Frst->next = new;
}
/*show Finish*/
void showlisk(Link * l)
{
    Listink p = l->Frst->next;
    int k = 1;
    while(p)
    {
        printf("(%d,%d) (%d,%d)\n",p->x1,p->y1,p->x2,p->y2);
        p = p->next;
        k++;
    }
    printf("\n");
}
