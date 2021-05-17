#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>

using namespace std;

void topKFrequentNumbers(vector<int>& arr, int n, int k){
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater< pair<int,int> > > minHeap;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    for(auto i=mp.begin();i!=mp.end();i++){
        minHeap.push(make_pair(i->second,i->first));
        if(minHeap.size()>k){
            minHeap.pop();
        }
    }
    while(!minHeap.empty()){
        cout<<minHeap.top().second<<" ";
        minHeap.pop();
    }
}

int main(){
    int n,k;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>k;
    topKFrequentNumbers(arr,n,k);
}