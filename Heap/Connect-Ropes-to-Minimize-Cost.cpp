#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int minimizeCost(vector<int>& arr){
    priority_queue<int,vector<int>,greater<int>> minHeap;
    for(int i=0;i<arr.size();i++)
        minHeap.push(arr[i]);
    int cost = 0;
    while(minHeap.size()>=2){
        int first=minHeap.top();
        minHeap.pop();
        int second=minHeap.top();
        minHeap.pop();
        cost = cost + first + second;
        minHeap.push(first+second);
    }
    return cost;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<minimizeCost(arr);
}