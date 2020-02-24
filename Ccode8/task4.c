
//
// Created by 97927 on 2019/12/11.
//
#include "Sequence.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void swap(int *num1,int * num2)
{
    int pause = *num1;
    *num1 = *num2;
    *num2 = pause;
}
int maxHeap(Sequence *sq,int bin)
{
    int end1 =  2 * bin + 1;
    if(end1 >= sq->nowside)
    {
        return -1;
    }
    if(end1 + 1 < sq->nowside && sq->Frst[end1].data < sq->Frst[end1 + 1].data)
    {
        end1++;
    }
    if(sq->Frst[end1].data > sq->Frst[bin].data)
    {
        swap(&sq->Frst[end1].data,&sq->Frst[bin].data);
        return end1;
    }
    return -1;
}
bool heapSort(Sequence * sq)
{
    Sequence sort_sq;
    InitSeQuence(&sort_sq);
    int i = (int)(sq->nowside / 2);
    while(i >= 0)
    {
        int k;
        k = maxHeap(sq, i);
        while(k > 0)
        {
            maxHeap(sq,k);
            k = maxHeap(sq, i);
        }
        i--;
        SequenceShow(sq);
    }
    while(1)
    {
        int pause = sq->Frst[0].data;
        swap(&sq->Frst[0].data,&sq->Frst[sq->nowside - 1].data);
        SeQuenceDelete(sq,sq->nowside,NULL);
        SequenceAdd(&sort_sq,pause);
        if(SeQuenceEmpty(sq))
            break;
        int k = maxHeap(sq,0);
        while(k > 0)
        {
            k = maxHeap(sq,k);
        }
        SequenceShow(sq);
        SequenceShow(&sort_sq);
    }

    SequenceShow(&sort_sq);
}

int main()
{
    Sequence sq;
    InitSeQuence(&sq);
    int times;
    scanf("%d",&times);
    for(int i = 0;i < times;i++)
    {
        int num;
        scanf("%d",&num);
        SequenceAdd(&sq,num);
    }
    SequenceShow(&sq);
    heapSort(&sq);

    return 0;
}