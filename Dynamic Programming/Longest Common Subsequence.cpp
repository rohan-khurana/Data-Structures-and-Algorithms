#include<bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string X, string Y, int m, int n){
	vector< vector<int> > dp(m+1 , vector<int>(n+1,0));
	for(int i=1;i<m+1;i++){
		for(int j=1;j<n+1;j++){
			if(X[i-1]==Y[j-1])
				dp[i][j]=1+dp[i-1][j-1];
			else
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[m][n];
}

int main(void){
	string X, Y;
	cout<<"Enter String 1: ";
	getline(cin,X);
	cout<<"Enter String 2: ";
	getline(cin,Y);
	cout<<"\nLength of Longest Common Subsequence: "<<longestCommonSubsequence(X,Y,X.length(),Y.length());
	return 0;
}
