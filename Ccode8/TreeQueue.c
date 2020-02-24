#include <stdio.h>
#include <stdlib.h>
#include "TreeQueue.h"

/*Init Finish*/
void InitTQueue(Queue * q)
{
    q->front = NULL;
    q->rear = NULL;
}
/*Empty Finish*/
statue TQueueEmpty(Queue q)
{
    if(q.rear == NULL)
        return true;
    return false;
}
void DestroyTQueue(Queue * q)
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
int TQueueLength(Queue q)
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
statue TGetHead(Queue * q,PointTree * p)
{
    if(q->front)
    {
        *p = q->front->t;
        return true;
    }
    else
        return false;

}
void TClearQueue(Queue * q)
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
statue EnTQueue(Queue * q,PointTree t,int n)
{
    QueueNode p = (QueueNode)malloc(sizeof(qNode));
    if(!p)
        return false;

    p->t = t;
    p->n = n;
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
statue DeTQueue(Queue * q,PointTree * t,int * e)
{
    if(q->front)
    {
        if(q->front == q->rear)
        {
            q->rear = NULL;
        }
        *t = q->front->t;
        QueueNode p = q->front;
        q->front = p->next;
        *e = p->n;
        free(p);
    }
    else
        return false;
}

