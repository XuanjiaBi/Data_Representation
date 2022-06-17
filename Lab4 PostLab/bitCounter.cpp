//Xuanjia Bi, xb4sydf; bitCounter.cpp;
#include <iostream>
#include <string>
using namespace std;

int binaryCounter(int x){
    // base case: to end the excusion;
    if(x==0) return 0;
    // Assumption: x/2 would take the floor since it is a integer oepration.
    if(x%2==1) return 1+binaryCounter(x/2);
    // No need to add on top;
    else return binaryCounter(x/2);
    // Could be more simpler in one line but go back later
}
string baseConvertion(string inputData,int startBase, int endBase){
    //convertion to decimal:
    int size = inputData.size();
    //cout<<"size:"<<size<<endl;
    int sumB_10 = 0;
    int base = 1; // start from 1;
    int tmp = 0;
    // "0-9" = ACSII(char) - 48
    //"A-Z"
    for(int i = size-1; i>=0; i--){
        //** NEED: check the boundaries!
        // bounderie checked!
        if(int(inputData[i])>=48 && int(inputData[i])<58){
            tmp = int(inputData[i])-48;
            //cout<<"dig: "<<tmp<<endl;
        }
        if(int(inputData[i])>=65 && int(inputData[i])<91){
            tmp = int(inputData[i])-55;
            //cout<<"alp: "<<tmp<<endl;
        }
        //cout<<base<<endl;
        //cout<<tmp<<endl;
        sumB_10 = sumB_10+base*tmp ;
        //cout<<sumB_10<<endl;
        base = base * startBase;//update the base each loop
    }
    //cout<<"base 10: "<<sumB_10<<endl;
    //convertion to endbase:
    int newSize=0;
    //size check:
    int sizeCheck = sumB_10;
    for(int i = 1; sizeCheck >=endBase; i++){
        sizeCheck = sizeCheck/endBase;
        newSize=i+1;
    }
    //cout<<newSize<<endl;
    //create empty string with 0;
    string s ="";
    /*for(int i = 0; i< newSize; i++){
        s = s + '0';
    }*/
    //cout<<s<<endl;
    int rmd;
    string arry [] = {"0", "1", "2", "3", "4","5","6","7","8","9","A","B","C","D","E","F","G","H","I","J","K","L","M","N", "O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    // condition filter on the num less than endBase
    if(sumB_10<endBase){
        s = arry[sumB_10];
    }else{
        //I know there are much smarter way without creating array, but I am so done!!
        // (such as int -> ACSII -> cout<< ACSII)
        for(int i=newSize;i>0;i--){
        /*if(sumB_10<endBase){
            string s_tmp = arry[sumB_10];
            s.insert(0,s_tmp);
            //cout<<s_tmp<<endl;
            //cout<<s<<endl;
        }
        else{*/
            rmd = sumB_10%endBase;
            //cout<<s[i-1]<<endl;
            /* int -> 'int':
             https://stackoverflow.com/questions/4629050/convert-an-int-to-ascii-character; */
            //if(rmd<9)
            string s_tmp = arry[rmd];
            s.insert(0,s_tmp);
            //s = s + s_tmp;
            sumB_10=(sumB_10-rmd)/endBase;
            
        }
            
        
        /*if(rmd>9 & rmd < 45)
         int tem = rmd + 55;
         //printf() could work
         char c = '0' + intToAscii(tmp);
         sumB_10=(sumB_10-rmd)/endBase;
        */
        //
        //cout<<s<<endl;
    }
    //cout<<s<<endl;
    return s;
}
int main(int argc, char **argv){
    //int input;
    //cin>> input;
    //cout<<binaryCounter(input)<<endl;
    //baseConvertion("A", 16, 10);
    //cout<<baseConvertion("2150", 10, 2);
    /*char apl_A = 'A';
    cout<<int(apl_A)<<endl;
    // return 65 -> A = 10; so that int(char) - 55;
    char dig_8 = '8';
    cout<<int(dig_8)<<endl;
    //return 56 -> int(dig)-48
    */
    //string s = "000";
    //char c = '0'+5;
    //s[1] = c;
    //cout<<s<<endl;
    //cout<<argc<<endl;
    //cout<<argv[2]<<endl;
    //cout<<argv[3]<<endl;
    cout << argv[1] << " has " << binaryCounter(atoi(argv[1])) << " bit(s)" << endl;
    cout << argv[2] << " (base " << argv[3] << ") = " << baseConvertion(argv[2], atoi(argv[3]), atoi(argv[4])) << " (base " << argv[4] << ")" << endl;
    return 0;
}
