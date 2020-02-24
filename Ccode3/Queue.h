//
// Created by HP on 2019/10/18.
//

#ifndef CCODE3_QUEUE_H
#define CCODE3_QUEUE_H

/*ADT*/
typedef enum  {false,true} statue;

typedef struct SeQuence_ADT
{
    int x;
    struct SeQuence_ADT * next;
}Node,*QueueNode;

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
statue GetHead(Queue * q,int *e);

void ClearQueue(Queue * q);/*Clear Finish*/
/*En Finsh*/
statue EnQueue(Queue * q,int e);
/*De Finish*/
statue DeQueue(Queue * q,int *e);
/*Traverse Finsh*/
statue QueueTraverse(Queue q);
#endif //CCODE3_QUEUE_H
