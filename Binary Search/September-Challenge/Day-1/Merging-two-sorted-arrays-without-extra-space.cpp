#include<iostream>
#include<vector>
using namespace std;

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void merge(vector<int> &arr1, vector<int> &arr2, int n1, int n2){
    int i=0,j=0;
    while(i<n1 && j<n2){
        if(arr1[i]<=arr2[j]){
            i++;
        }
        else if(arr1[i]>arr2[j]){
            swap(&arr1[i], &arr2[j]);
            i++;
            if(j<n2-1 && arr2[j+1]<arr2[j]){
                int key=arr2[j];
                int tj=j+1;
                while(tj<n2 && arr2[tj]<key){
                    arr2[tj-1]=arr2[tj];
                    tj++;
                }
                arr2[tj-1]=key;
            }
        }
    }
}

int main(){
    int n1,n2;
    cin>>n1;
    vector<int> arr1(n1);
    for(int i=0;i<n1;i++){
        cin>>arr1[i];
    }
    cin>>n2;
    vector<int> arr2(n2);
    for(int i=0;i<n2;i++){
        cin>>arr2[i];
    }
    merge(arr1,arr2,n1,n2);
    for(int i=0;i<n1;i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n2;i++){
        cout<<arr2[i]<<" ";
    }
    return 0;
}