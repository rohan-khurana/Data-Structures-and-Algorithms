#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stack>

using namespace std;

stack<int> s,ss;

void pushOpr(int a){
    s.push(a);
    if(ss.empty() || ss.top()>a)
        ss.push(a);
}

int popOpr(){
    if(s.empty())
        return -1;
    int ans=s.top();
    s.pop();
    if(ss.top()==ans)
        ss.pop();
    return ans;
}

int minElement(){
    if(ss.size()==0)
        return -1;
    return ss.top();
}

void printStack(){
    if (s.empty())
        return;
    int x = s.top();
    s.pop();
    printStack();
    cout<<x<<" ";
    s.push(x);
}

int main(){
    int n,a;
    while(true){
        cout<<"\nStack Operations\n1. Push\n2. Pop\n3. Min Element\n4. Print Stack\n5. Stop\n";
        cin>>n;
        switch(n){
            case 1: cin>>a;
                    pushOpr(a);
                    cout<<"Pushed "<<a<<endl;
                    break;
            case 2: cout<<"Popped "<<popOpr()<<endl;
                    break;
            case 3: cout<<"Minimum Element "<<minElement()<<endl;
                    break;
            case 4: cout<<"Stack ";
                    printStack();
                    break;
            case 5: exit(0);
            default: cout<<"Wrong Input "<<endl;
            
        }
    }
}