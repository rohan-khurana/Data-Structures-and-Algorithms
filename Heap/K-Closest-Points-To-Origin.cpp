#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

void kClosestPointsToOrigin(vector<vector<int>> arr, int n, int k){
    priority_queue<pair<int,pair<int,int>>> maxHeap;
    for(int i=0;i<n;i++){
        maxHeap.push(make_pair(arr[i][0]*arr[i][0] + arr[i][1]*arr[i][1], make_pair(arr[i][0],arr[i][1])));
        if(maxHeap.size() > k){
            maxHeap.pop();
        }
    }
    while(!maxHeap.empty()){
        pair<int,int> p = maxHeap.top().second;
        cout<<"{"<<p.first<<","<<p.second<<"} ";
        maxHeap.pop();
    }
}

int main(){
    int n,k;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>arr[i][0]>>arr[i][1];
    }
    cin>>k;
    kClosestPointsToOrigin(arr,n,k);
}