//
// Created by 97927 on 2019/12/2.
//
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "my_Link.h"
using namespace std;

LNode::LNode(int n, LNode *nxt) {
    data = n;
    next = nxt;
}

my_Link::my_Link() {
    LNode * p = new LNode;
    p->data = 0;
    p->next = nullptr;
    Fst = p;
    Lst = p;
    Length = 0;
}
bool my_Link::empty() {
    return Lst == Fst;
}
int my_Link::length() {
    return Length;
}
bool my_Link::getElem(int i, int *e) {
    if(i > Length || i < 1)
        return false;
    LNode * p = Fst->next;
    int k = 1;
    while(k < i)
    {
        p = p->next;
        k++;
    }
    if(e)
        *e = p->data;

    return true;
}
int my_Link::locateElem(int e) {
    LNode * p = Fst->next;
    int i = 1;
    while(p && p->data != e)
    {
        p = p->next;
        i++;
    }
    if(i > Length)
        return -1;
    return i;
}
bool my_Link::priorElem(int e, LNode *pre) {
    LNode * p = Fst;
    while(p->next && p->next->data != e)
    {
        p = p->next;
    }
    if(p->next && p->next->data == e)
    {
        pre = p;
    } else{
        pre = nullptr;
    }
}
bool my_Link::nextElem(int e, LNode *next) {
    LNode * p = Fst->next;
    while(p && p->data != e)
    {
        p = p->next;
    }
    if(p && p->data == e)
        next = p->next;
}
bool my_Link::clearLink() {
    if(!empty())
    {
        LNode * p = Fst->next;
        while(p)
        {
            LNode * q = p->next;
            delete(p);
            p = q;
        }
    }
    Fst->next = nullptr;
    Lst = Fst;
    Length = 0;
}
bool my_Link::insert(int i, int e) {
    if(i < 1)
        return false;

    if(i > Length)
    {
        LNode * p = new LNode;
        p->data = e;
        p->next = nullptr;
        Lst->next = p;
        Lst = p;
        Length++;
        return true;
    }
    LNode * p = Fst->next;
    LNode * q = Fst;
    int k = 1;
    while(p && k != i)
    {
        q = p;
        p = p->next;
        k++;
    }
    LNode * newnode = new LNode;
    newnode->data = e;
    q->next = newnode;
    newnode->next = p;
    Length ++;

    return true;
}
bool my_Link::deleteNode(int i, int *e) {
    if(i > Length || i < 1)
        return false;

    LNode * p = Fst->next;
    LNode * q = Fst;
    int k = 1;
    while(p && k != i)
    {
        p = p->next;
        k++;
    }
    priorElem(p->data,q);
    q = p->next;
    *e = p->data;
    delete(p);
    Length --;

    return true;
}
bool my_Link::addLink(int e) {
    LNode * newnode = new LNode;
    newnode->data = e;
    newnode->next = nullptr;

    Lst->next = newnode;
    Lst = newnode;
    Length++;
}
bool my_Link::showLink() {
    LNode * p = Fst->next;
    int k = 1;
    while(p)
    {
        cout<<" data "<<k<<" : "<<p->data;
        p = p->next;
        k++;
        if(!(k%10))
        {
            cout<<endl;
        }
    }
    cout<<endl;
}

my_Link::~my_Link() {
    LNode * p = Fst->next;
    while(p)
    {
        LNode * q = p->next;
        delete p;
        p = q;
    }
    delete Fst;
}
