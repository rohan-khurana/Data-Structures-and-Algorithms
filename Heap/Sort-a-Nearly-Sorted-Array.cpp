#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
//Complexity: O(nlogk)

int sortK(vector<int>& arr, int n, int k){
    priority_queue<int, vector<int>, greater<int>> minHeap;

    int index=0;
    for(int i=0;i<n;i++){
        minHeap.push(arr[i]);
        if(minHeap.size()>k){
            arr[index++]=minHeap.top();
            minHeap.pop();
        }
    }
    while(!minHeap.empty()){
        arr[index++]=minHeap.top();
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
    sortK(arr,n,k);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}