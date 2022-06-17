//lab 1 xToN
//xb4syf 1/23/2022
#include<iostream>
using namespace std;

int xton(int a, int b){
    if (b==0) // When base is zero
    {
        return 1;
    }
	if(b==1) //actual base for excuting the loop
	{
		return a;
	}
    if(b<0)
    {
        cout<<"sorry, we dont consider negative power in this case"<<endl;
        return 404;
    }
	else
	{
        return(a*xton(a,b-1));
	}
}

int main(){
	int x,y,z;
	cout<<"please enter the base:"<<endl;
	cin>>x;
	cout<<"please enter the power: (non-negative integer)"<<endl;
	cin>>y;
	z = xton(x,y);
	cout<<z<<endl;
	return 0;
}
