#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int>& s, int k){
    if(k==1){
        s.pop();
        return;
    }
    int top=s.top();
    s.pop();
    solve(s,k-1);
    s.push(top);
}

void deleteMiddle(stack<int>& s){
    if(s.empty())
        return;
    int k = (s.size()/2)+1;
    solve(s,k);
}

void printStack(stack<int>& s){
    if (s.empty())
        return;
    int x = s.top();
    s.pop();
    printStack(s);
    cout<<x<<" ";
    s.push(x);
}

int main(){
    int n,x;
    stack<int> s;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        s.push(x);
    }
    deleteMiddle(s);
    printStack(s);
}