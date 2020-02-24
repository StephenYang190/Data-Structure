//
// Created by HP on 2019/10/18.
//

#ifndef CCODE3_QUEUE_H
#define CCODE3_QUEUE_H

/*ADT*/
#include "BinaryTree.h"

typedef struct List_ADT
{
    PointNode t;
    int n;
    struct List_ADT * next;
}qNode,*QueueNode;

typedef struct
{
    QueueNode front,rear;
}Queue;

/*operate*/

/*Init Finish*/
void InitQueue(Queue * q);
/*Empty Finis*/
statue QueueEmpty(Queue q);
void DestroyQueue(Queue * q);
/*Length Finish*/
int QueueLength(Queue q);
/*Get Finish*/
statue GetHead(Queue * q,PointNode * p);

void ClearQueue(Queue * q);/*Clear Finish*/
/*En Finsh*/
statue EnQueue(Queue * q,PointNode t,int n);
/*De Finish*/
statue DeQueue(Queue * q,PointNode * t,int * e);

#endif //CCODE3_QUEUE_H
