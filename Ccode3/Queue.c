#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

/*Init Finish*/
void InitQueue(Queue * q)
{
    q->front = NULL;
    q->rear = NULL;
}
/*Empty Finish*/
statue QueueEmpty(Queue q)
{
    if(q.rear == NULL)
        return true;
    return false;
}
void DestroyQueue(Queue * q)
{
    QueueNode p = q->front;
    while(p)
    {
        QueueNode m = p->next;
        free(p);
        p = m;
    }
    q->rear = NULL;
    q->front = NULL;
}
int QueueLength(Queue q)
{
    int i = 0;
    QueueNode p = q.front;
    while(p)
    {
        i++;
        p = p->next;
    }

    return i;
}
statue GetHead(Queue * q,int *e)
{
    if(q->front)
    {
        *e = q->front->x;
        return true;
    }
    else
        return false;

}
void ClearQueue(Queue * q)
{
    QueueNode p = q->front;
    while(p)
    {
        QueueNode m = p->next;
        free(p);
        p = m;
    }
    q->rear = NULL;
    q->front = NULL;
}
statue EnQueue(Queue * q,int e)
{
    QueueNode p = (QueueNode)malloc(sizeof(Node));
    if(!p)
        return false;

    p->x = e;
    p->next = NULL;
    if(q->rear == NULL)
    {
        q->front = p;
    }
    else
    {
        if(q->rear)
            q->rear->next = p;
    }

    q->rear = p;

    return true;
}
statue DeQueue(Queue * q,int *e)
{
    if(q->front)
    {
        if(q->front == q->rear)
        {
            q->rear = NULL;
        }
        *e = q->front->x;
        QueueNode p = q->front;
        q->front = p->next;
        free(p);
    }
    else
        return false;
}
/*Traverse Finish*/
statue QueueTraverse(Queue q)
{
    QueueNode p = q.front;
    int k = 1;
    while(p)
    {
        printf("x %d:%d\n",k,p->x);
        p = p->next;
        k++;
    }
    printf("\n");
}
