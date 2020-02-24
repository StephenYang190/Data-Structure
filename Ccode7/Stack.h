//
// Created by HP on 2019/10/18.
//

#ifndef CCODE2_SEQUENCE_H
#define CCODE2_SEQUENCE_H

#define INIT_LONG 10
#define ADD_LONG 5
#ifndef TDY
typedef enum {false,true}statue;
#define TDY
#endif

/*ADT*/
typedef struct
{
    int x;
}kNode,*StackNode;

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
/*Length Finish*/
int StackLength(Stack  s);
/*Clear Finish*/
void ClearStack(Stack * s);
/*Get Finish*/
statue GetTop(Stack s,int * e);
/*Push Finish*/
statue Push(Stack * s,int e);
/*Pop Finish*/
statue Pop(Stack * s,int * e);
/*Traverse Finish*/
void StackTraverse(Stack  s);

#endif //CCODE2_SEQUENCE_H
