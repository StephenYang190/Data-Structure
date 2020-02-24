//
// Created by YTD on 2019/12/19.
//
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "stack"
#include "my_stack.h"
#include <string>
#include "function.h"

using namespace std;
//#define YTD
double midToOut(string str)
{
    stack<char> oprt1;// stack operators
    my_stack nmb;// stack number
    int i = str.find('#');//find first #
    if(i == string::npos)//do not have #
    {
        cout<<"Don't have # at beginning."<<endl;
        return -1;
    }

    int len = str.length();
    i++;
    while(i < len)
    {
        //output the char this circle get and the stack number
        cout<<"deal with \""<<str[i]<<"\""<<endl;
        cout<<"now stack of num :"<<endl;
        nmb.traverse();
        cout<<endl;
        //if the char is # , end
        if(str[i] == '#')
        {
            break;
        }
        //generate number
        if(str[i] >= '0' && str[i] <= '9')
        {
            double integer = 0;
            double decimal = 0;
            bool flag = true;
            for(double k = 0.1;str[i] == ' ' || str[i] == '.' ||(str[i] >= '0' && str[i] <= '9');i++) {
                if (str[i] == ' ')//skip the blanket
                    continue;
                if(str[i] == '.')//sign of the decimal part
                {
                    flag = false;
                    continue;
                }
                if(str[i] - '0' > 9)
                {
                    cout<<"enter wrong operate."<<endl;
                    return -1;
                }
                if (flag)
                {
                    integer *= 10;
                    integer += str[i] - '0';
                } else{
                    decimal += (str[i] - '0') * k;
                    k *= 0.1;
                }
            }
            nmb.push(integer + decimal);
            continue;//do not need to add i
        }
        //skip the blanket
        else if(str[i] == ' '){
        }
        //right brackets
        else if(str[i] == ')')
        {
            if(oprt1.empty())
            {
                cout<<"Don have enough (."<<endl;
                return -1;
            }
            char pause = oprt1.top();
            while(pause != '(')
            {
                //do not have enough numberd
                if(nmb.getlength() < 2)
                {
                    cout<<"Too many operators."<<endl;
                    return -1;
                }
                double n1 = nmb.pop();
                double n2 = nmb.pop();
                n1 = computeTwoNumber(n2,n1,pause);
                if(n1 == -65535)
                {
                    cout<<"divide by 0"<<endl;
                    return -1;
                }
                nmb.push(n1);
                oprt1.pop();
                if(oprt1.empty())
                {
                    cout<<"Don have enough (."<<endl;
                    return -1;
                }
                pause = oprt1.top();
            }
            oprt1.pop();
        }
        //operators + - / * (
        else if(str[i] == '(' || str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*'){
            char pause;
            if(!oprt1.empty())
                pause = oprt1.top();
            //empty or left brackets add
            if(oprt1.empty() || pause == '(' || str[i] == '(')
            {
                oprt1.push(str[i]);
            } else if(compareOperate(pause,str[i]))
            {
                oprt1.push(str[i]);
            } else{
                while(!compareOperate(pause,str[i]))
                {
                    if(nmb.getlength() < 2)
                    {
                        cout<<"Too many operators."<<endl;
                        return -1;
                    }
                    double n1 = nmb.pop();
                    double n2 = nmb.pop();
                    n1 = computeTwoNumber(n2,n1,pause);
                    if(n1 == -65535)
                    {
                        cout<<"divide by 0"<<endl;
                        return -1;
                    }
                    nmb.push(n1);
                    oprt1.pop();
                    if(oprt1.empty())
                        break;
                    pause = oprt1.top();
                }
                oprt1.push(str[i]);
            }
        }
        //other opraters
        else{
            cout<<"enter wrong operate."<<endl;
            return -1;
        }
        i++;
    }
    //finish the handle of string
    while(!oprt1.empty())
    {
        char pause = oprt1.top();
        cout<<"deal with "<<pause<<endl;
        if(pause == '(')
        {
            cout<<"Dont't enough )."<<endl;
            return -1;
        }
        if(nmb.getlength() < 2)
        {
            cout<<"End by operator."<<endl;
            return -1;
        }
        double n1 = nmb.pop();
        double n2 = nmb.pop();
        n1 = computeTwoNumber(n2,n1,pause);
        if(n1 == -65535)
        {
            cout<<"divide by 0"<<endl;
            return -1;
        }
        nmb.push(n1);
        oprt1.pop();
        cout<<endl<<"stack of num :"<<endl;
        nmb.traverse();
    }
    return nmb.getTop();
}
#ifndef YTD
int main()
{
    std::string str = getString("calculation(below 20,ignore all blanket)");
    my_stack nmb;
    cout<<str<<endl;
    double outcome = midToOut(str);
    if(outcome != -1)
    {
        cout<<"The outcome is "<<outcome<<endl;
    } else{
        cout<<"Error"<<endl;
    }


    return 0;
}
#endif