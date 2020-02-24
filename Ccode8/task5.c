//
// Created by 97927 on 2019/12/11.
//
#include <stdlib.h>
#include <stdio.h>
#include "Sequence.h"
#define YTD
int maxNumber(Sequence sq)
{
    int max = sq.Frst[0].data;
    for(int i = 0;i < sq.nowside;i++)
    {
        if(sq.Frst[i].data > max)
        {
            max = sq.Frst[i].data;
        }
    }
    return max;
}
int maxNumber1(const int * sq,int n)
{
    int max = -1;
    int site = -1;
    for(int i = 0;i < n;i++)
    {
        if(!sq[i])
            continue;
        if(max == -1 || sq[i] > max)
        {
            max = sq[i];
            site = i;
        }
    }
    return site;
}
void courtNumber(Sequence sq)
{
    int * D = (int *)malloc(sizeof(int) * sq.nowside);
    for(int i = 0;i < sq.nowside;i++)
    {
        D[i] = 0;
    }
    for(int i = 0;i < sq.nowside;i++)
    {
        D[sq.Frst[i].data - 1]++;
    }
#ifndef YTD
    for(int i = 0;i < sq.nowside;i++)
    {
        printf("D[%d] : %d\n",i,D[i]);
    }
#endif
    int k;
    while((k = maxNumber1(D,sq.nowside)) >= 0)
    {
        printf("%d times : %d\n",k + 1,D[k]);
        D[k] = 0;
    }
}
int main()
{
    Sequence sq;
    InitSeQuence(&sq);
    int times;
    scanf("%d",&times);
#ifndef YTD
    int num[12] = {5,2,3,3,1,3,4,2,5,2,3,5};
#endif
    for(int i = 0;i < times;i++)
    {
#ifdef YTD
        int num;
        scanf("%d",&num);
        SequenceAdd(&sq,num);
#endif
#ifndef YTD
        SequenceAdd(&sq,num[i]);
#endif
    }
    SequenceShow(&sq);
    courtNumber(sq);

    return 0;
}