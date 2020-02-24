//
// Created by HP on 2019/10/18.
//

#ifndef CCODE2_SEQUENCE_H
#define CCODE2_SEQUENCE_H

#define INIT_LONG 10
#define ADD_LONG 5

#include "BinaryTree.h"


/*ADT*/
typedef struct
{
    PointNode t;
    int flag;
}SNode,*StackNode;

typedef struct Stack
{
    StackNode Frst;
    int top,base;
    int length;
}Stack;

/*operate*/

/*Init Finish*/
void InitStack(Stack * s);
/*Empty Finish*/
statue StackEmpty(Stack  s);
/*Destroy Finish*/
void DestroyStack(Stack * s);
/*Get Finish*/
statue GetTop(Stack s,PointNode * t);
/*Push Finish*/
statue Push(Stack * s,PointNode t,int flag);//t1 = leftchild out 2 = rightchild out
/*Pop Finish*/
statue Pop(Stack * s,PointNode * t);


#endif //CCODE2_SEQUENCE_H
