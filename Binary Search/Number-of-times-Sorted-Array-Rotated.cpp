#include<iostream>
#include<vector>

using namespace std;

int rotatedArray(vector<int>& arr){
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

}

int main(){
    int n,ele;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
    cin>>arr[i];
    }
    cout<<rotatedArray(arr);
}