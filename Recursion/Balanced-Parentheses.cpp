#include<iostream>
#include<vector>
#include<string>

using namespace std;

void solve(int open, int close, string op, vector<string>& v){
    if(open==0 && close==0){
        v.push_back(op);
        return;
    }
    if(open!=0){
        string op1=op;
        op1.push_back('(');
        solve(open-1, close, op1, v);
    }
    if(open<close){
        string op1=op;
        op1.push_back(')');
        solve(open, close-1, op1, v);
    }
    return;
}

vector<string> balancedParentheses(int n){
    int open=n;
    int close=n;
    vector<string> v;
    string op;
    solve(open, close, op, v);
    return v;
}

int main(){
    int n;
    cin>>n;
    vector<string> v;
    v=balancedParentheses(n);
    for(auto i:v){
        cout<<i<<" ";
    }
}