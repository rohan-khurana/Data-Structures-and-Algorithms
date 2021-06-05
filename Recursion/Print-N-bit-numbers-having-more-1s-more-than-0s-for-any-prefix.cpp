#include<iostream>
#include<string>

using namespace std;

void printBinaryNumber(int ones, int zeroes, int n, string op){
    if(n==0){
        cout<<op<<"  ";
        return;
    }
    string op1=op;
    op1.push_back('1');
    printBinaryNumber(ones+1, zeroes, n-1, op1);
    if(ones>zeroes){
        string op2=op;
        op2.push_back('0');
        printBinaryNumber(ones, zeroes+1, n-1, op2);
    }
    return;
}

int main(){
    int n;
    cin>>n;
    int ones=0;
    int zeroes=0;
    string op="";
    printBinaryNumber(ones, zeroes, n, op);
}