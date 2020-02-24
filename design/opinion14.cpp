//
// Created by 97927 on 2019/12/27.
//
#include <iostream>
#include <vector>
#include "my_Queue.h"
using namespace std;

int sore[3] = {0,1,2};
int main()
{
    int nm;
    cin>>nm;
    int sum = 0;
    while(nm != 0)
    {
        if(nm == 1)
        {
            sum += 1;
            sore[1] = 2;
        }
        else if(nm == 2)
        {
            sum += sore[1];
            sore[1] += 2;
        }
        cin>>nm;
    }
    cout<<sum;

    return 0;
}