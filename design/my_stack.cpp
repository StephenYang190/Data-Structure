//
// Created by YTD on 2019/12/13.
//

#include "my_stack.h"
#include <iostream>

StNode::~StNode() = default;

my_stack::my_stack() {
    length = 0;
}

bool my_stack::empty() {
    return length == 0;
}

int my_stack::getlength() {
    return length;
}

void my_stack::clearStack() {
    frt.clear();
    length = 0;
}

bool my_stack::getTop(double *e) {
    if(length == 0)
    {
        return false;
    }
    *e = frt[length - 1].data;

    return true;
}

bool my_stack::push(double e) {
    StNode nw_node(e);
    frt.push_back(nw_node);
    length++;

    return true;
}
bool my_stack::push(int e) {
    StNode nw_node(e);
    frt.push_back(nw_node);
    length++;

    return true;
}

bool my_stack::pop(double *e) {
    if(length == 0)
        return false;
    *e = frt[length - 1].data;
    length--;
    frt.pop_back();

    return true;
}
bool my_stack::pop(int *e) {
    if(length == 0)
        return false;
    *e = frt[length - 1].data;
    length--;
    frt.pop_back();

    return true;
}

bool my_stack::traverse() {
    using std::cout;
    using std::endl;
    if(length == 0)
        return false;
    for(int i = 0;i < length;i++)
    {
        //cout<<"data "<<i<<" : "<<frt[i].data<<" ";
        cout<<frt[i].data<<" ";;
        /*if(i%10 < 1)
            cout<<endl;*/
    }

    return true;
}

bool my_stack::getTop(int *e) {
    if(length == 0)
    {
        return false;
    }
    *e = frt[length - 1].data;

    return true;
}

double my_stack::getTop() {
    if(length == 0)
    {
        return -1;
    }
    return frt[length - 1].data;
}

double my_stack::pop() {
    if(length == 0)
        return -1;
    double e = frt[length - 1].data;
    length--;
    frt.pop_back();

    return e;
}

StNode::StNode(double n) {
    data = n;
}
