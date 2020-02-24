//
// Created by 97927 on 2019/12/27.
//
#include "my_Graph.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int nd_n,ed_n;
    cin>>nd_n>>ed_n;
    my_Graph g(nd_n,ed_n,1);
    int n;
    cin>>n;
    for(int i = 0;i < n;i++)
    {
        int bgn;
        cin>>bgn;
        vector<float> T;
        //find the shortest distance
        g.dijkstra(T,bgn - 1);
        float sum = 0;
        for(int k = 0;k < nd_n;k++)
        {
            if(k == bgn - 1)
                continue;
            if(T[k] == MAX)
            {
                sum = 0;
                break;
            }
            sum += T[k];
        }
        if(sum != 0)
        {
            sum = (float)(nd_n - 1) / sum;
        }
        cout.setf(ios::showpoint);
        cout.flags(ios::fixed);
        cout.precision(2);
        cout<<"Cc("<<bgn<<") = "<<sum<<endl;
    }
}