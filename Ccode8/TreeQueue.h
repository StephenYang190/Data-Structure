//
// Created by HP on 2019/10/18.
//

#ifndef CCODE3_QUEUE_H
#define CCODE3_QUEUE_H

/*ADT*/
#include "BinaryTree.h"

typedef struct List_ADT
{
    PointTree t;
    int n;
    struct List_ADT * next;
}qNode,*QueueNode;

typedef struct
{
    QueueNode front,rear;
}Queue,*PointQueue;

/*operate*/

/*Init Finish*/
void InitTQueue(Queue * q);
/*Empty Finis*/
statue TQueueEmpty(Queue q);
void DestroyTQueue(Queue * q);
/*Length Finish*/
int TQueueLength(Queue q);
/*Get Finish*/
statue TGetHead(Queue * q,PointTree * p);
/*Clear Finish*/
void TClearQueue(Queue * q);
/*En Finsh*/
statue EnTQueue(Queue * q,PointTree t,int n);
/*De Finish*/
statue DeTQueue(Queue * q,PointTree * t,int * e);

#endif //CCODE3_QUEUE_H
