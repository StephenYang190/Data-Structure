//
// Created by 97927 on 2019/12/26.
//
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include "function.h"
#include <ctime>
#include <fstream>
using namespace std;

bool compareSort(int n)
{
    std::string ifilename = "task8/source" ;
    string sort[8] = {"mergesort","selectionsort","bubblesort",
                      "fastsort","heapsort","radixsort"};
    ifilename += ('0' + n) ;
    ifilename += ".txt";
    ifstream in(ifilename);
    int k = 0;
    vector<int> test,p;
    while(!in.eof())
    {
        int nm;
        in>>nm;
        test.push_back(nm);
        p.push_back(nm);
    }
    in.close();
    cout<<"example "<<n<<endl;
    selectionSort(test);
    test.assign(p.begin(),p.end());
    bubbleSort(test);
    test.assign(p.begin(),p.end());
    fastSort(test);
    test.assign(p.begin(),p.end());
    heapSort(test);
    test.assign(p.begin(),p.end());
    radixSort(test,5);
    test.assign(p.begin(),p.end());
    mergeSort(test);
    test.assign(p.begin(),p.end());
    straightSort(test);
    test.assign(p.begin(),p.end());
    shellSort(test);

    return 0;
}
int main()
{
    for(int i = 0;i < 10;i++)
    {
        compareSort(i);
    }

    return 0;
}
