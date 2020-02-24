//
// Created by 97927 on 2019/12/24.
//
#include <iostream>
#include <cstdlib>
#include "my_BinaryTree.h"
#include <vector>
#include <fstream>
#define TOT 126 - 10
//#define YTD

using namespace std;
//sort as weight
bool sortVector(vector<my_BinaryTree *> &huff)
{
    int length = huff.size();
    for(int k = 0;k < length;k++)
    {
        int minW = huff[k]->getWeight();
        int minS = k;
        for(int i = k + 1;i < length;i++)
        {
            if(huff[i]->getWeight() > minW)
            {
                minW = huff[i]->getWeight();
                minS = i;
            }
        }
        if(minS == k)
            continue;
        my_BinaryTree * pause_tree = huff[minS];
        huff.erase(huff.begin() + minS);
        huff.insert(huff.begin() + k,pause_tree);
    }
    return true;
}
//create huffman tree
bool huffmanEnCode(vector<my_BinaryTree *> &huff)
{
    int length = huff.size();
    sortVector(huff);
    while(true)
    {
        //create new tree
        my_BinaryTree * p = new my_BinaryTree('\0');
        //insert the two min weight
        p->inserChild(0,0,huff.back());
        huff.pop_back();
        p->inserChild(0,1,huff.back());
        huff.pop_back();
        length = huff.size();
        if(length == 0)
        {
            huff.push_back(p);
            break;
        }
        for(int i = 0;i < length;i++)
        {
            if(huff[i]->getWeight() < p->getWeight())
            {
                huff.insert(huff.begin() + i,p);
                break;
            }
        }
        if(p->getWeight() < huff.back()->getWeight())
        {
            huff.push_back(p);
        }
    }

    return true;
}

#ifndef YTD
int main() {
    //open read file to code
    ifstream in("txtsourse.txt");
    if(!in.is_open())
    {
        cout<<"Open fails."<<endl;
        return 0;
    }
    //courn and haxi exchange
    int courn[TOT] = {0};
    //to create a hufftree
    vector<my_BinaryTree *> huff;
    //store every letter
    vector<my_BinaryTree *> huff_letter;
    //calculate the letter
    char ch;
    while (!in.eof()) {
        in.get(ch);
        courn[ch - '\n']++;
    }
    //create tree
    for (int i = 0; i < TOT; i++)
    {
        if(courn[i] == 0)
            continue;
        my_BinaryTree * p = new my_BinaryTree('\n' + i,courn[i]);
        courn[i] = huff.size();
        huff.push_back(p);
        huff_letter.push_back(p);
    }
    in.close();
    //create huffman tree
    huffmanEnCode(huff);
    //code letter
    huff[0]->coding("huffman.txt");
    //code to file
    std::string infile("example/tesk.txt");
    std::string outfile("example/re.txt");
    ifstream inf(infile);
    ofstream outf(outfile);
    //ofstream outf(outfile);
    unsigned int nm = 0;
    int times = 0;
    int m = 1;
    while(!inf.eof())
    {
        inf.get(ch);
        int site = courn[ch - '\n'];
        std::string pause = huff_letter[courn[ch - '\n']]->getCode();
        for(int i = 0;i < pause.size();i++)
        {
            if(pause[i] == '1')
            {
                nm += 1;
            }
            times++;
            if(times == 32)
            {
                outf<<nm<<endl;
                nm = 0;
                times = 0;
                m++;
            }
            else{
                nm *= 2;
            }
        }
    }
    if(time != 0)
   {
        for(int k = times;k < 31;k++)
            {
                nm *= 2;
            }
   }
    outf<<nm<<endl;
    inf.close();
    outf.close();
    huff[0]->deCodeFile("example/re.txt");

    return 0;
}

#endif