#include <bits/stdc++.h>
using namespace std;

bool subsetSum(vector<int>& arr, int sum, int n){
	vector<vector<bool> > dp(n+1, vector<bool>(sum+1,false));
	for(int i=0;i<n+1;i++){
		for(int j=0;j<1;j++){
			dp[i][j]=true;
		}
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<sum+1;j++){
			if(arr[i-1]<=j){
				dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
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
	cout<<"\nSubset Present: "<<(subsetSum(arr,sum,n)?"YES":"NO");
	return 0;
}
