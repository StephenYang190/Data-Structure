//
// Created by HP on 2019/10/18.
//

#ifndef CCODE2_SeQuence_H
#define CCODE2_SeQuence_H

#define INIT_LONG 10
#define ADD_LONG 5
typedef enum  {false,true} statue;

/*ADT*/
typedef struct SeQuence_ADT
{
    int x,y;
}Node,*StackNode;

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
statue GetTop(Stack s,int * x,int * y);
/*Push Finish*/
statue Push(Stack * s,int x,int y);
/*Pop Finish*/
statue Pop(Stack * s,int * x,int * y);
/*Traverse Finish*/
void StackTraverse(Stack  s);

#endif //CCODE2_SeQuence_H
