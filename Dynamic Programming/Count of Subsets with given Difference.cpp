#include <bits/stdc++.h>
#include<iostream>
using namespace std;

int countOfSubsetSum(vector<int>& arr, int sum, int n){
	vector<vector<int> > dp(n+1, vector<int>(sum+1,0));
	for(int i=0;i<n+1;i++){
		dp[i][0]=1;
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<sum+1;j++){
			if(arr[i-1]<=j){
				dp[i][j]=dp[i-1][j-arr[i-1]] + dp[i-1][j];
			}
			else
				dp[i][j]=dp[i-1][j];
		}
	}
	for(int i=0;i<n+1;i++){
		for(int j=0;j<sum+1;j++){
			cout<<dp[i][j]<<"  ";
		}
		cout<<"\n";
	}
	return dp[n][sum];
}

int countOfSubsetSumDiff(vector<int>& arr, int diff, int n){
	int sum;
	for(int i=0;i<n;i++){
		sum+=arr[i];
	}
	sum=(diff+sum);
	sum/=2;
	return countOfSubsetSum(arr, sum, n);
}

int main(void){
	int n,diff;
	cout<<"Size:";
	cin>>n;
	vector<int> arr(n);
	cout<<"Enter Elements:\n";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"Enter Difference:";
	cin>>diff;
	cout<<"\nNumber of Subsets: "<<countOfSubsetSumDiff(arr,diff,n);
	return 0;
}
