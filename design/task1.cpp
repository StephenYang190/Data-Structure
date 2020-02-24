//
// Created by 97927 on 2019/12/29.
//
#include <iostream>
#include <iomanip>
#include<list>
#include <cstdlib>
#include "my_List.h"
#include <windows.h>
using namespace std;

#define SLEEPTIME 2000
//#define YTD

#ifndef YTD
int main() {
    //list to store task last time
    my_List_B q;
    //list to store task end
    my_List ndl;
    cout<<std::left;
    while(true)
    {
        std::system("clear");
        cout<<endl;
        char buffer[128], cmd[] = "tasklist /FO CSV";
        //store task now
        my_List_B b;
        FILE* pipe = popen(cmd, "r");
        if (!pipe)
            return -1;

        fgets(buffer, 128, pipe);
        //last is empty , store in last and do not compare
        if(q.empty())
        {
            while (!feof(pipe))
            {
                if (fgets(buffer, 128, pipe))
                {
                    q.enList(task(buffer));
                }
            }
        }
        //compare two seconds task
        else{
            while (!feof(pipe))
            {
                if (fgets(buffer, 128, pipe))
                {
                    b.enList(task(buffer));
                }
            }
            q.compare(b,ndl);
        }

        pclose(pipe);
        //sort as for memory
        q.sortList();
        LiNode * nd = ndl.frt;
        int k = 0;
        for (LiNode_B * it = q.frt;k < 20; it = it->next,k++)
        {
            cout <<setw(40)<< it->data.name << "\t" ;
            cout<<setw(10)<< it->data.memory<<"\t"<<it->data.lastTime;
            if(nd)
            {
                cout <<"\t\t\t\t"<<setw(40)<< nd->data.name << "\t" ;
                cout<<setw(10)<< nd->data.memory<<"\t"<<nd->data.end;
                nd = nd->next;
            }
            cout<<endl;
        }
        Sleep(SLEEPTIME);
    }
    return 0;
}
#endif
