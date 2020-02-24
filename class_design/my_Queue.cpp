//
// Created by 97927 on 2019/12/2.
//
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "my_Queue.h"
using namespace std;

QNode::QNode(int n) {
    QNode::data = n;
}


my_Queue::my_Queue() {
    Fst = new QNode[INIT_LONG];
    Length = 10;
    Nowside = 0;
}
bool my_Queue::empty() {
    return Nowside == 0;
}
int my_Queue::length() {
    return Length;
}
bool my_Queue::getElem(int i, int *e) {
    if(i > Nowside || i < 1)
        return false;
    *e = Fst[i - 1].data;
}
int my_Queue::locateElem(int e) {
    int i = 0;
    while(i < Nowside && Fst[i].data != e)
    {
        i++;
    }
    if(i == Nowside)
        return -1;
    return i + 1;
}
bool my_Queue::priorElem(int e, int *pre) {
    int i = 0;
    while(i < Nowside && Fst[i].data != e)
    {
        i++;
    }
    if(i == Nowside) return false;
    *pre = Fst[i - 1].data;
    return true;
}
bool my_Queue::nextElem(int e, int *next) {
    int i = 0;
    while(i < Nowside && Fst[i].data != e)
    {
        i++;
    }
    if(i >= Nowside - 1) return false;
    *next = Fst[i + 1].data;
    return true;
}
bool my_Queue::clearQueue() {
    if(!empty())
    {
        Nowside = 0;
    }
}
bool my_Queue::insert(int i, int e) {
    if(i < 1 || i > Nowside)
        return false;

    for(int k = Nowside - 1;k >= (i - 1);k--)
    {
        Fst[k + 1].data = Fst[k].data;
    }

    Fst[i - 1].data = e;
    Nowside++;

    if(Nowside == Length)
    {
        auto * p = new QNode[Length + ADD_LONG];
        for(int de = 0; de < Nowside; de++)
        {
            p[de].data = Fst[de].data;
        }
        delete [] Fst;
        Fst = p;
        Length += ADD_LONG;
    }

    return true;
}
bool my_Queue::deleteNode(int i, int *e) {
    if(i > Nowside || i < 1)
        return false;

    for(int k = i - 1;k < Nowside;k++)
    {
        Fst[k].data = Fst[k + 1].data;
    }
    Nowside --;

    return true;
}
bool my_Queue::add(int e) {
    Fst[Nowside].data = e;
    Nowside++;
    if(Nowside == Length)
    {
        auto * p = new QNode[Length + ADD_LONG];
        for(int i = 0;i < Nowside;i++)
        {
            p[i].data = Fst[i].data;
        }
        delete [] Fst;
        Fst = p;
        Length += ADD_LONG;
    }
}
bool my_Queue::show() {
    for(int i = 0;i < Nowside;i++)
    {
       cout<<"data"<<i<<" : "<<Fst[i].data<<endl;
    }
    printf("\n");
}
my_Queue::~my_Queue() {
    if(!empty())
    {
        delete [] Fst;
    }
    Fst = nullptr;
    Nowside = 0;
}

int my_Queue::nowlength() {
    return Nowside;
}


