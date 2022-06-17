//xb4syf Xuanjia Bi
//1/23/22
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include<iostream>
#include<string>
using namespace std;

class bankAccount{
 public:
  bankAccount(); //defualt constructor
  bankAccount(double amount);//with amount
  ~bankAccount();//destructor
  
  double withdraw(double amount);
  double deposit(double amount);
  double getBalance();
 private:
  double balance; 
};

#endif
