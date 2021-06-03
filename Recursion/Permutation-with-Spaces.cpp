#include<iostream>
#include<string>

using namespace std;

void permutationWithSpaces(string ip, string op){
    if(ip.length()==0){
        cout<<op<<" ";
        return;
    }
    string op1=op;
    string op2=op;
    op1.push_back('_');
    op1.push_back(ip[0]);
    op2.push_back(ip[0]);
    ip.erase(ip.begin()+0);

    permutationWithSpaces(ip,op1);
    permutationWithSpaces(ip,op2);
    return;
}

int main(){
    string ip;
    string op="";
    getline(cin,ip);
    op.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    permutationWithSpaces(ip,op);
}