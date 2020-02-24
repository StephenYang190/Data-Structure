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
void DestroyStack(Stack * s) {
    if (!StackEmpty(*s)) {
        free(s->Frst);
    }
    s->Frst = NULL;
    s->length = 0;
    s->base = 0;
    s->top = 0;
}
statue GetTop(Stack s,PointNode * t)
{
    if(!StackEmpty(s))
    {
        *t = s.Frst[s.top - 1].t;
        return true;
    }
    return false;
}
statue Push(Stack * s,PointNode t,int flag)
{
    s->Frst[s->top].t = t;
    s->Frst[s->top].flag = flag;
    s->top++;
    if(s->top == s->length)
    {
        s->Frst = realloc(s->Frst,sizeof(StackNode) * (s->length + ADD_LONG));
        s->length += ADD_LONG;
    }
    return true;
}
statue Pop(Stack * s,PointNode * t)
{
    if(!StackEmpty(*s))
    {
        *t = s->Frst[s->top - 1].t;
        s->top--;
        return true;
    }
    return false;
}