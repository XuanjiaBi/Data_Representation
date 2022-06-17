//xb4syf Xuanjia Bi ListItr.cpp
#include"ListItr.h"
#include<iostream>
#include<string>
using namespace std;
ListItr::ListItr(){
    current = NULL;
}
ListItr::ListItr(ListNode* theNode){
    current = theNode;
}

bool ListItr::isPastEnd()const{
    //ListNode testNode = ListNode(current);
    if(current->next==NULL){
        return true;
    }
    else{
        return false;
    }
}
bool ListItr::isPastBeginning()const{
    if(current->previous==NULL){
        return true;
    }
    else return false; //I Dont know if one line works
}

void ListItr::moveForward(){
    //ListNode testNode = ListNode(current);
    //current->isPastEnd ==? current.isPastEnd
    if(!isPastEnd()){
        current = current  -> next;
    }
}
void ListItr::moveBackward(){
    //ListNode testNode = ListNode(current);
    //current->isPastEnd ==? current.isPastEnd
    if(!isPastBeginning()){
        current = current  -> previous;
    }
}
//void ListItr::moveForward(){
//    if(!current.isPastBeginning()){
//       current = current -> previous;
//    }
//}
int ListItr::retrieve() const{
    return current->value;
}
