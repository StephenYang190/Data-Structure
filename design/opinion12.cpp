//
// Created by 97927 on 2019/12/27.
//
#include "my_Graph.h"
#include <iostream>
#include <vector>
#include "function.h"
using namespace std;

int main()
{
    int n = getInt("number");
    vector<int> object;
    vector<int> quan;
    for(int i = 0;i < n;i++)
    {
        int q;
        cin>>q;
        quan.push_back(q);
    }
    n = getInt("number");
    for(int i = 0;i < n;i++)
    {
        int q;
        cin>>q;
        object.push_back(q);
    }
    heapSort(quan);
    heapSort(object);
    int sum = 0;
    while(true)
    {
        if(object.empty() || quan.empty())
            break;
        int nm = quan.back();
        quan.pop_back();
        int ob;
        if(nm > 0)
        {
            ob = object.back();
            if(ob >= 0)
            {
                object.pop_back();
            }
        }
        else{
            ob = object.front();
            if(ob <= 0)
            {
                object.erase(object.begin());
            }
        }
        if(ob * nm > 0)
        {
            sum += ob*nm;
        }
    }
    cout<<sum;

    return 0;
}
