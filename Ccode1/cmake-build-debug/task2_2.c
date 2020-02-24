//
// Created by HP on 2019/9/23.
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
    Listink Frst,Lst;//frst 头节点
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
statue SortLisk(Link * l)
{
    if(l->Length < 1)
        return false;

    Listink q , p ;
    p = l->Frst->next->next;
    l->Frst->next->next = NULL;
    while(p)
    {
        q = p->next;
        p->next = l->Frst->next;
        l->Frst->next = p;
        p = q;
    }
}
int main()
{
    /*link init*/
    Link a;
    InitList(&a);
    for(int i = 0;i < 1;i++)
    {
        add(&a,i);
    }
    showlisk((&a));

    SortLisk(&a);
    showlisk(&a);

    return 0;
}