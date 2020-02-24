//
// Created by HP on 2019/10/18.
//

#ifndef CCODE2_SeQuence_H
#define CCODE2_SeQuence_H

#define INIT_LONG 20
#define ADD_LONG 5
typedef enum  {false,true} statue;

/*ADT*/
typedef struct Node_ADT
{
    int site;
    struct Node_ADT * next;
}Site,*SitePoint;
typedef struct SeQuence_ADT
{
    int data;//max 5
    SitePoint fn;
}Node,*SeQuenceNode;

typedef struct SeQuence
{
    SeQuenceNode Frst;
    int Length;
}Sequence;

/*operate*/

/*Init Finish*/
void InitSeQuence(Sequence * L);
/*Empty Finish*/
statue SeQuenceEmpty(Sequence * L);
void DestroySeQuence(Sequence * L);
int SeQuenceLength(Sequence * L);

/*Clear Finish*/
void ClearSeQuence(Sequence * L);
/*add Finish*/
statue add(Sequence * l,int e);
/*show Finish*/
void showlisk(Sequence * l);

#endif //CCODE2_SeQuence_H
