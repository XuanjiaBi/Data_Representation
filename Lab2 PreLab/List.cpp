//xb4syf Xuanjia Bi List.cpp
#include"List.h"
#include<iostream>
#include<string>
using namespace std;
//Dummy node
List::List(){
    head = new ListNode();
    tail = new ListNode();
    head->next = tail;
    tail->previous = head;
    count=0;
}
List::List(const List& source){
    head=new ListNode();
    tail=new ListNode();
    head->next=tail;
    tail->previous=head;
    count=0;
    // Make a deep copy of the list
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}
List::~List(){
    // clean up the memory
    delete head;
    delete tail;
}
//change the four pointers
void List::insertAtTail(int x){
    ListNode* newNode = new ListNode();
    newNode->value = x; // set the parameter
    newNode->next = tail;
    newNode->previous = tail->previous;
    tail->previous->next = newNode;
    tail->previous = newNode;
    count ++;
}
List& List::operator=(const List& source) {
    if (this == &source) {
        // The two are the same list; no need to do anything
        return *this;
    } else {
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();
        // Make a deep copy of the list
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}
void List::remove(int x){
}
ListItr List::find(int x){
    ListItr iter = ListItr();
    return iter;
}
int List::size() const{
    //**
    //Do I need to make a new list then do the count?? (is iter.moveForward going to ruin the order?)
    //int counter = 0;
    //ListItr iter(head->next); // the first pointer
    //while(!iter.isPastEnd(){
    //  counter++;
    //    iter.moveForward;
    //}
    return count;
}
//* thoughts: just return the pointer that is the first
ListItr List::first(){
    ListItr iter = ListItr();
    iter = this->head->next;
    return iter;
}
ListItr List::last(){
    ListItr iter = ListItr();
    iter = this->tail->previous;
    return iter;
}
bool List::isEmpty() const{
    if(head->next == tail){
        return true;
    }
    else return false;
}
void List::makeEmpty(){
    delete this;
}
void List::insertAfter(int x, ListItr position){}
void List::insertBefore(int x, ListItr position){}
void printList(List& source, bool forward){
    //***
    ListItr iter = ListItr();
    iter = source.first();
    if(source.isEmpty()){
        cout<<"Sorry, this is a empty list"<<endl;
    }
    if(forward){
        while (!iter.isPastEnd()){
            cout<<iter.retrieve()<<endl;
            iter.moveForward();
        }
    }
    if(!forward){
        while(!iter.isPastBeginning()){
            cout<<iter.retrieve()<<endl;
            iter.moveBackward();
        }
    }
}
