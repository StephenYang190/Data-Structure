
#include <cstdlib>
#include <cstdio>
#include "my_Link.h"
#include "my_Sequence.h"
#include "my_Queue.h"
#include "my_stack.h"
#include <iostream>
#include <vector>
#include <string>
#include "function.h"
#include <ctime>
#include <fstream>

using namespace std;
#define TEST

#ifndef TEST
#define TEST
int main()
{
/*
cout<<time(nullptr)<<endl;
    time_t current_time;
    current_time = time(nullptr);

vector<int> v;
     int a = 100;
     v.push_back(a);
     v.erase(v.begin());
     cout<<a;
     char ch;
     cin.get(ch);
     cout<<ch;
     cout<<int(ch);

     std::string str("123456");
     cout<<str<<endl;
     str.pop_back();
     cout<<str<<endl;
     cout<<time(nullptr);
*/

     /*ofstream out[10];
     std::string sfilename = "source";
     for(int i = 0;i < 10;i++)
     {
         std::string filename = sfilename;
         filename += '0' + i;
         filename += ".txt";
         out[i].open(filename);
     }
     for(int k = 0;k < 10;k++)
     {
         for(int i = 0;i < 50000;i++)
         {
             int n = (int)random() % 50000;
             out[k]<<n<<" ";
             if((i % 10) == 9)
             {
                 out[k]<<endl;
             }
         }
     }

    for(int i = 0;i < 10;i++)
    {
        out[i].close();
    }*/
    /*vector<int> v;
    for(int i = 0;i < LENG;i++)
    {
        int num = (int)random() % 200;
        v.push_back(num);
        cout<<num<<" ";
        if((i % 10) == 9)
            cout<<endl;
    }
    straightSort(v);
    for(int i = 0;i < LENG;i++)
    {
        cout<<v[i]<<" ";
        if((i % 10) == 9)
            cout<<endl;
    }*/
    /*string str("asdfgh");
    str[2] = 'a';
    cout<<str;*/
    vector<int> v;
    for(int i = 0;i < 10000;i++)
    {
        int n = random() % 50000;
        cout<<n<<" ";
        if(i%10 == 9)
            cout<<endl;
        v.push_back(n);
    }
    cout<<endl;
    shellSort(v);

    return 0;
}

#endif
