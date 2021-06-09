#include<iostream>
#include<vector>
using namespace std;

int BinarySearchDesc(vector<int>& arr, int ele){
  int start=0;
  int end=arr.size()-1;
  while(start<=end){
    int mid= start+(end-start)/2;
    if(ele==arr[mid]){
      return mid;
    }
    else if(ele<arr[mid]){
      start=mid+1;
    }
    else{
      end=mid-1;
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
  cout<<BinarySearchDesc(arr,ele);
  return 0;
}
