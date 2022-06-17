#include "postfixCalculator.h"
#include <string>
#include <iostream>

using namespace std;
//** error prevention needed!! Case:
/*
 1. input has alphabet
 2. input has "-1" (my code works on this right now)
 3. # of signs and numbers mismatched
 4. other speical characters !@#$%^
 5. space (nothing)
 */

int main(){
    // all my code based on the input txt file, which I edited outside of the cpp codes.
    postfixCalculator p;
    string token;
while (cin >> token) {
    // string -> char:
    const char* arr_char = token.c_str();
    // need to design a error prevention tho
    //check two situation:
    //if char is size of
    int size = token.size();
    if(token == "~"){
        p.negation();
        //cout<<"negation "<<p.top()<<endl;
     }
    else if(token == "+"){
        p.addition();
        //cout<<"addition"<<p.top()<<endl;
    }
    else if(token == "-"){
        p.subtraction();
        //cout<<"subtraction"<<p.top()<<endl;
     }
    //input whatever the number is
    //** error prevention needed!! **
    else if(token == "*"){
        p.multiplication();
    }
    else if(token == "/"){
        p.division();
    }
    else {// might need to change
        int x = atoi(arr_char);
        p.push(x);
        //cout<<"input number"<<p.top()<<endl;
      }
    }
    //cout << "Final Result: " << p.top() << endl;
    cout << p.top() << endl;
    return 0;
}

