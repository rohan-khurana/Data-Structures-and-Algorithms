#include <bits/stdc++.h>
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

	return dp[n][sum];
}

int main(void){
	int n,sum;
	cout<<"Size:";
	cin>>n;
	vector<int> arr(n);
	cout<<"Enter Elements:\n";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"Enter Sum:";
	cin>>sum;
	cout<<"\nNumber of Subsets Present: "<<countOfSubsetSum(arr,sum,n);
	return 0;
}
