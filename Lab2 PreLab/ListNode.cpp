//xb4syf
//Xuanjia Bi 1/27/22
#include "ListNode.h"
#include<iostream>
#include<string>
using namespace std;

ListNode::ListNode(){
    value = 0;
    //set them to null first
    previous = NULL;
    next = NULL;
}
ListNode::ListNode(int n){
    value = n;
    previous = NULL;
    next = NULL;
}
ListNode::~ListNode(){
}
