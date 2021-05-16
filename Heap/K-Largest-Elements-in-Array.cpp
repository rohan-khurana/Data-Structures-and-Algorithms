#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

void kLargestElements(vector<int>& arr, int n, int k){
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int i=0;i<n;i++){
        minHeap.push(arr[i]);
        if(minHeap.size()>k){
            minHeap.pop();
        }
    }
    while(!minHeap.empty()){
        cout<<minHeap.top()<<" ";
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
    kLargestElements(arr,n,k);
}