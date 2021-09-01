#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int maxSubArraySum(vector<int>& arr){
    int sum=0;
    int maxSum=INT_MIN;
    for(auto i : arr){
        sum+=i;
        maxSum=max(maxSum, sum);
        if(sum<0)
            sum=0;
    }
    return maxSum;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<maxSubArraySum(arr);
    return 0;
}