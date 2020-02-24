//
// Created by HP on 2019/10/18.
//

#ifndef CCODE2_SeQuence_H
#define CCODE2_SeQuence_H

#define INIT_LONG 10
#define ADD_LONG 5
#ifndef STATUE
typedef enum  {false,true} statue;
#define STATUE
#endif

/*ADT*/
typedef struct SeQuence_ADT
{
    int data;
}SeNode,*PointSeNode;

typedef struct SeQuence
{
    PointSeNode Frst;
    int Length;
    int nowside;
}Sequence,*PointSequence;

/*operate*/

/*Init Finish*/
void InitSeQuence(Sequence * L);
/*Empty Finish*/
statue SeQuenceEmpty(Sequence * L);
void DestroySeQuence(Sequence * L);
int SeQuenceLength(Sequence * L);
statue GetElem(Sequence * L,int i,int *e);
int LocateElem(Sequence * L,int e);
statue PriorElem(Sequence * L,int e,int * pre);
statue NextElem(Sequence * L,int e,int * next);
/*Clear Finish*/
void ClearSeQuence(Sequence * L);
/*Insert Finish*/
statue SeQuenceInsert(Sequence * l,int i,int e);
/*Delete Finish*/
statue SeQuenceDelete(Sequence * l,int i,int * e);
/*add Finish*/
void SequenceAdd(Sequence * l,int e);
/*show Finish*/
void SequenceShow(Sequence * l);

#endif //CCODE2_SeQuence_H
