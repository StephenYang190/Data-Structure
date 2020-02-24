//
// Created by 97927 on 2019/12/13.
//

#ifndef DESIGN_FUNCTION_H
#define DESIGN_FUNCTION_H

#include <string>
#include <vector>
#include <queue>
#include <stack>
#define LENG 100

std::string getString(const std::string& out = "name");
int getInt(const std::string& out = "name");
float getFloat(const std::string& out = "name");
bool compareOperate(char c1,char c2);//true c2 > c1
double computeTwoNumber(double n1,double n2,char c1);
void mergeSort(std::vector<int> &sq);
void selectionSort(std::vector<int> &sq);
void bubbleSort(std::vector<int> &sq);
bool fastSort(std::vector<int> &sq);
bool heapSort(std::vector<int> &sq);
bool radixSort(std::vector<int> &sq,int n);
bool straightSort(std::vector<int> &sq);
bool shellSort(std::vector<int> &sq);
#endif //DESIGN_FUNCTION_H
