#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int kthSmallest(vector<int>& arr, int k){
    priority_queue<int> maxHeap;

    for(int i=0;i<arr.size();i++){
        maxHeap.push(arr[i]);
        if(maxHeap.size() > k){
            maxHeap.pop();
        }
    }
    return maxHeap.top();
}

int main(){
    int n,k1,k2,sum=0;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>k1>>k2;
    int first = kthSmallest(arr,k1);
    int second = kthSmallest(arr,k2);
    for(int i=0;i<n;i++){
        if(arr[i]>first && arr[i]<second){
            sum+=arr[i];
        }
    }
    cout<<sum;
}