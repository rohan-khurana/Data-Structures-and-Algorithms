#include<iostream>
#include<vector>

using namespace std;

int firstOccurence(vector<int>& arr, int ele){
    int start=0, result=-1;
    int end=arr.size()-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(ele==arr[mid]){
            result=mid;
            end=mid-1;
        }
        else if(ele<arr[mid]){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return result;
}

int lastOccurence(vector<int>& arr, int ele){
    int start=0, result=-1;
    int end=arr.size()-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(ele==arr[mid]){
            result=mid;
            start=mid+1;
        }
        else if(ele<arr[mid]){
            end=mid-1;
        }
        else{
            start=mid+1;
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
    cout<<firstOccurence(arr,ele)<<" "<<lastOccurence(arr,ele);
}