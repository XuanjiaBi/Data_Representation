//xb4syf
//Xuanjia Bi 1/23/22
#include "bankAccount.h"
#include<iostream>
#include<string>
using namespace std;

bankAccount::bankAccount(){
  balance = 0.00;
}
bankAccount::bankAccount(double n){
  balance = n;
}
bankAccount::~bankAccount(){
  // implement as empty
}
double bankAccount::withdraw(double n){
  if(n>balance){
      
    return balance;
  }
  else{
      balance = balance - n;
    return balance;
  }
}
double bankAccount::deposit(double n){
    balance = balance+n;
  return balance;
}
double bankAccount::getBalance(){
  return balance;
}
