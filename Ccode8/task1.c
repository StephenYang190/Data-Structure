//
// Created by 97927 on 2019/12/8.
//
#include <stdlib.h>
#include <stdio.h>
#include "Sequence.h"
#include "Queue.h"
void bubbleSort(Sequence * sq)
{
    int times = sq->nowside;
    for(int i = 0;i < times;i++)
    {
        for(int j = times;j > i;j--)
        {
            if(sq->Frst[j].data > sq->Frst[j - 1].data)
            {
                int pause = sq->Frst[j].data;
                sq->Frst[j].data = sq->Frst[j - 1].data;
                sq->Frst[j - 1].data = pause;
            }
        }
    }
    printf("Bubble Sort Finish.\n");
}
void selectionSort(Sequence * sq)
{
    int times = sq->nowside;
    int max;
    int max_site;
    for(int i = 0;i < times;i++)
    {
        max = sq->Frst[i].data;
        for(int j = i + 1;j < times;j++)
        {
            if(sq->Frst[j].data >max)
            {
                max = sq->Frst[j].data;
                max_site = j;
            }
        }
        sq->Frst[max_site].data = sq->Frst[i].data;
        sq->Frst[i].data = max;
    }
    printf("Selection Sort Finish.\n");
}
void collectionSort(Sequence * sq,int a1,int a2,int b1,int b2)
{
    if(b1 < a1)
    {
        int pause = b1;
        b1 = a1;
        a1 = pause;
        pause = b2;
        b2 = a2;
        a2 = pause;
    }
    while(1)
    {
        if(a1 > a2 || b1 > b2)
            break;
        if(sq->Frst[a1].data >= sq->Frst[b1].data)
        {
            a1++;
        }
        else{
            int pause;
            SeQuenceDelete(sq,b1 + 1,&pause);
            SeQuenceInsert(sq,a1 + 1,pause);
            b1++;
        }
    }
}
void mergeSort(Sequence * sq)
{
    int length = sq->nowside;
    Queue q;
    InitQueue(&q);
    for(int i = 0;i < length;i += 2)
    {
        if(i + 1 == length)
        {
            EnQueue(&q,i);
            EnQueue(&q,i);
            break;
        }
        if(sq->Frst[i].data < sq->Frst[i + 1].data)
        {
            int pause = sq->Frst[i].data;
            sq->Frst[i].data = sq->Frst[i + 1].data;
            sq->Frst[i + 1].data = pause;
        }
        EnQueue(&q,i);
        EnQueue(&q,i + 1);
        SequenceShow(sq);
    }
    while(QueueLength(q) > 2)
    {
        int a1,a2,b1,b2;
        DeQueue(&q,&a1);
        DeQueue(&q,&a2);
        DeQueue(&q,&b1);
        DeQueue(&q,&b2);
        collectionSort(sq,a1,a2,b1,b2);
        EnQueue(&q,a1);
        EnQueue(&q,b2);
        SequenceShow(sq);
    }
    printf("Merge Sort Finish.\n");
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
    mergeSort(&sq);
    SequenceShow(&sq);

    return 0;
}