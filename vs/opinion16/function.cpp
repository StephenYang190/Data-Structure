//
// Created by 97927 on 2019/12/13.
//

#include "function.h"
#include <iostream>
#include <vector>
//#include "my_Queue.h"
#include <ctime>
using namespace std;


std::string getString(const std::string& out) {
    std::string str;
    cout<<"Enter the "<<out<<" : ";
    getline(cin,str);
    return str;
}

int getInt(const string &out) {
    int num;
    cout<<"Enter the "<<out<<" : ";
    while(true)
    {
        cin>>num;
        if(cin.fail())
        {
            cout<<"Error!Please enter the integer :  ";
            cin.clear();
            continue;
        }
        break;
    }
    cin.ignore();

    return num;
}
//float getFloat(const std::string& out)
//{
//    float num;
//    cout<<"Enter the "<<out<<" : ";
//    while(true)
//    {
//        cin>>num;
//        if(cin.fail())
//        {
//            cout<<"Error!Please enter the integer :  ";
//            cin.clear();
//            continue;
//        }
//        break;
//    }
//
//    return num;
//}
//bool compareOperate(char c1,char c2)
//{
//    switch(c1)
//    {
//        case '-' :
//        case '+' :
//        {
//            return !(c2 == '-' || c2 == '+' || c2 == '(');
//        }
//        case '*' :
//        case '/' :
//        {
//            return c2 == ')';
//        }
//        case '(' :
//        {
//            return c2 != ')';
//        }
//        case ')' :
//        {
//            return false;
//        }
//    }
//}
//double computeTwoNumber(double n1, double n2,char c1)
//{
//    switch(c1)
//    {
//        case '+' :
//            return n1 + n2;
//        case '-' :
//            return n1 - n2;
//        case '*' :
//            return n1 * n2;
//        case '/' :
//            return n1 / n2;
//    }
//    return -1;
//}
//void collectionSort(vector<int> &sq,int a1,int a2,int b1,int b2)
//{
//    while(1)
//    {
//        if(a1 > a2 || b1 > b2)
//            break;
//        if(sq[a1] >= sq[b1])
//        {
//            a1++;
//        }
//        else{
//            int pause = sq[b1];
//            sq.erase(sq.begin() + b1);
//            sq.insert(sq.begin() + a1,pause);
//            a1++;
//            b1++;
//            a2++;
//        }
//    }
//}
//void mergeSort(vector<int> &sq)
//{
//    clock_t current,last;
//    current = clock();
//    int length = sq.size();
//    my_Queue q;
//    for(int i = 0;i < length;i++)
//    {
//        q.enQueue(i);
//        q.enQueue(i);
//    }
//    while(q.getlength() > 2)
//    {
//        int a1,a2,b1,b2;
//        q.deQueue(&a1);
//        q.deQueue(&a2);
//        q.getHead(&b1);
//        if(b1 - 1 == a2)
//        {
//            q.deQueue(&b1);
//            q.deQueue(&b2);
//            collectionSort(sq,a1,a2,b1,b2);
//            q.enQueue(a1);
//            q.enQueue(b2);
//        } else{
//            q.enQueue(a1);
//            q.enQueue(a2);
//        }
//    }
//    last = clock();
//    printf("Merge Sort Finish.");
//    cout<<"Using "<<last - current<<endl;
//}
//void selectionSort(vector<int> &sq)
//{
//    clock_t current,last;
//    current = clock();
//    int times = sq.size();
//    int max;
//    int max_site;
//    for(int i = 0;i < times;i++)
//    {
//        max = sq[i];
//        for(int j = i + 1;j < times;j++)
//        {
//            if(sq[j] < max)
//            {
//                max = sq[j];
//                max_site = j;
//            }
//        }
//        sq[max_site] = sq[i];
//        sq[i] = max;
//    }
//    last = clock();
//    printf("Selection Sort Finish.");
//    cout<<"Using "<<last - current<<endl;
//}
//void bubbleSort(vector<int> &sq)
//{
//    clock_t current,last;
//    current = clock();
//    int times = sq.size();
//    for(int i = 0;i < times;i++)
//    {
//        for(int j = times;j > i;j--)
//        {
//            if(sq[j] < sq[j - 1])
//            {
//                int pause = sq[j];
//                sq[j] = sq[j - 1];
//                sq[j - 1] = pause;
//            }
//        }
//    }
//    last = clock();
//    printf("Bubble Sort Finish.");
//    cout<<"Using "<<last - current<<endl;
//}
//bool straightSort(vector<int> &sq)
//{
//    clock_t current,last;
//    current = clock();
//    int times = sq.size();
//    for(int i = 1;i < times;i++)
//    {
//        for(int k = 0;k < i;k++)
//        {
//            if(sq[k] > sq[i])
//            {
//                int nm = sq[i];
//                sq.erase(sq.begin() + i);
//                sq.insert(sq.begin() + k,nm);
//                break;
//            }
//        }
//    }
//    last = clock();
//    printf("Straight Sort Finish.");
//    cout<<"Using "<<last - current<<endl;
//
//    return true;
//}
//int changeSort(vector<int> &sq,int bin,int end)
//{
//    if((end - bin) <= 1)
//    {
//        if(bin >= end)
//            return -1;
//        if(sq[bin] < sq[end])
//        {
//            int pause = sq[bin];
//            sq[bin] = sq[end];
//            sq[end] = pause;
//        }
//        return -1;
//    }
//    int pause = sq[bin];
//    sq.erase(sq.begin() + bin);
//    int i = bin;
//    int k = end - 1;
//    while(1)
//    {
//        if(i >= k)
//        {
//            if(sq[i] <= pause)
//            {
//                k = i;
//            } else{
//                k++;
//                i = k;
//            }
//            sq.insert(sq.begin() + k,pause);
//            break;
//        }
//        if(sq[k] > pause)
//        {
//            k--;
//            continue;
//        }
//        if(sq[i] > pause)
//        {
//            int data = sq[k];
//            sq[k] = sq[i];
//            sq[i] = data;
//            k--;
//            i++;
//        } else{
//            i++;
//            continue;
//        }
//    }
//
//    return k;
//}
//bool fastSort(vector<int> &sq)
//{
//    clock_t current,last;
//    current = clock();
//    queue<int> q;
//    q.push(0);
//    q.push(sq.size() - 1);
//    while(!q.empty())
//    {
//        int bin,end;
//        bin = q.front();
//        q.pop();
//        end = q.front();
//        q.pop();
//        int middle = changeSort(sq,bin,end);
//        if(middle != -1)
//        {
//           q.push(bin);
//           q.push(middle - 1);
//           q.push(middle + 1);
//           q.push(end);
//        }
//    }
//    last = clock();
//    cout<<"Faste Sort Finish.Using "<<last - current<<endl;
//}
//void swap(int *num1,int * num2)
//{
//    int pause = *num1;
//    *num1 = *num2;
//    *num2 = pause;
//}
//int maxHeap(vector<int> &sq,int bin,int end)
//{
//    int end1 =  2 * bin + 1;
//    if(end1 >= end)
//    {
//        return -1;
//    }
//    if(end1 + 1 < end && sq[end1] < sq[end1 + 1])
//    {
//        end1++;
//    }
//    if(sq[end1] > sq[bin])
//    {
//        swap(&sq[end1],&sq[bin]);
//        return end1;
//    }
//    return -1;
//}
//bool heapSort(vector<int> &sq)
//{
//    clock_t current,last;
//    current = clock();
//    int i = (int)(sq.size() / 2);
//    int end = sq.size();
//    while(i >= 0)
//    {
//        int k;
//        k = maxHeap(sq, i,end);
//        while(k > 0)
//        {
//            k = maxHeap(sq,k,end);
//        }
//        i--;
//    }
//    while(1)
//    {
//        /*cout<<endl;
//        for(int i = 0;i < sq.size();i++)
//        {
//            cout<<sq[i]<<" ";
//            if((i % 10) == 9)
//                cout<<endl;
//        }*/
//        int pause = sq[0];
//        swap(&sq[0],&sq[end - 1]);
//        if(end == 1)
//            break;
//        end--;
//        int k = maxHeap(sq,0,end);
//        while(k > 0)
//        {
//            k = maxHeap(sq,k,end);
//        }
//    }
//    last = clock();
//    cout<<"HeapSort Finish.Using "<<last - current<<endl;
//}
//bool radixSort(std::vector<int> &sq,int n)
//{
//    clock_t current,last;
//    current = clock();
//    vector<int> pauses[10];
//    int k = 0;
//    while(k < n)
//    {
//        while(!sq.empty())
//        {
//            int nm = sq.back();
//            int st = nm;
//            for(int j = 0;j < k;j++)
//            {
//                st /= 10;
//            }
//            sq.pop_back();
//            pauses[st % 10].push_back(nm);
//        }
//        k++;
//        for(int i = 0;i < 10;i++)
//        {
//            while(!pauses[i].empty())
//            {
//                sq.push_back(pauses[i].back());
//                pauses[i].pop_back();
//            }
//        }
//    }
//    last = clock();
//    cout<<"RadixSort Finish.Using "<<last - current<<endl;
//
//    return true;
//}