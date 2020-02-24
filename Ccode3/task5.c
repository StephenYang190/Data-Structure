//
// Created by HP on 2019/10/25.
//
#include <stdlib.h>
#include <stdio.h>
#include "Link.h"

int LocateLable(Link *l,int x,int y)
{
    int x1,x2,y1,y2;
    Listink p = l->Frst->next;
    while(1)
    {
        if(!p)
            break;
        x1 = p->x1;
        x2 = p->x2;
        y1 = p->y1;
        y2 = p->y2;
        if(x >= x1 && x <= x2 && y >= y1 && y <= y2)
            break;
        p = p->next;
    }

    if(!p)
        return -1;
    Node * q = NULL;
    q = PriorElem(l,p->sign);
    q->next = p->next;
    p->next = l->Frst->next;
    l->Frst->next = p;

    return p->sign;
}
int main()
{
    Link a;
    InitList(&a);

    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0;i < n;i++)
    {
        int x1,x2,y1,y2;
        scanf("%d",&x1);
        scanf("%d",&y1);
        scanf("%d",&x2);
        scanf("%d",&y2);
        add(&a,x1,y1,x2,y2);
    }
    showlisk(&a);
    for(int i = 0;i < m;i++)
    {
        int x,y;
        scanf("%d",&x);
        scanf("%d",&y);
        int sit = LocateLable(&a,x,y);
        if(sit == -1)
            printf("IGNORED\n");
        else
            printf("%d\n",sit);
    }
    return 0;
}
