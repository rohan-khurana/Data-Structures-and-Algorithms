#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nearestGreaterToLeft(vector<int>& arr){
    stack<int> s;
    vector<int> v;
    for(int i=0;i<arr.size();i++){
        if(s.size()==0){
            v.push_back(-1);
        }
        else if(s.size()>0 && s.top()>arr[i]){
            v.push_back(s.top());
        }
        else if(s.size()>0 && s.top()<arr[i]){
            while(s.size()>0 && s.top()<=arr[i]){
                s.pop();
            }
            if(s.size()==0)
                v.push_back(-1);
            else
                v.push_back(s.top());
        }
        s.push(arr[i]);
    }
    return v;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n), v(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    v=nearestGreaterToLeft(arr);
    for(int i:v)
        cout<<i<<" ";
}