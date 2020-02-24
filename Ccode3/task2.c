//
// Created by HP on 2019/10/19.
//
#include <stdlib.h>
#include <stdio.h>
#include "Queue.h"

int main()
{
    Queue q;
    InitQueue(&q);

    if(QueueEmpty(q))
        printf("1\n");
    else
        printf("0\n");

    for(int i = 0;i < 5;i++)
    {
        EnQueue(&q,i);
    }
    QueueTraverse(q);

    int n;
    for(int i = 0;i < 2;i++)
         DeQueue(&q,&n);

    printf("%d\n",n);
    QueueTraverse(q);

    n = QueueLength(q);
    printf("%d\n",n);

    GetHead(&q,&n);
    printf("%d\n",n);

    return 0;
}
