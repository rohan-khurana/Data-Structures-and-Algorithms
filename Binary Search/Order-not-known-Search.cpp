#include<iostream>
#include<vector>

using namespace std;

int Search(vector<int>& arr, int ele){
    if(arr.size()==1){
        if(arr[0]==ele)
            return 0;
        else
            return -1;
    }
    else{
        int start=0;
        int end=arr.size()-1;
        if(arr[0]<arr[1]){
            while(start<=end){
                int mid=start+(end-start)/2;
                if(ele==arr[mid]){
                    return mid;
                }
                else if(ele<arr[mid]){
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
            return -1;
        }
        else{
            while(start<=end){
                int mid=start+(end-start)/2;
                if(ele==arr[mid]){
                    return mid;
                }
                else if(ele>arr[mid]){
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
            return -1;
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
    cin>>ele;
    cout<<Search(arr,ele);
    return 0;
}