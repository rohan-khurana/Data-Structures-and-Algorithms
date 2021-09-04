#include<bits/stdc++.h>
using namespace std;

#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

pair<int,int> search(vector<vector<int> >& arr, int target){
    int m=arr.size();
    int n=arr[0].size();
    pair<int,int> ans;
    int l=0;
    int h=(m*n)-1;

    while(l<=h){
        int mid=l+(h-l)/2;
        if(arr[mid/m][mid%m]==target){
            return make_pair(mid/m,mid%m);
        }
        if(arr[mid/m][mid%m]<target){
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }
    return make_pair(-1,-1);
}

int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>> arr(n,vector<int>(n,0));
    int target;
    pair<int,int> ans;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    cin>>target;
    
    ans=search(arr,target);
    cout<<"("<<ans.first<<","<<ans.second<<")";
    return 0;
}