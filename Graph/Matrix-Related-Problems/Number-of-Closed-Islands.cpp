#include<bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>>& grid, int i, int j){
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]){
        return;
    }
    grid[i][j]=1;
    DFS(grid, i+1, j);
    DFS(grid, i-1, j);
    DFS(grid, i, j+1);
    DFS(grid, i, j-1);
}
    
int closedIsland(vector<vector<int>>& grid) {
    int count=0;
    int m=grid.size(), n=grid[0].size();
    for(int i=0;i<n;i++){
        DFS(grid, 0, i);
        DFS(grid, m-1,i);
    }
    for(int i=0;i<m;i++){
        DFS(grid, i, 0);
        DFS(grid, i, n-1);
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==0){
                DFS(grid, i, j);
                count++;
            }
        }
    }
    return count;
        
}