#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int KthSmallest(vector<int>& arr, int n,int k){
    priority_queue<int> maxHeap;

    for(int i=0;i<n;i++){
        maxHeap.push(arr[i]);
        if(maxHeap.size() > k){
            maxHeap.pop();
        }
    }
    return maxHeap.top();
}

int main(){
    int n,k;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>k;
    cout<<KthSmallest(arr,n,k);
}