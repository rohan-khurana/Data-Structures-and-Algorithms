#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<math.h>

using namespace std;

void kClosestNumbers(vector<int>& arr, int n, int k, int x){
    priority_queue<pair<int,int>> maxHeap;
    for(int i=0;i<n;i++){
        maxHeap.push(make_pair(abs(arr[i]-x), arr[i]));
        if(maxHeap.size() > k){
            maxHeap.pop();
        }
    }
    while(!maxHeap.empty()){
        cout<<maxHeap.top().second<<" ";
        maxHeap.pop();
    }
}

int main(){
    int n,k,x;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>k;
    cin>>x;
    kClosestNumbers(arr,n,k,x);
}