//
// Created by 97927 on 2019/12/13.
//

#include "my_Queue.h"
#include <iostream>

bool my_Queue::empty() {
    return length == 0;
}

my_Queue::my_Queue() {
    frt = new QNode();
    lst = frt;
    length = 0;
}

int my_Queue::getlength() {
    return length;
}

bool my_Queue::getHead(int *e) {
    if(empty())
        return false;
    *e = frt->next->data;
    return true;
}

void my_Queue::clearQueue() {
    QNode * p = frt->next;
    while(p)
    {
        QNode * m = p->next;
        delete p;
        p = m;
    }
    lst = frt;
    length = 0;
}

bool my_Queue::enQueue(int e) {
    QNode * p = new QNode;
    if(!p)
        return false;

    p->data = e;
    p->next = nullptr;
    lst->next = p;
    lst = p;
    length++;

    return true;
}

bool my_Queue::deQueue(int *e) {
    QNode * p = frt->next;
    if(p)
    {
        if(p == lst)
        {
            lst = frt;
        }
        *e = p->data;
        frt->next = p->next;
        delete p;
    }
    else
        return false;
    length--;
    return true;
}

bool my_Queue::traverse() {
    using std::cout;
    using std::endl;
    QNode * p = frt->next;
    int k = 1;
    while(p)
    {
        cout<<"data "<<k<<" : "<<p->data<<" ";
        p = p->next;
        k++;
        if(k % 10 == 0)
            cout<<endl;
    }
    cout<<"queue traverse finish."<<endl;
    return true;
}

my_Queue::~my_Queue() {
    QNode * p = frt;
    while(p)
    {
        QNode * m = p->next;
        delete p;
        p = m;
    }
    lst = nullptr;
    frt = nullptr;
    length = 0;
}

QNode::QNode(int n,QNode * nxt) {
    data = n;
    QNode::next = nxt;
}

QNode::~QNode() = default;


my_Queue_Plus::my_Queue_Plus() {
    frt = new Qnode_more();
    lst = frt;
    length = 0;
}

bool my_Queue_Plus::empty() {
    return length == 0;
}

int my_Queue_Plus::getlength() {
    return length;
}

bool my_Queue_Plus::getHead(int *e) {
    if(empty())
        return false;
    *e = frt->next->data;
    return true;
}

void my_Queue_Plus::clearQueue() {
    Qnode_more * p = frt->next;
    while(p)
    {
        Qnode_more * m = p->next;
        delete p;
        p = m;
    }
    lst = frt;
    length = 0;
}

bool my_Queue_Plus::enQueue(int e1, int e2, int e3) {
    Qnode_more * p = new Qnode_more;
    if(!p)
        return false;

    p->data = e1;
    p->data1 = e2;
    p->data2 = e3;
    p->frnt = lst;
    p->next = nullptr;
    length++;
    lst->next = p;
    lst = p;

    return true;
}

bool my_Queue_Plus::deQueue(int *e, int *e2, int *e3) {
    using std::cout;
    using std::endl;
    Qnode_more * p = frt->next;
    if(p)
    {
        if(p == lst)
        {
            lst = frt;
        }
        *e = p->data;
        *e2 = p->data1;
        *e3 = p->data2;
        frt->next = p->next;
        if(p->next)
        p->next->frnt = frt;
        delete p;
    }
    else
        return false;
    length--;
    return true;
}

bool my_Queue_Plus::traverse() {
    using std::cout;
    using std::endl;
    Qnode_more * p = frt->next;
    int k = 1;
    while(p)
    {
        cout<<"data "<<k<<" : "<<p->data<<","<<p->data1<<","<<p->data2 - p->data1<<" ";
        p = p->next;
        k++;
        if(k % 10 == 0)
            cout<<endl;
    }
    cout<<"queue traverse finish."<<endl;
    return true;
}

my_Queue_Plus::~my_Queue_Plus(){
    Qnode_more * p = frt;
    while(p)
    {
        Qnode_more * m = p->next;
        delete p;
        p = m;
    }
    lst = nullptr;
    frt = nullptr;
    length = 0;
}

bool my_Queue_Plus::sort() {
    Qnode_more * p = frt->next;
    while(p)
    {
        Qnode_more * min = p;
        Qnode_more * q = p->next;
        while(q)
        {
            //find the min begin time
            if(q->data1 < min->data1)
            {
                min = q;
            }
            //if begin time is equal , compare end time
            else if(q->data1 == min->data1)
            {
                if(q->data2 < min->data2)
                {
                    min  = q;
                }
                else if(q->data2 == min->data2)
                {
                    if(q->data < min->data)
                    {
                        min = q;
                    }
                }
            }
            q = q->next;
        }
        if(min == p)
        {
            p = p->next;
            continue;
        }
        min->frnt->next = min->next;
        if(min->next)
            min->next->frnt = min->frnt;
        p->frnt->next = min;
        min->frnt = p->frnt;
        p->frnt = min;
        min->next = p;
    }

    return true;
}

int my_Queue_Plus::lastTime() {
    return lst->data2;
}
//find event happen at this second
bool my_Queue_Plus::timeEvent(int t,my_Queue_Plus & q) {
    using std::cout;
    using std::endl;
    Qnode_more * p = frt->next;
    bool reFlag = false;
    if(p->data1 > t)
        return false;
    while(p)
    {
        if(p->data1 > t)
            break;
        if(p->data1 == t || p->data2 == t)
        {
            int key_n = p->data;
            int ta_t = p->data1;
            int re_t = p->data2;
            q.enQueue(key_n,ta_t,re_t);
            reFlag = true;
        }
        //if this event is end , pop
        else if(p->data2 < t)
        {
            p->frnt->next = p->next;
            if(p->next)
                p->next->frnt = p->frnt;
            cout<<"event "<<" : "<<p->data<<","<<p->data1<<","<<p->data2 - p->data1<<" end"<<endl;
            length--;
            Qnode_more * pause = p->next;
            delete p;
            p = pause;
            continue;
        }
        p = p->next;
    }

    return reFlag;
}
