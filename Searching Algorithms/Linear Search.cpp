#include<iostream>
using namespace std;

int linearSearch(int arr[], int n, int x){
  for(int i = 0; i<n; i++){
  if(arr[i]==x)
    return i;
  }
  return -1;
}

int main(){
  int arr[], n, x;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cout<<linearSearch(arr, n, x);
}
