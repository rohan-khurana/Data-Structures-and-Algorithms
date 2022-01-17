#include<iostream>
#include<vector>

using namespace std;

int minIndex(vector<int>& arr){
    int start = 0;
    int n=arr.size();
    int end = arr.size()-1;
    while(start<=end){
        int mid=(end+start)/2;
        int next=(mid+1)%n;
        int prev=(mid+n-1)%n;
        if(arr[mid]<arr[prev]&&arr[mid]<arr[next]){
            return mid;
        }
        if(arr[start]<=arr[mid]){
            start=mid+1;
        }
        else if(arr[mid]<=arr[end]){
            end=mid-1;
        }
    }
    return -1;
}
int binarySearch(vector<int>& arr, int start, int end, int ele){
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==ele){
            return mid;
        }
        if(ele<arr[mid]){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return -1;
}
int binarySearchR(vector<int>& arr, int ele){
    int m=minIndex(arr);
    cout<<m;
    int ans=binarySearch(arr,0,m-1,ele);
    if(ans==-1)
        ans=binarySearch(arr,m,arr.size()-1,ele);
    return ans;
}
int main(){
    int n,ele;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
    cin>>arr[i];
    }
    cin>>ele;
    cout<<binarySearchR(arr,ele);
}