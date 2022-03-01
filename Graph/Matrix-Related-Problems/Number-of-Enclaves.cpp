#include<bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>>& grid, int i, int j, int& count){
    if(i>=grid.size() || i<0 || j<0 || j>=grid[0].size() || grid[i][j]==0){
        return;
    }
    count++;
    grid[i][j]=0;
    DFS(grid,i+1,j,count);
    DFS(grid,i-1,j,count);
    DFS(grid,i,j+1,count);
    DFS(grid,i,j-1,count);
}

int numEnclaves(vector<vector<int>>& grid) {
    int m=grid.size();
    int n=grid[0].size();
    int count=0;
    for(int i=0;i<m;i++){
        DFS(grid,i,0,count);
        DFS(grid,i,n-1,count);
    }
    for(int i=0;i<n;i++){
        DFS(grid,0,i,count);
        DFS(grid,m-1,i,count);
    }
    count=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                DFS(grid,i,j,count);
            }
        }
    }
    return count;
}