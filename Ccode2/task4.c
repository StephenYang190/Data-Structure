//
// Created by HP on 2019/10/11.
//
#include <stdio.h>
#include <stdlib.h>

typedef enum  {false,true} statue;

typedef struct List_ADT
{
    int time_ar;
    int time_le;
    struct List_ADT * next;
}Node,*Listink;

typedef struct List
{
    Listink Frst,Lst;
    int Length;
}Link;

void add(Link * l);

/*Init Finish*/
void InitList(Link * L,int n)
{
    Listink p = (Listink)malloc(sizeof(Node));
    p->time_ar = 0;
    p->time_le = 0;
    p->next = NULL;
    L->Frst = p;
    L->Lst = p;
    L->Length = 0;
    for(int i = 0;i < n;i++)
    {
        add(L);
    }
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
    *e = p->time_ar;
}
/*Locate Finish*/
int LocateElem(Link * L,int e)
{
    Node * p = L->Frst->next;
    int i = 1;
    while(p && p->time_ar != e)
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
    while(p && p->time_ar != e)
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
    while(p && p->time_ar != e)
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
statue ListInsert(Link * l,int i)
{
    if(i < 1)
        return false;

    int e1,e2;
    scanf("%d %d",&e1,&e2);
    if(i > l->Length)
    {

        Listink p = (Listink)malloc(sizeof(Node));
        p->time_ar = e1;
        p->time_le = e2;
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
    new->time_ar = e1;
    new->time_le = e2;
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
    *e = p->time_ar;
    free(p);
    l->Length --;

    return true;
}
/*add Finish*/
void add(Link * l)
{
    int e1,e2;
    scanf("%d %d",&e1,&e2);
    Listink new = (Listink)malloc(sizeof(Node));
    new->time_ar = e1;
    new->time_le = e2;
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
        printf("time%d:(%d,%d)\n",k,p->time_ar,p->time_le);
        p = p->next;
        k++;
    }
    printf("\n");
}
/*Sore Finish*/
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
            int max = p->time_ar;
            for(;k < l->Lst;k = k->next)
            {
                if(k->next->time_ar > max)
                {
                    max = k->next->time_ar;
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
void fixlink(int * a,Link b)
{
    Listink p = b.Frst->next;
    while(p)
    {
        for(int i = p->time_ar;i < p->time_le;i++)
        {
            a[i] = 1;
        }
        p = p->next;
    }
}
/*Compare*/
int Compare(Link a,Link b)
{
    int sum = 0;
    int *pa = (int *)malloc(sizeof(int)*a.Lst->time_le);
    int *pb = (int *)malloc(sizeof(int)*b.Lst->time_le);
    for(int i = 0;i < a.Lst->time_le;i++)
    {
        pa[i] = 0;
    }
    fixlink(pa,a);
    for(int i = 0;i < b.Lst->time_le;i++)
    {
        pb[i] = 0;
    }
    fixlink(pb,b);

    int lsttme = (a.Lst->time_le < b.Lst->time_le) ? a.Lst->time_le : b.Lst->time_le;
    for(int i = 0;i < lsttme;i++)
    {
        if(pa[i] && pb[i])
        {
            sum++;
        }
    }


    /*if(p->time_ar < q->time_ar)
    {
        if(p->time_le >= q->time_le)
        {
            sum += p->time_le - p->time_ar;
            q = q->next;
        }
        else
        {
            if(p->time_le <= q->time_ar)
            {
                p = p->next;
                continue;
            }
            else
            {
                sum += p->time_le - q->time_ar;
                p = p->next;
            }
        }
    }
    else if(p->time_ar > q->time_ar)
    {
        if(q->time_le >= p->time_le)
        {
            sum += q->time_le - q->time_ar;
            p = p->next;
        }
        else
        {
            if(q->time_le <= p->time_ar)
            {
                q = q->next;
                continue;
            }
            else
            {
                sum += q->time_le - p->time_ar;
                q = q->next;
            }
        }
    }
    else
    {
        if(q->time_le > p->time_le)
        {
            sum += p->time_le - p->time_ar;
            p = p->next;
        }
        else
        {
            sum += q->time_le - q->time_le;
            q = q->next;
        }
    }*/

    return sum;
}
int main()
{
    /*link init*/
    int n;
    scanf("%d",&n);
    Link a;
    InitList(&a,n);
    Link b;
    InitList(&b,n);

    int time = Compare(a,b);
    printf("%d",time);


    getchar();
    getchar();

    return 0;
}
