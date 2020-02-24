//
// Created by HP on 2019/10/10.
//
#include <stdio.h>
#include <stdlib.h>

typedef enum  {false,true} statue;

typedef struct List_ADT
{
    int data;
    struct List_ADT * next;
}Node,*Listink;

typedef struct List
{
    Listink Frst,Lst;
    int Length;
}Link;
/*Init Finish*/
void InitList(Link * L)
{
    Listink p = (Listink)malloc(sizeof(Node));
    p->data = 0;
    p->next = NULL;
    L->Frst = p;
    L->Lst = p;
    L->Length = 0;
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
statue GetElem(Link * L,int i,int *e)
{
    if(i > L->Length || i < 1)
        return false;
    Node * p = L->Frst->next;
    int k = 1;
    while(k < i)
    {
        p = p->next;
        k++;
    }
    *e = p->data;
}
/*Locate Finish*/
int LocateElem(Link * L,int e)
{
    Node * p = L->Frst->next;
    int i = 1;
    while(p && p->data != e)
    {
        p = p->next;
        i++;
    }
    if(i > L->Length)
        return -1;
    return i + 1;
}
void PriorElem(Link * L,int e,Node * pre)
{
    Node * p = L->Frst->next;
    Node * q;
    while(p && p->data != e)
    {
        q = p;
        p = p->next;
    }
    if(p && p != L->Frst->next)
        pre = q;
}
void NextElem(Link * L,int e,Node * next)
{
    Node * p = L->Frst->next;
    while(p && p->data != e)
    {
        p = p->next;
    }
    if(p && p != L->Lst)
        next = p->next;
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
/*Insert Finish*/
statue ListInsert(Link * l,int i,int e)
{
    if(i < 1)
        return false;

    if(i > l->Length)
    {
        Listink p = (Listink)malloc(sizeof(Node));
        p->data = e;
        p->next = NULL;
        l->Lst->next = p;
        l->Lst = p;
        l->Length++;
        return true;
    }
    Node * p = l->Frst->next;
    Node * q = l->Frst;
    int k = 1;
    while(p && k != i)
    {
        q = p;
        p = p->next;
        k++;
    }
    Listink new = (Listink)malloc(sizeof(Node));
    new->data = e;
    q->next = new;
    new->next = p;
    l->Length ++;

    return true;
}
/*Delete Finish*/
statue ListDelete(Link * l,int i,int * e)
{
    if(i > l->Length | i < 1)
        return false;

    Node * p = l->Frst->next;
    Node * q = l->Frst;
    int k = 1;
    while(p && k != i)
    {
        q = p;
        p = p->next;
        k++;
    }
    q->next = p->next;
    *e = p->data;
    free(p);
    l->Length --;

    return true;
}
/*add Finish*/
void add(Link * l,int e)
{
    Listink new = (Listink)malloc(sizeof(Node));
    new->data = e;
    new->next = NULL;

    l->Lst->next = new;
    l->Lst = new;
    l->Length++;
}
/*show Finish*/
void showlisk(Link * l)
{
    Listink p = l->Frst->next;
    int k = 1;
    while(p)
    {
        printf("data %d:%d\n",k,p->data);
        p = p->next;
        k++;
    }
    printf("\n");
}
/*Sore*/
statue SORELINK(Link * l)
{
    Listink p = l->Frst->next;
    Listink p_pre = l->Frst;
    if(p)
    {
        for(;p < l->Lst;)
        {
            Listink maxside = NULL;
            Listink maxpre = NULL;
            Listink k = p;
            int max = p->data;
            for(;k < l->Lst;k = k->next)
            {
                if(k->next->data > max)
                {
                    max = k->next->data;
                    maxpre = k;
                }
            }
            if(maxpre)
            {
                maxside = maxpre->next;
                if(maxside->next)
                    maxpre->next = maxside->next;
                else {
                    l->Lst = maxpre;
                    maxpre->next = NULL;
                }
                p_pre->next = maxside;
                maxside->next = p;
                p_pre = maxside;
            }
            else
            {
                p_pre = p;
                p = p->next;
            }
        }
    }
}
int main()
{
    /*link init*/
    Link a;
    InitList(&a);
    for(int i = 0;i < 5;i++)
    {
        int num;
        printf("Enter a number :");
        scanf("%d",&num);
        add(&a,num);
    }
    showlisk((&a));

    SORELINK(&a);
    showlisk(&a);

    SORELINK(&a);
    showlisk(&a);

    getchar();
    getchar();

    return 0;
}
