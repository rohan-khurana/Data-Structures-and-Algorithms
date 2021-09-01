#include<iostream>
#include<vector>
using namespace std;

void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void sort(vector<int>& arr, int n){
    int low=0;
    int mid=0;
    int high=n-1;
    while(mid<=high){
        switch(arr[mid]){
            case 0: swap(&arr[mid++],&arr[low++]);
                    break;
            case 1: mid++;
                    break;
            case 2: swap(&arr[mid],&arr[high--]);
                    break;
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    } 
    sort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<" ";
    } 
}