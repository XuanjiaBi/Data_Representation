//Linked list function
//Xuanjia Bi
//xb4suf stack.h
/* push( int e ):
 call the List first()-> insert before
 
 bool empty() -> isempty();
 
 void pop():
 first() -> remove();
 
 int top():
 first() -> retrive();
 */

#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

#include "ListNode.h"
#include "List.h"
#include "ListItr.h"

class Stack{
public:
    Stack();
    ~Stack();
    void push(int e);
    void pop();
    int top();
    bool empty();
private:
    List* l;
};

#endif
