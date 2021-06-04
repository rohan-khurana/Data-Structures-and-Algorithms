#include<iostream>
#include<vector>
#include<string>
using namespace std;

void letterCasePermutation(string ip, string op, vector<string>& v){
    if(ip.length()==0){
        v.push_back(op);
        return;
    }
    if(isalpha(ip[0])){
        string op1=op;
        string op2=op;
        op1.push_back(toupper(ip[0]));
        op2.push_back(tolower(ip[0]));
        ip.erase(ip.begin()+0);
        letterCasePermutation(ip,op1,v);
        letterCasePermutation(ip,op2,v);
        return;
    }
    else{
        string op1=op;
        op1.push_back(ip[0]);
        ip.erase(ip.begin()+0);
        letterCasePermutation(ip,op1,v);
        return;
    }
}

int main(){
    string ip;
    cin>>ip;
    string op="";
    vector<string> v;
    letterCasePermutation(ip,op,v);
    for(auto i:v){
        cout<<i<<" ";
    }
}