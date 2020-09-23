#include <bits/stdc++.h>
using namespace std;

int rodCutting(vector<int>& len, vector<int>& price, int N, int n){
	vector< vector<int> > dp(n+1 , vector<int>(N+1,0));
	
	for(int i=1;i<n+1;i++){
		for(int j=1;j<N+1;j++){
			if(len[i-1]<=j){
				dp[i][j]=max((price[i-1]+dp[i][j-len[i-1]]),dp[i-1][j]);
			}
			else
				dp[i][j]=dp[i-1][j];
		}
	}
	return dp[n][N];
}

int main(){
	int n,N;
	cout<<"Size of Length Array:";
	cin>>n;
	vector<int> len(n);
	vector<int> price(n);
	
	for(int i=0;i<n;i++){
		cout<<"\nEnter Length:";
		cin>>len[i];
		cout<<"Enter its Price:";
		cin>>price[i];
	}
	cout<<"Enter Rod Length: ";
	cin>>N;
	cout<<"\nLength  Price\n";
	for(int i=0;i<n;i++){
		cout<<len[i]<<"   ->   "<<price[i]<<"\n";
	}
	cout<<"\nMaximum Profit: "<<rodCutting(len,price,N,n);
}
