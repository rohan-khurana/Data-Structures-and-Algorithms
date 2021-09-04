#include<bits/stdc++.h>
using namespace std;

#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

int majority(vector<int>& arr){
    int count=0;
    int element=0;
    for(int i : arr){
        if(count==0){
            element=i;
        }
        if(i==element)
            count+=1;
        else
            count-=1;
    }
    return element;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<majority(arr);
    return 0;
}