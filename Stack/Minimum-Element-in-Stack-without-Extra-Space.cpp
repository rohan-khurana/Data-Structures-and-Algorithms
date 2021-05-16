#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stack>

using namespace std;

int minEle=0;
stack<int> s;

int minElement(){
    if(s.size()==0){
        return -1;
    }
    return minEle;
}
void pushOpr(int x){
    if(s.size()==0){
        s.push(x);
        minEle=x;
    }
    else{
        if(x>=minEle)
            s.push(x);
        else{
            s.push((2*x)-minEle);
            minEle=x;
        }
    }
}
int topOpr(){
    if(s.size()==0)
        return -1;
    else{
        if(s.top()>=minEle)
            return s.top();
        else{
            return minEle;
        }
    }
}
int popOpr(){
    int t;
    if(s.size()==0)
        return -1;
    else{
        if(s.top()>=minEle){
            t=s.top();
            s.pop();
            return t;
        }
        else{
            t=minEle;
            minEle = 2*minEle - s.top();
            s.pop();
            return t;
        }
    }
}

int main(){
    int n,a;
    while(true){
        cout<<"\nStack Operations\n1. Push\n2. Pop\n3. Min Element\n4. Top\n5. Stop\n";
        cin>>n;
        switch(n){
            case 1: cin>>a;
                    pushOpr(a);
                    cout<<"Pushed "<<a<<endl;
                    break;
            case 2: cout<<"Popped "<<topOpr()<<endl;
                    popOpr();
                    break;
            case 3: cout<<"Minimum Element "<<minElement()<<endl;
                    break;
            case 4: cout<<"Top Element "<<topOpr()<<endl;
                    break;
            case 5: exit(0);
            default: cout<<"Wrong Input "<<endl;
            
        }
    }
}