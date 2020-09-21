#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsack(vector<int>& wt, vector<int>& val, int W, int n){
	vector< vector<int> > dp(n+1 , vector<int>(W+1,0));
	
	for(int i=1;i<n+1;i++){
		for(int j=1;j<W+1;j++){
			if(wt[i-1]<=j){
				dp[i][j]=max((val[i-1]+dp[i][j-wt[i-1]]),dp[i-1][j]);
			}
			else
				dp[i][j]=dp[i-1][j];
		}
	}
	return dp[n][W];
}

int main(){
	int n,W;
	cout<<"No. of Items:";
	cin>>n;
	vector<int> wt(n);
	vector<int> val(n);
	cout<<"Enter Items Weight:\n";
	for(int i=0;i<n;i++){
		cin>>wt[i];
	}
	cout<<"Enter Items Value:\n";
	for(int i=0;i<n;i++){
		cin>>val[i];
	}
	cout<<"Enter Knapsack Capacity: ";
	cin>>W;
	cout<<"\nWeight  Value\n";
	for(int i=0;i<n;i++){
		cout<<wt[i]<<"\t"<<val[i]<<"\n";
	}
	cout<<"\nMaximum Value: "<<unboundedKnapsack(wt,val,W,n);
}
