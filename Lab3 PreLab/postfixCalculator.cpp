#include "postfixCalculator.h"

using namespace std;

postfixCalculator::postfixCalculator(){
    // set to NULL, but following line does not work
    //stk = NULL;
}
void postfixCalculator::addition(){
    if(this->empty()){
        //if stk is empty skip
    }else{
        int x = stk.top();
        stk.pop();
        int y = stk.top();
        stk.pop();
        int sum = x+y;
        stk.push(sum);
    }
}
void postfixCalculator::subtraction(){
    if(stk.empty()){
        //skip
    }else{
        int x = stk.top();
        stk.pop();
        int y = stk.top();
        stk.pop();
        int diff = y-x;
        stk.push(diff);
    }
}
void postfixCalculator::multiplication(){
    int x = stk.top();
    stk.pop();
    int y = stk.top();
    stk.pop();
    int product = x*y;
    stk.push(product);
}
void postfixCalculator::division(){
    int x = stk.top();
    stk.pop();
    int y = stk.top();
    stk.pop();
    int quot = y/x;
    stk.push(quot);
}
void postfixCalculator::negation(){
    if(stk.empty()){
        //skip
    }else{
        stk.push(stk.top()*-1); // one line could cause error
    }
}
void postfixCalculator::push(int x){
    stk.push(x);
}
int postfixCalculator::top(){
    return stk.top();
}
bool postfixCalculator::empty(){
    return stk.empty();// default as false right now;
}
