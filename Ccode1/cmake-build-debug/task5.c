//
// Created by HP on 2019/9/26.
//

#include <stdio.h>
#include <stdlib.h>

typedef enum  {false,true} statue;

typedef struct List_ADT
{
    int data;
    struct List_ADT * next;
    struct List_ADT * prior;
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
    p->prior = NULL;
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
    new->prior = l->Lst;
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
statue MoveQuen(Link * l,int num,int dr) {
    int i = 1;
    Listink p = l->Frst->next;
    while (p->data != num && p) {
        p = p->next;
        i++;
    }
    if (i > l->Length) {
        return false;
    }
    if ((i + dr) > l->Length || (i + dr) < 1) {
        return false;
    }
    Listink q, r, w;
    q = p;
//
    if (dr > 0)
    {
        for (int k = 0; k < dr; k++)
        {
            q = q->next;
        }
    }
    else
    {
        q = q->prior;
        for(int k = 0;k < abs(dr);k++)
        {
            q = q->prior;
        }
    }
    r = p->next;
    w = p->prior;
    if(r)
    {
        r->prior = w;
    }
    if(w)
    {
        w->next = r;
    }
    p->next = q->next;
    p->prior = q;
    q->next = p;
    if(p->next) p->next->prior = p;
}
int main()
{
    Link a;
    InitList(&a);
    int n;
    printf("students number :");
    scanf("%d",&n);

    for(int i = 0;i < n;i++)
    {
        add(&a,i + 1);
    }
    showlisk(&a);

    int m;
    printf("how many times do you want to ad?");
    scanf("%d",&m);
    for(int i = 0;i < m;i++)
    {
        int po,dr;
        printf("people and dirction : ");
        scanf("%d %d",&po,&dr);
        MoveQuen(&a,po,dr);
        showlisk(&a);
    }

    return 0;
}