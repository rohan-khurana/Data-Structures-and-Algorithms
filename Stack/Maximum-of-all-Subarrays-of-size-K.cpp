#include<bits/stdc++.h>
using namespace std;
vector<int> KSum(vector<int>& arr, int n, int k){
    vector<int> ans;
    list<int> l;
    int i=0,j=0;
    while(j<k){
        while(l.size()>0 && l.back()<arr[j]){
            l.pop_back();
        }
        l.push_back(arr[j]);
        if(j-i+1<k){
            j++;
        }
        if(j-i+1==k)
            ans.push_back(l.front());
        if(l.front()==arr[i])
            l.pop_back();
        i++;
        j++;
    }
    return ans;
}

int main(){
    int n,k;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>k;
    vector<int> ans=KSum(arr,n,k);
    for(int i:ans){
        cout<<i<<" ";
    }
}