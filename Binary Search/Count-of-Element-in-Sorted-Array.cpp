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

int countOf(vector<int>& arr, int ele){
    int first=firstOccurence(arr,ele);
    int last=lastOccurence(arr,ele);
    return last-first+1;
}

int main(){
    int n,ele;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>ele;
    cout<<countOf(arr,ele);
}