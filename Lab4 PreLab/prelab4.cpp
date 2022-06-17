//xb4syf Xuanjia Bi; prelab4.cpp
#include <iostream>
#include <string>
using namespace std;
void sizeOfTest(){
    cout<<"Size of int: "<< sizeof(int)<<endl;
    cout<<"Size of unsigned int: "<< sizeof(unsigned int)<<endl;
    cout<<"Size of float: "<< sizeof(float)<<endl;
    cout<<"Size of double: "<<sizeof(double)<<endl;
    cout<<"Size of char: "<<sizeof(char)<<endl;
    cout<<"Size of bool: "<<sizeof(bool)<<endl;
    cout<<"Size of int*: "<<sizeof(int*)<<endl;
    cout<<"Size of char*: "<<sizeof(char*)<<endl;
    cout<<"Size of double*: "<<sizeof(double*)<<endl;
    //cout<<"."<<endl;
}
void overflow(){
    //Thought: to make a int 0, and max = 0-1;
    unsigned int x = 0;
    //**? check why tho
    //**? should I use some package method (climits: UINT_MAX) that is directly call max
    unsigned int max = x-1; //
    //Instead it return 0
    unsigned int result = max + 1;
    //cout<<"the max for int in decimal is "<< max<< endl;
    cout<<max<<" + 1 = "<< result<< endl;
    //cout<<"."<<endl;
}
void outputBinary(int x){
    char reprRaw[33] =  "00000000000000000000000000000000";
    //char repr[33] = {0};
    //cout<<reprRaw<<endl;
    int size = 0;
    for (int tmp = x; tmp; tmp >>= 1)
        size++;
    for (int i = 0; i < size; i++){
        /* There is some original thoughts:
         string[] -- "00000.."
         //string temp;
         for(index--):
             if(x=0): string[last] = 0;
             if(x=1): string[last] = 1;
             if(int x%2==1): string[index] 3= 1 ...;
             else: string[index] = 0 ;
             x=x/2;
         */
        // using bit shifting
        // ?: inspired by one of the TA --> I actually like the one liner mothod; but there are some mods including index changed to match up the requirement//
            reprRaw[i+32-size] = ((x >> (size - i - 1)) & 1) ? '1' : '0';
            
    }
    //cout << reprRaw << endl;
    //adding space between;
    for(int i = 0;i<=31;i++){
        cout<<reprRaw[i];
        if((i+1)%4==0 && i!= 31){
            cout<<' ';
        }
    }
    cout<<endl;
}

int main(){
    int x;
    cin>>x;
    sizeOfTest();
    overflow();
    outputBinary(x);
    //
  return 0;
}
