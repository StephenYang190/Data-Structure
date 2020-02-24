#include <stdio.h>
#include <stdlib.h>

#define INIT_LONG 10
#define ADD_LONG 5
typedef enum  {false,true} statue;

typedef struct List_ADT
{
    int time_ar;
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
/*Empty Finis*/
statue ListEmpty(Link * L)
{
    if(L->nowside == 0)
        return true;
    return false;
}
void DestroyList(Link * L)
{
    if(!ListEmpty(L))
    {
        free(L->Frst);
    }
    L->Frst = NULL;
    L->nowside = 0;
}
int ListLength(Link * L)
{
    return L->Length;
}
///*Get Finish*/
statue GetElem(Link * L,int i,int *e)
{
    if(i > L->nowside || i < 1)
        return false;
    *e = L->Frst[i - 1].time_ar;
}
///*Locate Finish*/
int LocateElem(Link * L,int e)
{
    int i = 0;
    while(i < L->nowside && L->Frst[i].time_ar != e)
    {
        i++;
    }
    if(i == L->nowside)
        return -1;
    return i + 1;
}
statue PriorElem(Link * L,int e,int * pre)
{
    int i = 0;
    while(i < L->nowside && L->Frst[i].time_ar != e)
    {
        i++;
    }
    if(i == L->nowside) return false;
    *pre = L->Frst[i - 1].time_ar;
    return true;
}
statue NextElem(Link * L,int e,int * next)
{
    int i = 0;
    while(i < L->nowside && L->Frst[i].time_ar != e)
    {
        i++;
    }
    if(i >= L->nowside - 1) return false;
    *next = L->Frst[i + 1].time_ar;
    return true;
}
///*Clear Finish*/
void ClearList(Link * L)
{
    if(!ListEmpty(L))
    {
        L->nowside = 0;
    }
}
/*Insert Finish*/
statue ListInsert(Link * l,int i,int e)
{
    if(i < 1 || i > l->nowside)
        return false;

    for(int k = l->nowside - 1;k >= (i - 1);k--)
    {
        l->Frst[k + 1].time_ar = l->Frst[k].time_ar;
    }

    l->Frst[i - 1].time_ar = e;
    l->nowside++;

    if(l->nowside == l->Length)
    {
        Listink p = (Listink)realloc(l->Frst,
                                     sizeof(Node)*(ADD_LONG + l->Length));
        l->Length += ADD_LONG;
    }

    return true;
}
/*Delete Finish*/
statue ListDelete(Link * l,int i,int * e)
{
    if(i > l->nowside || i < 1)
        return false;

    for(int k = i - 1;k < l->nowside;k++)
    {
        l->Frst[k].time_ar = l->Frst[k + 1].time_ar;
    }
    l->nowside --;

    return true;
}
/*add Finish*/
void add(Link * l,int e)
{
    l->Frst[l->nowside].time_ar = e;
    l->nowside++;
}
/*show Finish*/
void showlisk(Link * l)
{
    for(int i = 0;i < l->nowside;i++)
    {
        printf("time_ar %d : %d \n",i,l->Frst[i]);
    }
    printf("\n");
}
/*Sore Finish*/
statue sorelisk(Link * l)
{
    if(!l->nowside) return false;

    Listink p = l->Frst;
    for(int i = 0;i < l->nowside - 1;i++){
        int max = p[i].time_ar;
        int k = 0;
        for(int j = i + 1;j < l->nowside;j++){

            if(p[j].time_ar > max) {
                max = p[j].time_ar;
                k = j;
            }
        }
        if(k){
            p[k].time_ar = p[i].time_ar;
            p[i].time_ar = max;
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
        printf("Enter number :");
        scanf("%d",&num);
        add(&a,num);
    }
    showlisk(&a);

    sorelisk(&a);
    showlisk((&a));

    getchar();
    getchar();

    return 0;
}