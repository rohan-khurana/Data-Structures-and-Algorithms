#include<iostream>
#include<vector>
#include<climits>
using namespace std;

char nextAlphabetElement(vector<char>& arr, int start, int end, char ele){
    char result='#';
    while(start<=end){
        int mid= start+(end-start)/2;
        if(arr[mid]<=ele){
            start=mid+1;
        }
        else{
            result=arr[mid];
            end=mid-1;
        }
    }
    return result;
}

int main(){
    int n;
    char ele;
    cin>>n;
    vector<char> arr(n);
    for(int i=0;i<n;i++){
    cin>>arr[i];
    }
    cin>>ele;
    cout<<nextAlphabetElement(arr,0,arr.size()-1,ele);
}