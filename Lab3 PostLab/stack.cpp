#include "stack.h"
using namespace std;

Stack::Stack(){
    //stack stk = new stack();
    l = new List(); // to use the new
}
Stack::~Stack(){
    delete l;
    //stack stk = new stack();
}
void Stack::push(int e){
    ListItr firstPosition = ListItr(l->head->next);
    l->insertBefore(e,firstPosition);
}
void Stack::pop(){
    ListItr firsPosition = ListItr(l->head->next);
    //** Repeated elements?
    int x = firsPosition.retrieve();
    //Always remove the first one even there are repeated elements?
    l->remove(x);
}
int Stack::top(){
    ListItr firsPosition = ListItr(l->head->next);
    //** Repeated elements?
    return firsPosition.retrieve();
}
bool Stack::empty(){
    return l->isEmpty();
}
