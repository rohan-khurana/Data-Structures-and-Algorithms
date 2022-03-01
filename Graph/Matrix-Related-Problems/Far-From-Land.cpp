include<bits/stdc++.h>
using namespace std;

int maxDistance(vector<vector<int>>& grid) {
    int step=0;
    queue<pair<int,int>> q;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]==1){
                q.push({i-1,j});
                q.push({i+1,j});
                q.push({i,j-1});
                q.push({i,j+1});
            }
        }
    }
        
    while(!q.empty()){
        int n=q.size();
        step++;
        for(int k=0;k<n;k++){
            int i=q.front().first, j=q.front().second;
            q.pop();
            if(i>=0 && j>=0 && i<grid.size() && j<grid[0].size() && grid[i][j]==0){
                grid[i][j]=step;
                q.push({i-1,j});
                q.push({i+1,j});
                q.push({i,j-1});
                q.push({i,j+1});
            }
        }
    }
    return step==1 ? -1 : step-1;
}