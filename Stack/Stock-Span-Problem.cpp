#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

vector<int> stockSpanProblem(vector<int> arr,int n){
    stack<pair<int,int>> s;
    vector<int> v;
    for(int i=0;i<n;i++){
        if(s.size()==0){
            v.push_back(-1);
        }
        else if(s.size()>0 && s.top().first>arr[i]){
            v.push_back(s.top().second);

        }
        else if(s.size()>0 && s.top().first<=arr[i]){
            while(s.size()>0 && s.top().first<=arr[i]){
                s.pop();
            }
            if(s.size()==0){
                v.push_back(-1);
            }
            else{
                v.push_back(s.top().second);
            }
        }
        s.push(make_pair(arr[i],i));
    }
    for(int i=0;i<v.size();i++){
        v[i]=i-v[i];
    }
    return v;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n),v(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    v=stockSpanProblem(arr,n);
    for(int i : v){
        cout<<i<<" ";
    }
}