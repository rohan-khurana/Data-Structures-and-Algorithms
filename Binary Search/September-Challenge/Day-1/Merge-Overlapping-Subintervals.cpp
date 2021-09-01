#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& arr){
    vector<vector<int>> ans;
    if(arr.size()==0){
        return ans;
    }
    sort(arr.begin(),arr.end());

    vector<int> temp=arr[0];
    for(auto i:arr){
        if(i[0]<=temp[1]){
            temp[1]=max(i[1],temp[1]);
        }
        else{
            ans.push_back(temp);
            temp=i;
        }
    }
    ans.push_back(temp);
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(2,0));
    for(int i=0;i<n;i++){
        cin>>arr[i][0];
        cin>>arr[i][1];
    }
    vector<vector<int>> ans=merge(arr);
    cout<<"[";
    for(int i=0;i<n;i++){
        cout<<"["<<ans[i][0]<<","<<ans[i][1]<<"]";
    }
    cout<<"]";
    return 0;
}