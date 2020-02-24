#include <stdio.h>
#include <stdlib.h>
#include "TreeStack.h"

/*Init Finish*/
void InitTStack(Stack * s)
{
    StackNode p = (StackNode)malloc(sizeof(SNode) * INIT_LONG);
    s->Frst = p;
    s->length = 10;
    s->base = 0;
    s->top = 0;
}
/*Empty Finish*/
statue TStackEmpty(Stack  s)
{
    if(s.top == s.base)
        return true;
    return false;
}
void DestroyTStack(Stack * s) {
    if (!TStackEmpty(*s)) {
        free(s->Frst);
    }
    s->Frst = NULL;
    s->length = 0;
    s->base = 0;
    s->top = 0;
}
statue TGetTop(Stack s,PointTree * t)
{
    if(!TStackEmpty(s))
    {
        *t = s.Frst[s.top - 1].t;
        return true;
    }
    return false;
}
statue TPush(Stack * s,PointTree t,int flag)
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
statue TPop(Stack * s,PointTree * t)
{
    if(!TStackEmpty(*s))
    {
        *t = s->Frst[s->top - 1].t;
        s->top--;
        return true;
    }
    return false;
}