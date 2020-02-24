//
// Created by 97927 on 2019/12/21.
//
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include "my_Queue.h"
#include <string>
#include "function.h"
using namespace std;

//#define YTD

class box{
private:
    vector<int> key_store;//box to store key
    int box_s;//box size
public:
    box(int n = 1)//initially
    {
        box_s = n;
        for(int i = 0;i < n;i++)
        {
            key_store.push_back(i + 1);
        }
    }
    bool pop(int n)//pop key n
    {
        for(int i = 0;i < box_s;i++)
        {
            //find key site
            if(key_store[i] == n)
            {
                //pop
                key_store[i] = 0;
                return true;
            }
        }
        return false;
    }
    bool push(int n)//push key n
    {
        for(int i = 0;i < box_s;i++)
        {
            //find box empty site
            if(key_store[i] == 0)
            {
                //push
                key_store[i] = n;
                return true;
            }
        }
        return false;
    }
    bool show()//show box
    {
        for(int i = 0;i < box_s;i++)
        {
            if(key_store[i] == 0)
            {
                cout<<"X ";
            } else{
                cout<<key_store[i]<<" ";
            }
        }
        cout<<endl;

        return true;
    }
    bool show(ofstream &out)//show out to file
    {
        for(int i = 0;i < box_s;i++)
        {
            if(key_store[i] == 0)
            {
                out<<"X ";
            } else{
                out<<key_store[i]<<" ";
            }
        }
        out<<endl;

        return true;
    }
    ~box()
    {
        key_store.clear();
    }
};
bool timePass(box &b,my_Queue_Plus &p,ofstream &out)
{
    int n = p.lastTime();//get end time
    int i = 0;
    my_Queue_Plus q;
    while(!p.empty())
    {
        i++;
        if(!p.timeEvent(i,q))//this time do not happen any things
        {
            continue;
        }
        while(!q.empty())//deal with things happen this time
        {
            int key_n = 0;
            int ta_t = 0;
            int re_t = 0;
            q.deQueue(&key_n,&ta_t,&re_t);
            if(ta_t == i)//if star time == this time
            {
                b.pop(key_n);
            } else if (re_t == i)//if end time == this time
            {
                b.push(key_n);
            }
        }
        cout<<"after time "<<i<<" : ";
        out<<"after time "<<i<<" : ";
        b.show();
        b.show(out);
        q.clearQueue();
    }

    return true;
}
#ifndef YTD
int main()
{
    //open the file to input and output
    ifstream in_tx;
    ofstream out_tx("task3result.txt");
    std::string fileName = getString("filename");
    fileName += ".txt";
    in_tx.open(fileName);
    if(!in_tx.is_open())
    {
        cout<<"wrong"<<endl;

        return 0;
    }
    //init keybox and timetable
    int total_long = 0;
    in_tx>>total_long;
    box B(total_long);
    my_Queue_Plus timetable;
    int n;
    in_tx>>n;
    for(int i = 0;i < n;i++)
    {
        int key_n;
        int ta_t;
        int re_t;
        in_tx>>key_n>>ta_t>>re_t;
        timetable.enQueue(key_n,ta_t,re_t + ta_t);
    }
    //output timetable
    timetable.traverse();
    //sort timetable
    timetable.sort();
    //output result
    timetable.traverse();
    timePass(B,timetable,out_tx);
    in_tx.close();
    out_tx.close();
    return 0;
}
#endif