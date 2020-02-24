//
// Created by 97927 on 2019/12/2.
//

#ifndef CLASS_DESIGN_MY_QUEUE_H
#define CLASS_DESIGN_MY_QUEUE_H

#define INIT_LONG 10
#define ADD_LONG 5

class SeNode
{
public:
    int data;
    SeNode(int n = 0);//init to 0
};
class my_Sequence {
public:
    SeNode * Fst;
    int Length;
    int Nowside;
    my_Sequence();//create a 10 array now = 0
    bool empty();//return true for empty
    int length();//return length not nowside
    int nowlength();//return nowside
    bool getElem(int i,int *e);//get ith elem data
    int locateElem(int e);//return position of elem e
    bool priorElem(int e,int * pre);//e priorelem
    bool nextElem(int e,int * next);//e next elem
    bool clearQueue();//nowside = 0 length don't change
    bool insert(int i,int e);//add number at ith
    bool deleteNode(int i,int * e);//delete ith number
    bool add(int e);//add number at rear
    bool show();//show queue

    ~my_Sequence();
};


#endif //CLASS_DESIGN_MY_QUEUE_H
