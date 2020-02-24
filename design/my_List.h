
//
// Created by 97927 on 2019/12/29.
//

#ifndef DESIGN_MY_LIST_H
#define DESIGN_MY_LIST_H

#include <cstring>
#include <ctime>
class task {
public:
    char name[128];//name of task
    int memory;//store memory
    time_t bgn;//store the begin time
    int lastTime;//store the task last time
    time_t end;//store the end time
    task(char* t) : memory(0)//initial
    {
        std::time(&bgn);
        lastTime = 0;
        end = 0;
        char* b = t + 1, * p = t + 1;
        while (*p) {
            if (*p == '"')
            {
                *p = 0;
                strcpy(name, b);
                break;
            }
            p++;
        }
        for (b = p + 1; p[1] != 'K'; p++)
            if (*p == '"')
                b = p;
        for (char* c = b + 1; c != p; c++)//calculate the memory
            if (*c == ',')
                continue;
            else
                memory = 10 * memory + *c - '0';
    }
    bool operator<(task& t) { return this->memory < t.memory; }
};
class LiNode{
public:
    task data;
    LiNode * next;
    LiNode(task n):data(n)
    {
        next = nullptr;
    }
    ~LiNode();
};
class LiNode_B {
public:
    task data;
    LiNode_B * pre;
    LiNode_B * next;
    LiNode_B(task n):data(n)
    {
        pre = nullptr;
        next = nullptr;
    }
    ~LiNode_B();
};
class my_List{
public:
    LiNode * frt;
    LiNode * lst;
    int length;
    my_List();//initial
    ~my_List();//delete
    LiNode * preLiNode(LiNode * n);//find the particular node t's pre
    bool enList(task t);//insert t to frt
    bool deList();//delete the last node
    bool dele(LiNode * t);//delete the particular node t
};
class my_List_B {
public:
    LiNode_B * frt;
    LiNode_B * lst;
    int length;
    my_List_B();//initial
    ~my_List_B();//delete
    bool empty();//return true is empty
    bool enList(task t);//insert t to last
    bool deList();//delete the last node
    LiNode_B * dete(LiNode_B * t);//delete the particular node t
    bool sortList();//sort as task memory
    bool compare(my_List_B &b,my_List &ndl);//compare two memory standing for all task in each second
};



#endif //DESIGN_MY_LIST_H
