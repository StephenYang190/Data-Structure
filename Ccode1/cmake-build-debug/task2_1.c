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
void SortLisk(Link * l)
{
    int i = 0,k = l->nowside - 1;
    for(;i < k;i++,k--)
    {
        int roo;
        roo = l->Frst[i].data;
        l->Frst[i].data = l->Frst[k].data;
        l->Frst[k].data = roo;
    }

}
int main()
{
    /*link init*/
    Link a;
    InitList(&a);
    for(int i = 0;i < 0;i++)
    {
        add(&a,i);
    }
    showlisk(&a);

    SortLisk((&a));
    showlisk((&a));

    return 0;
}