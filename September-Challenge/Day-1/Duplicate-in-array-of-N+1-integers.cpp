#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int duplicate(vector<int>& arr){
    int slow=arr[0];
    int fast=arr[0];
    do{
        slow=arr[slow];
        fast=arr[arr[fast]];
    }while(slow!=fast);
    while(slow!=fast){
        slow=arr[slow];
        fast=arr[fast];
    }
    return slow;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<duplicate(arr);
    return 0;
}