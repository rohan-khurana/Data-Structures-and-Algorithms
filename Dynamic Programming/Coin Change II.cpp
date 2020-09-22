#include <bits/stdc++.h>
using namespace std;

int coinChangeII(vector<int>& coins, int sum, int n){
	vector<vector<int> > dp(n+1, vector<int>(sum+1,0));
	for(int i=0;i<sum+1;i++){
			dp[0][i]=INT_MAX-1;
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<sum+1;j++){
			if(j%coins[0]==0){
				dp[i][j]=j/coins[0];
			}
			else
				dp[i][j]=INT_MAX-1;
		}
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<sum+1;j++){
			if(coins[i-1]<=j){
				dp[i][j]=min(1+dp[i][j-coins[i-1]], dp[i-1][j]);
			}
			else
				dp[i][j]=dp[i-1][j];
		}
	}

	return dp[n][sum];
}

int main(void){
	int n,sum;
	cout<<"Size of Coin Array:";
	cin>>n;
	vector<int> coins(n);
	cout<<"Enter Coin Values:\n";
	for(int i=0;i<n;i++){
		cin>>coins[i];
	}
	cout<<"Enter Sum:";
	cin>>sum;
	cout<<"\nMinimum Number of Coins: "<<coinChangeII(coins,sum,n);
	return 0;
}
