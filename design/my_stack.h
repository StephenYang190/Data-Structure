//
// Created by 97927 on 2019/12/13.
//

#ifndef DESIGN_MY_STACK_H
#define DESIGN_MY_STACK_H

#include <vector>

class StNode{
public:
    double data;
    StNode(double n = 0);
    ~StNode();
};
class my_stack {
private:
    std::vector<StNode> frt;
    int length;
public:
    my_stack();//initial
    bool empty();//true while stack is empty
    int getlength();//get stack length at this time
    void clearStack();//clear stack
    bool getTop(double * e);//get top num and store at e
    bool getTop(int * e);
    double getTop();
    bool push(double e);//push back e
    bool push(int e);
    bool pop(double * e);//pop top elem and store at e
    double pop();
    bool pop(int * e);
    bool traverse();//show all stack elem
};


#endif //DESIGN_MY_STACK_H
