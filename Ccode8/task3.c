//
// Created by 97927 on 2019/12/10.
//
#include <stdio.h>
#include <stdlib.h>
#include "Sequence.h"

int fastSort(Sequence * sq,int bin,int end)
{
    if((end - bin) <= 1)
    {
        if(bin >= end)
            return 0;
        if(sq->Frst[bin].data < sq->Frst[end].data)
        {
            int pause = sq->Frst[bin].data;
            sq->Frst[bin].data = sq->Frst[end].data;
            sq->Frst[end].data = pause;
        }
        return 0;
    }
    int pause;
    SeQuenceDelete(sq,bin + 1,&pause);
    int i = bin;
    int k = end - 1;
    while(1)
    {
        if(i >= k)
        {
            if(sq->Frst[i].data <= pause)
            {
                i--;
                k = i;
            } else{
                k++;
                i = k;
            }
            SeQuenceInsert(sq,k + 1,pause);
            break;
        }
        if(sq->Frst[k].data < pause)
        {
            k--;
            continue;
        }
        if(sq->Frst[i].data < pause)
        {
            int data = sq->Frst[k].data;
            sq->Frst[k].data = sq->Frst[i].data;
            sq->Frst[i].data = data;
            k--;
            i++;
        } else{
            i++;
            continue;
        }
    }
    fastSort(sq,bin,k - 1);
    fastSort(sq,k + 1,end);

    return 0;
}

int main()
{
    Sequence sq;
    InitSeQuence(&sq);
    int times;
    scanf("%d",&times);
    int num[5] = {2,3,1,4,5};
    for(int i = 0;i < times;i++)
    {
        /*int num;
        scanf("%d",&num);*/
        SequenceAdd(&sq,num[i]);
    }
    SequenceShow(&sq);
    fastSort(&sq,0,sq.nowside - 1);
    SequenceShow(&sq);

    return 0;

}
