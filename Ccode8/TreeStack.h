//
// Created by HP on 2019/10/18.
//

#ifndef CCODE2_SEQUENCE_H
#define CCODE2_SEQUENCE_H

#define INIT_LONG 10
#define ADD_LONG 5

#include "BinaryTree.h"
#ifndef STATUE
typedef enum  {false,true} statue;
#define STATUE
#endif

/*ADT*/
typedef struct
{
    PointTree t;
    int flag;
}SNode,*StackNode;

typedef struct Stack
{
    StackNode Frst;
    int top,base;
    int length;
}Stack,*PointStack;

/*operate*/

/*Init Finish*/
void InitTStack(Stack * s);
/*Empty Finish*/
statue TStackEmpty(Stack  s);
/*Destroy Finish*/
void DestroyTStack(Stack * s);
/*Get Finish*/
statue TGetTop(Stack s,PointTree * t);
/*Push Finish*/
statue TPush(Stack * s,PointTree t,int flag);//t1 = leftchild out 2 = rightchild out
/*Pop Finish*/
statue TPop(Stack * s,PointTree * t);


#endif //CCODE2_SEQUENCE_H
