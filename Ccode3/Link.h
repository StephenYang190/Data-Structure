//
// Created by HP on 2019/10/18.
//

#ifndef CCODE3_LINK_H
#define CCODE3_LINK_H

/*ADT*/
typedef enum  {false,true} statue;

typedef struct List_ADT
{
    int x1,y1;
    int x2,y2;
    int sign;
    struct List_ADT * next;
}Node,*Listink;

typedef struct List
{
    Listink Frst,Lst;
    int Length;
}Link;

/*operate*/

/*Init Finish*/
void InitList(Link * L);
/*Empty Finis*/
statue ListEmpty(Link * L);
void DestroyList(Link * L);
int ListLength(Link * L);
statue GetElem(Link * L,int i,int *e1,int *e2,int *e3,int *e4);
Node * PriorElem(Link * L,int i);
/*Clear Finish*/
void ClearList(Link * L);
/*add Finish*/
void add(Link * l,int e1,int e2,int e3,int e4);
/*show Finish*/
void showlisk(Link * l);

#endif //CCODE3_LINK_H
