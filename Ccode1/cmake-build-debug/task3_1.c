//
// Created by HP on 2019/9/23.
//
#include <stdio.h>
#include <stdlib.h>

#define INIT_LONG 10
#define ADD_LONG 5
typedef enum  {false,true} statue;

typedef struct List_ADT
{
    int data;
}Node,*Listink;

typedef struct List
{
    Listink Frst;
    int Length;
    int nowside;
}Link;
/*Init Finish*/
void InitList(Link * L)
{
    Listink p = (Listink)malloc(sizeof(Node) * INIT_LONG);
    L->Frst = p;
    L->Length = 10;
    L->nowside = 0;
}
/*add Finish*/
void add(Link * l,int e)
{
    l->Frst[l->nowside].data = e;
    l->nowside++;

    if(l->nowside == l->Length)
    {
        Listink p = (Listink)malloc(sizeof(Node)*(ADD_LONG + l->Length));
        for(int i = 0;i < l->nowside;i++)
        {
            p[i].data = l->Frst[i].data;
        }
        free(l->Frst);
        l->Frst = p;
//realloc bug : num was changed
//        Listink p = (Listink)realloc(l->Frst,
//                                     sizeof(Node)*(ADD_LONG + l->Length));
        l->Length += ADD_LONG;
    }
}
/*show Finish*/
void showlisk(Link * l)
{
    for(int i = 0;i < l->nowside;i++)
    {
        printf("data %d : %d \n",i,l->Frst[i]);
    }
    printf("\n");
}
int main()
{
    int m,n;
    printf("please enter n m: ");
    while(!scanf("%d %d",&n,&m))
    {
        while(getchar() == '\n') continue;
        printf("again\n");
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

    int i = 0;
    int k = 0;
    int cout = 1;
    while(i < n)
    {
        if(!(cout % m) && D[k])
        {
            printf("data %d : %d\n", i, a.Frst[k]);
            D[k] = 0;
            i++;
        }
        k++;
        if(k == n) k = 0;
        if(D[k]) cout++;
    }

    return 0;
}