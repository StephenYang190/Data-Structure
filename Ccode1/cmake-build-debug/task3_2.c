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
    new->next = l->Frst->next;

    l->Lst->next = new;
    l->Lst = new;
    l->Length++;
}
/*show Finish*/
void showlisk(Link * l)
{
    Listink p = l->Frst->next;
    int k = 1;
    statue mode = false;

    while(1)
    {
        if(p == l->Frst->next)
        {
            if(mode)
                break;
            else
                mode = true;
        }

        printf("data %d:%d\n",k,p->data);
        p = p->next;
        k++;
    }
    printf("\n");
}
int main()
{
    int m,n;
    printf("please enter the number n and m: ");
    while(!scanf("%d %d",&n,&m))
    {
        while(getchar() == '\n') continue;
        printf("Again\n");
    }

    Link a;
    InitList(&a);
    int * D = (int *)malloc(sizeof(int) * n);
    for(int i = 0;i < n;i++)
    {
        add(&a,i);
        D[i] = 1;
    }
    showlisk(&a);

    int cout = 0;
    int i = 0;
    int k = 0;
    Listink p = a.Frst->next;
    Listink q;
    while(i < n)
    {
        if(D[k])
        {
            cout++;
        }
        if(!(cout % m) && D[k])
        {
            printf("data %d : %d\n",i,p->data);
            D[k] = 0;
            i++;
        }
        p = p->next;
        k++;
        k = k % a.Length;
    }

    return 0;
}