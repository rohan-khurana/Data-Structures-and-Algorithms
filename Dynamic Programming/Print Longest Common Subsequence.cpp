#include<bits/stdc++.h>
using namespace std;

string printLCS(string X, string Y, int m, int n){
	string s="";
	vector< vector< int> > dp(m+1,vector<int>(n+1,0));
	for(int i=1;i<m+1;i++){
		for(int j=1;j<n+1;j++){
			if(X[i-1]==Y[j-1]){
				dp[i][j]=1+dp[i-1][j-1];
			}
			else
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}
	
	for(int i=0;i<m+1;i++){
		for(int j=0;j<n+1;j++)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	int i=m, j=n;
	
	while(i>0 && j>0){
		if(X[i-1]==Y[j-1]){
			s.push_back(X[i-1]);
			i--;
			j--;
		}
		else
		{
			if(dp[i-1]>dp[j-1])
				i--;
			else
				j--;
		}
	}
	reverse(s.begin(),s.end());
	return s;
}


int main(void){
	string X, Y;
	cout<<"Enter String 1: ";
	getline(cin,X);
	cout<<"Enter String 2: ";
	getline(cin,Y);
	cout<<"\nLongest Common Subsequence: "<<printLCS(X,Y,X.length(),Y.length());
	return 0;
}
