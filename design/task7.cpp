//
// Created by 97927 on 2019/12/30.
//
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include "my_Graph.h"
#include "function.h"
using namespace std;

int main()
{
    string str = "1234.txt";//bus line file
    my_Graph_Bus g(str);
    string node1 = getString("node1");
    string node2 = getString("node2");
    cout<<endl;
    while(node1 != "p" && node2 != "p")
    {
        //the fast line
        g.bfsGo(node1,node2);
        cout<<endl;
        //the easiest line
        g.dfsGo(node1,node2);
        node1 = getString("node1");
        node2 = getString("node2");
    }


    return 0;
}
