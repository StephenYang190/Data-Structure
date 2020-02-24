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
    *e = L->Frst[i - 1].data;
}
///*Locate Finish*/
int LocateElem(Link * L,int e)
{
    int i = 0;
    while(i < L->nowside && L->Frst[i].data != e)
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
    while(i < L->nowside && L->Frst[i].data != e)
    {
        i++;
    }
    if(i == L->nowside) return false;
    *pre = L->Frst[i - 1].data;
    return true;
}
statue NextElem(Link * L,int e,int * next)
{
    int i = 0;
    while(i < L->nowside && L->Frst[i].data != e)
    {
        i++;
    }
    if(i >= L->nowside - 1) return false;
    *next = L->Frst[i + 1].data;
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
        l->Frst[k + 1].data = l->Frst[k].data;
    }

    l->Frst[i - 1].data = e;
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
        l->Frst[k].data = l->Frst[k + 1].data;
    }
    l->nowside --;

    return true;
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
int main()
{
    /*link init*/
    Link a;
    InitList(&a);
    for(int i = 0;i < 5;i++)
    {
        add(&a,i);
    }
    showlisk(&a);

    /*insert test*/
    ListInsert(&a,1,5);
    ListInsert(&a,5,15);
    ListInsert(&a,10,10);
    showlisk(&a);
    printf("Insert Finish\n");

    /*delete test*/
//    int E;
//    ListDelete(&a,5,&E);
//    ListDelete(&a,1,&E);
//    ListDelete(&a,10,&E);
//    showlisk(&a);
//    printf("Delete finish\n");

//    /*Clear test*/
//    ClearList(&a);
//    showlisk(&a);

    /*locate test*/
//    int num = LocateElem(&a,15);

    /*Get test*/
    int num;
    GetElem(&a,5,&num);
    printf("%d\n",num);
//    getchar();
//    getchar();

    if(ListEmpty(&a)) printf("1");
    else printf("0");
    printf("\n");
    printf("length %d,now %d\n",a.Length,a.nowside);

    getchar();
    getchar();

    return 0;
}