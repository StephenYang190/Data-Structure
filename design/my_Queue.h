//
// Created by 97927 on 2019/12/13.
//

#ifndef DESIGN_MY_QUEUE_H
#define DESIGN_MY_QUEUE_H

class QNode{
public:
    int data;
    QNode * next;
    QNode(int n = 0,QNode* nxt = nullptr);
    ~QNode();
};
class Qnode_more :public QNode {
public:
    int data1;//time begin
    int data2;//time eng
    Qnode_more * frnt;
    Qnode_more * next;
    Qnode_more(int n1 = 0,int n2 = 0,int n3 =0):QNode(n1){//initially
        data1 = n2;
        data2 = n3;
        frnt = nullptr;
        next = nullptr;
    };
    ~Qnode_more()= default;
};
class my_Queue {
private:
    QNode * frt;
    QNode * lst;
    int length;
public:
    my_Queue();
    bool empty();
/*Length Finish*/
    int getlength();
/*Get Finish*/
    bool getHead(int *e);
/*Clear Finish*/
    void clearQueue();
/*En Finsh*/
    bool enQueue(int e);
/*De Finish*/
    bool deQueue(int *e);
/*Traverse Finsh*/
    bool traverse();
    ~my_Queue();
};
class my_Queue_Plus{
private:
    Qnode_more * frt;
    Qnode_more * lst;
    int length;

public:
    my_Queue_Plus();//initially
    bool empty();//true when all thing finish
    int getlength();//return length
    bool getHead(int *e);//get the first thing
    void clearQueue();
    bool enQueue(int e1,int e2,int e3);//insert thing to back
    bool deQueue(int *e,int *e2,int *e3);//pop the first thing
    bool traverse();//show queue
    bool sort();//sort as begin time
    int lastTime();//return the last thing end time
    bool timeEvent(int t,my_Queue_Plus & q);//deal with time n
    ~my_Queue_Plus();
};

#endif //DESIGN_MY_QUEUE_H
