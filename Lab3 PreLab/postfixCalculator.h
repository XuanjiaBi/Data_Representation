#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H
#include <stack>
#include <iostream>
using namespace std;

class postfixCalculator{
public:
    postfixCalculator();
    //PostfixCalculator(const PostfixCalculator& source);
    //~PostfixCalcualtor();
    //postfixCalculator& operator = (const PostfixCalculator& source);
    void addition();
    void subtraction();
    void multiplication();
    void push(int x);
    void division();
    void negation();
    bool empty();
    int top();
private: // why such intance is set to private like ListNode/ List calss
    stack<int> stk;
};

#endif
