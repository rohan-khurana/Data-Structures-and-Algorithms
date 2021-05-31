#include<iostream>
#include<stack>
using namespace std;

void insert(stack<int>& s, int ele){
    if(s.size()==0){
        s.push(ele);
        return;
    }
    int temp=s.top();
    s.pop();
    insert(s,ele);
    s.push(temp);
    return;
}

void reverse(stack<int>& s){
    if(s.size()==1)
        return;
    int temp=s.top();
    s.pop();
    reverse(s);
    insert(s, temp);
    return;
}

void printStack(stack<int>& s){
    if(s.empty())
        return;
    int x=s.top();
    s.pop();
    printStack(s);
    cout<<x<<" ";
    s.push(x);    
}

int main(){
    int n,x;
    cin>>n;
    stack<int> s;
    for(int i=0;i<n;i++){
        cin>>x;
        s.push(x);
    }
    reverse(s);
    printStack(s);
}