//xb4syf Xuanjia Bi List.cpp
#include"List.h"
#include<iostream>
#include<string>
using namespace std;
//Constructors:
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
    makeEmpty();
    delete head;
    delete tail;
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

// Insert:
//change the four pointers
void List::insertAtTail(int x) {
    ListNode* newNode = new ListNode(x);
    newNode->next = tail;
    newNode->previous = tail->previous;
    tail->previous->next = newNode;
    tail->previous = newNode;
    count++;
}
void List::insertAfter(int x, ListItr position){
    ListNode* newNode = new ListNode(x);
    newNode->next = position.current->next;
    newNode->previous = position.current;
    position.current->next = newNode;
    position.current->next->next->previous = newNode; // ** 
    count++;
}
void List::insertBefore(int x, ListItr position){
    ListNode* newNode = new ListNode(x);
    newNode->next = position.current;
    newNode->previous = position.current->previous;
    position.current->previous = newNode;
    newNode->previous->next = newNode;
    count++;
}
void List::remove(int x){
    //Question::
    //ListItr* vs ListItr
    ListItr itr = find(x);
    //***This gives me sanitizer 2 failure, but why?????????
    //remove() prevention:
    if(itr.isPastEnd()){
    }else{
        itr.current->next->previous = itr.current->previous;
        itr.current ->previous->next = itr.current->next;
        count--;
        delete itr.current;
    }
}
    //Also since its is a pointer sothat it is easier to use delete function
 //***** prevention!
ListItr List::find(int x){
    ListItr itr(head->next); // ***
    while(!itr.isPastEnd()){
        if(itr.retrieve()==x){
            return itr;
        }
        itr.moveForward();
    }
    return itr; // I honestly think should be more prvention instead of simply return the "tail"
}

int List::size() const{
    return count;
}
ListItr List::first(){
    ListItr iter = ListItr(head->next);
    return iter;
}
ListItr List::last(){
    ListItr iter = ListItr(tail->previous);
    return iter;
}
bool List::isEmpty() const{
    /*
    if(head->next == tail){
        return true;
    }
    else return false;
    */
    // better solution: to check the size only
    return count<1;
    //True: only one ndoe
    //False: more than one node (including one)
}
// Given by Prof but inspired by other TA for better coding
void List::makeEmpty(){
   // ListNode* itrPointer = head->next;
    while(!isEmpty()){
        remove(first().retrieve());
    }
    count = 0;
    head->next = tail;
    tail->previous=head;
}

void printList(List& source, bool forward){
    ListItr itr = source.first();
    if(forward){
        while (!itr.isPastEnd()){
            cout<<itr.retrieve()<<endl;
            itr.moveForward();
        }
    }
    if(!forward){
        itr = source.last();
        while(!itr.isPastBeginning()){
            cout<<itr.retrieve()<<endl;
            itr.moveBackward();
        }
    }
}
