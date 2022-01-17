#include<iostream>
#include<vector>

using namespace std;

int nearlySortedBS(vector<int>& arr, int start, int end, int ele){
    while(start<=end){
        int mid=start+(end-start)/2;
        if(ele==arr[mid])
            return mid;
        
        if(mid-1>=start && arr[mid-1]==ele)
            return mid-1;

        if(mid+1<=end && arr[mid+1]==ele)
            return mid+1;
        
        if(ele<arr[mid]){
            end=mid-2;
        }
        else{
            start=mid+2;
        }
    }
    return -1;
}

int main(){
    int n,ele;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
    cin>>arr[i];
    }
    cin>>ele;
    cout<<nearlySortedBS(arr,0, arr.size()-1, ele);
}