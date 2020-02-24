//
// Created by 97927 on 2019/12/29.
//

#include "my_List.h"
#include <ctime>

my_List_B::my_List_B() {
    frt = nullptr;
    lst = nullptr;
    length = 0;
}

my_List_B::~my_List_B() {
    LiNode_B * p = frt;
    while (p)
    {
        LiNode_B * q = p->next;
        delete p;
        p = q;
    }
    frt = nullptr;
    lst = nullptr;
}

bool my_List_B::enList(task t) {
    length++;
    LiNode_B * nnd = new LiNode_B(t);//new node
    if(!nnd)
        return false;
    if(!frt)//if list is empty
    {
        frt = nnd;
        lst = nnd;
    } else{
        lst->next = nnd;
        nnd->pre = lst;
        lst = nnd;
    }
    return true;
}

bool my_List_B::deList() {
    if(!lst)
    {
        return false;
    } else{
        LiNode_B * p = lst->pre;
        delete lst;
        if(p)//if last' pre node exist
        {
            p->next = nullptr;
            lst = p;
        } else{
            frt = nullptr;
            lst = nullptr;
        }
    }
    length--;
    return true;
}

bool my_List_B::sortList() {
    //selection sort
    LiNode_B * p = frt;
    while(p)
    {
        int min = p->data.memory;//store min memory
        LiNode_B * min_s = p;//store min site
        LiNode_B * q = p->next;
        while(q)
        {
            if(q->data.memory < min)//if q is miner than min , swap
            {
                min = q->data.memory;
                min_s = q;
            }
            q = q->next;
        }
        if(min_s == p)
        {
            p = p->next;
            continue;
        }
        min_s->pre->next = min_s->next;
        if(min_s->next)//if min is last
            min_s->next->pre = min_s->pre;
        else
            lst = min_s->pre;
        if(p->pre)
        {
            p->pre->next = min_s;
            min_s->pre = p->pre;
        }
        min_s->next = p;
        p->pre = min_s;
        if(p == frt)//if p is first
        {
            frt = min_s;
        }

    }
    return true;
}

bool my_List_B::compare(my_List_B &b,my_List &ndl) {
    LiNode_B * p = frt;
    //compare this and b
    while(p)
    {
        LiNode_B * q = b.frt;
        while(q)//weather the task in this is also in b
        {
            if(strcmp(q->data.name,p->data.name) == 0)
            {
                break;
            }
            q = q->next;
        }
        //find fail
        if(q == nullptr)
        {
            std::time(&p->data.end);//note the ending time
            ndl.enList(p->data);//push in ending list
            p = dete(p);//delete this task
        }
        else{
            p->data.lastTime++;//last time ++
            p->data.memory = q->data.memory;//refresh memory
            p = p->next;
            b.dete(q);//delete this task in b
        }
    }
    //compare b and ending list
    if(!b.empty())
    {
        LiNode_B * q = b.frt;
        while(q)
        {
            LiNode * pause = ndl.frt;
            while(pause)//weather this new task have run
            {
                if(strcmp(q->data.name,pause->data.name) == 0)
                {
                    break;
                }
                pause = pause->next;
            }
            if(pause == nullptr)
            {
            } else{
                //have run
                q->data.lastTime = pause->data.lastTime;//refresh last time
                ndl.dele(pause);
            }
            enList(q->data);//push in this list
            q = q->next;
        }
    }

    return true;
}

bool my_List_B::empty() {
    return frt == nullptr;
}

LiNode_B *my_List_B::dete(LiNode_B *t) {
    length--;
    if(t == frt)
    {
        frt = t->next;
    }
    if(t == lst)
    {
        lst = t->pre;
    }
    LiNode_B * preNode = t->next;
    if(t->pre)
        t->pre->next = t->next;
    if(t->next)
        t->next->pre = t->pre;
    delete t;
    return preNode;
}

my_List::my_List() {
    frt = nullptr;
    lst = nullptr;
    length = 0;
}

my_List::~my_List() {
    LiNode * p = frt;
    while (p)
    {
        LiNode * q = p->next;
        delete p;
        p = q;
    }
    frt = nullptr;
    lst = nullptr;
}

bool my_List::enList(task t) {
    length++;
    LiNode * nnd = new LiNode(t);
    if(!nnd)
        return false;
    nnd->next = frt;
    frt = nnd;
    if(!lst)
        lst = nnd;
    return true;
}

bool my_List::deList() {
    length--;
    if(!lst)
    {
        return false;
    } else{
        LiNode * p = preLiNode(lst);
        delete lst;
        if(p)
        {
            p->next = nullptr;
            lst = p;
        } else{
            frt = nullptr;
            lst = nullptr;
        }
        return true;
    }
}

LiNode *my_List::preLiNode(LiNode *n) {
    LiNode * p = frt;
    while(p->next)
    {
        if(p->next == n)
            break;
        p = p->next;
    }
    if(p->next == n)
        return p;
    return nullptr;
}

bool my_List::dele(LiNode *t) {
    length--;
    LiNode * pr = preLiNode(t);
    if(pr)
    {
        pr->next = t->next;
    }
    if(t == frt)
    {
        frt = t->next;
    }
    if(t == lst)
    {
        lst = pr;
    }
    delete t;

    return true;
}

LiNode::~LiNode() = default;

LiNode_B::~LiNode_B() = default;
