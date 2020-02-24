#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

/*Init Finish*/
void InitStack(Stack * s)
{
    StackNode p = (StackNode)malloc(sizeof(Node) * INIT_LONG);
    s->Frst = p;
    s->length = 10;
    s->base = 0;
    s->top = 0;
}
/*Empty Finish*/
statue StackEmpty(Stack  s)
{
    if(s.top == s.base)
        return true;
    return false;
}
void DestroyStack(Stack * s)
{
    if(!StackEmpty(*s))
    {
        free(s->Frst);
    }
    s->Frst = NULL;
    s->length = 0;
    s->base = 0;
    s->top = 0;
}
int StackLength(Stack  s)
{
    return s.top - s.base;
}
/*Clear Finish*/
void ClearStack(Stack * s)
{
    if(!StackEmpty(*s))
    {
        s->top = 0;
        s->base = 0;
    }
}
statue GetTop(Stack s,int * e)
{
    if(!StackEmpty(s))
    {
        *e = s.Frst[s.top - 1].x;
        return true;
    }
    return false;
}
statue Push(Stack * s,int e)
{
    if(s->top == s->length)
        return false;
    s->Frst[s->top].x = e;
    s->top++;
    return true;
}
statue Pop(Stack * s,int * e)
{
    if(!StackEmpty(*s))
    {
        *e = s->Frst[s->top - 1].x;
        s->top--;
        return true;
    }
    return false;
}
void StackTraverse(Stack  s)
{
    if(!StackEmpty(s))
    {
        for(int i = 0;i < s.top;i++)
        {
            printf("Date %d : %d\n",i,s.Frst[i].x);
        }
    }
    else
    {
        printf("Empty.\n");
    }
}