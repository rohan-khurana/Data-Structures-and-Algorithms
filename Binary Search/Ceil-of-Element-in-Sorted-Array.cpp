#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int ceilSortedArray(vector<int>& arr, int start, int end, int ele){
    int result=INT_MAX;
    while(start<=end){
        int mid= start+(end-start)/2;
        if(arr[mid]==ele){
            return arr[mid];
        }
        if(arr[mid]<ele){
            start=mid+1;
        }
        else{
            result=arr[mid];
            end=mid-1;
        }
    }
    return result;
}

int main(){
    int n,ele;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
    cin>>arr[i];
    }
    cin>>ele;
    cout<<ceilSortedArray(arr,0,arr.size()-1,ele);
}