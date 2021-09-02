#include<bits/stdc++.h>
using namespace std;

#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void nextPermutation(vector<int>& arr){
    int i,j;
    for(i=arr.size()-2;i>=0;i--){
        if(arr[i]<arr[i+1])
            break;
    }
    if(i<0){
        reverse(arr.begin(),arr.end());
    }
    else{
        for(j=arr.size()-1;j>i;j--){
            if(arr[j]>arr[i])
                break;
        }
        swap(&arr[i],&arr[j]);
        reverse(arr.begin()+i+1,arr.end());
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    nextPermutation(arr);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}