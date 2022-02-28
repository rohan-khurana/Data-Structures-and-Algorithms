#include<bits/stdc++.h>
using namespace std;

int area(int i, int j, vector<vector<int>>& grid){
    if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && grid[i][j]==1){
        grid[i][j]=0;
        return (1+area(i+1,j,grid)+area(i-1,j,grid)+area(i,j+1,grid)+area(i,j-1,grid));
    }
    return 0;
}

int maxAreaOfIsland(vector<vector<int>>& grid){
    int maxArea = 0;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            maxArea=max(maxArea,area(i,j,grid));
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }

    cout<<maxAreaOfIsland(grid);
    return 0;
}