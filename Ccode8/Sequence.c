#include <stdio.h>
#include <stdlib.h>
#include "Sequence.h"

/*Init Finish*/
void InitSeQuence(Sequence * L)
{
    PointSeNode p = (PointSeNode)malloc(sizeof(SeNode) * INIT_LONG);
    L->Frst = p;
    L->Length = 10;
    L->nowside = 0;
}
/*Empty Finis*/
statue SeQuenceEmpty(Sequence * L)
{
    if(L->nowside == 0)
        return true;
    return false;
}
void DestroySeQuence(Sequence * L)
{
    if(!SeQuenceEmpty(L))
    {
        free(L->Frst);
    }
    L->Frst = NULL;
    L->nowside = 0;
}
int SeQuenceLength(Sequence * L)
{
    return L->Length;
}
///*Get Finish*/
statue GetElem(Sequence * L,int i,int *e)
{
    if(i > L->nowside || i < 1)
        return false;
    *e = L->Frst[i - 1].data;
}
///*Locate Finish*/
int LocateElem(Sequence * L,int e)
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
statue PriorElem(Sequence* L,int e,int * pre)
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
statue NextElem(Sequence * L,int e,int * next)
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
/*Clear Finish*/
void ClearSeQuence(Sequence * L)
{
    if(!SeQuenceEmpty(L))
    {
        L->nowside = 0;
    }
}
/*Insert Finish*/
statue SeQuenceInsert(Sequence * l,int i,int e)
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
        PointSeNode p = (PointSeNode)realloc(l->Frst,
                sizeof(SeNode)*(ADD_LONG + l->Length));
        l->Length += ADD_LONG;
    }

    return true;
}
/*Delete Finish*/
statue SeQuenceDelete(Sequence * l,int i,int * e)
{
    if(i > l->nowside || i < 1)
        return false;

    if(e)
        *e = l->Frst[i - 1].data;
    for(int k = i - 1;k < l->nowside;k++)
    {
        l->Frst[k].data = l->Frst[k + 1].data;
    }
    l->nowside --;

    return true;
}
/*add Finish*/
void SequenceAdd(Sequence * l,int e)
{
    l->Frst[l->nowside].data = e;
    l->nowside++;
    if(l->nowside == l->Length)
    {
        PointSeNode p = (PointSeNode)realloc(l->Frst,
                                     sizeof(SeNode)*(ADD_LONG + l->Length));
        l->Frst = p;
        l->Length += ADD_LONG;
    }

}
/*show Finish*/
void SequenceShow(Sequence * l)
{
    for(int i = 0;i < l->nowside;i++)
    {
        printf("data %d : %d \n",i,l->Frst[i].data);
    }
    printf("\n");
}
