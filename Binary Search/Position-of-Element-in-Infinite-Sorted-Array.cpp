#include<iostream>
#include<vector>

using namespace std;

int BSinInfinite(vector<int>& arr, int start, int end, int ele){
    //define end index in infinite array
    while(ele>arr[end]){
        start=end;
        end*=2;
    }

    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==ele){
            return mid;
        }
        else if(arr[mid]>ele){
            end=mid-1;
        }
        else{
            start=mid+1;
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
    cout<<BSinInfinite(arr,0,1,ele);
}