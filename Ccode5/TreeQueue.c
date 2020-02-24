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
statue GetHead(Queue * q,PointNode * p)
{
    if(q->front)
    {
        *p = q->front->t;
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
statue EnQueue(Queue * q,PointNode t,int n)
{
    QueueNode p = (QueueNode)malloc(sizeof(Node));
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
statue DeQueue(Queue * q,PointNode * t,int * e)
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

