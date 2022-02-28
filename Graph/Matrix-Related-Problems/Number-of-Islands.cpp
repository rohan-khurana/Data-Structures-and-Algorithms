#include<bits/stdc++.h>
using namespace std;

void DFS(vector<vector<char>>& grid, int i, int j, int& count){
    if(i>=0 && j>=0 && i<grid.size() && j<grid[0].size() && grid[i][j]=='1'){
        grid[i][j]='0';
        DFS(grid, i+1, j, count);
        DFS(grid, i-1, j, count);
        DFS(grid, i, j+1, count);
        DFS(grid, i, j-1, count);
    }
}
    
int numIslands(vector<vector<char>>& grid) {
    int count=0;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();j++){
            if(grid[i][j]=='1'){
                count++;
                grid[i][j]='0';
                DFS(grid, i+1, j, count);
                DFS(grid, i-1, j, count);
                DFS(grid, i, j+1, count);
                DFS(grid, i, j-1, count);
            }
        }
    }
    return count;
}