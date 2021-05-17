#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>

using namespace std;

void frequencySort(vector<int>& arr, int n){
    priority_queue<pair<int,int>> maxHeap;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    for(auto i=mp.begin();i!=mp.end();i++){
        maxHeap.push(make_pair(i->second,i->first));
    }
    while(!maxHeap.empty()){
        int freq=maxHeap.top().first;
        int ele=maxHeap.top().second;
        for(int i=0;i<freq;i++){
            cout<<ele<<" ";
        }
        maxHeap.pop();
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    frequencySort(arr,n);
}