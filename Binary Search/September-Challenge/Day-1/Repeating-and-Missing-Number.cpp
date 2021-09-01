#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    unordered_map<int,bool> mp;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(mp.find(arr[i])==mp.end()){
            mp[arr[i]]=true;
        }
        else{
            cout<<"Repeating: "<<arr[i];
        }

    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        if(mp.find(i)==mp.end()){
            cout<<"Missing: "<<i;
        }
    }
}