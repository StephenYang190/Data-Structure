#include <stdio.h>
#include <stdlib.h>
#include "SequenceLink.h"

/*Init Finish*/
void InitSeQuence(Sequence * L)
{
    SeQuenceNode p = (SeQuenceNode)malloc(sizeof(Node) * INIT_LONG);
    L->Frst = p;
    L->Length = 20;
    for(int i = 0;i < L->Length;i++)
    {
        L->Frst[i].data = 0;
        L->Frst[i].fn = NULL;
    }
}
/*Empty Finis*/
statue SeQuenceEmpty(Sequence * L)
{
    int i = 0;
    for(;i < L->Length;i++)
    {
        if(L->Frst[i].data > 0)
            break;
    }
    if(i < L->Length)
        return false;
    return true;
}
void DestroySeQuence(Sequence * L)
{
    if(!SeQuenceEmpty(L))
    {
        for(int i = 0;i < L->Length;i++)
        {
            SitePoint p = L->Frst[i].fn;
            while(p)
            {
                SitePoint q = p->next;
                free(p);
                p = q;
            }
        }
        free(L->Frst);
    }
    L->Frst = NULL;
    L->Length = 0;
}
int SeQuenceLength(Sequence * L)
{
    return L->Length;
}

/*Clear Finish*/
void ClearSeQuence(Sequence * L)
{
    if(!SeQuenceEmpty(L))
    {
        for(int i = 0;i < L->Length;i++)
        {
            SitePoint p = L->Frst[i].fn;
            while(p)
            {
                SitePoint q = p->next;
                free(p);
                p = q;
            }
            L->Frst[i].data = 0;
        }
    }
}
/*add Finish*/
statue add(Sequence * l,int e)
{
    int i = 0;
    for(;i < l->Length;i++)
    {
        if(l->Frst[i].data + e < 6)
            break;
    }
    if(i < l->Length)
    {
        for(int k = 0;k < e;k++)
        {
            SitePoint p = (SitePoint)malloc(sizeof(Site));
            p->site =k + l->Frst[i].data + 1 + i * 5;
            printf("%d ",p->site);
            p->next = l->Frst[i].fn;
            l->Frst[i].fn = p;
        }
        l->Frst[i].data += e;
    }
    else
    {
        i = 0;
        while(1)
        {
            if(e == 0)
                break;
            if(i == l->Length)
                return false;
            if(l->Frst[i].data < 5)
            {
                for(int k = l->Frst[i].data;k < 5;k++)
                {
                    SitePoint p = (SitePoint)malloc(sizeof(Site));
                    p->site =k + l->Frst[i].data + 1 + i * 5;
                    printf("%d ",p->site);
                    p->next = l->Frst[i].fn;
                    l->Frst[i].fn = p->next;
                    e--;
                    l->Frst[i].data ++;
                }
            }
            i++;
        }
    }

    printf("\n");
    return true;
}
/*show Finish*/
void showlisk(Sequence * l)
{
    for(int i = 0;i < l->Length;i++)
    {
        printf("Row %d :",i);
        SitePoint p = l->Frst[i].fn;
        if(!p)
        {
            printf("None");
        }
        else
        {
            while(p)
            {
                printf("%d ",p->site);
                p = p->next;
            }
        }

        printf("\n");
    }
    printf("\n");
}
