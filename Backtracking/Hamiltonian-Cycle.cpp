#include<iostream>
#include<vector>

using namespace std;

bool isSafe(int v, vector<vector<int>>& graph, vector<int>& path, int n, int pos){
    if(graph[path[pos-1]][v]==0){
        return false; //if v is not adjacent to previous vertex
    }
    for(int i=0;i<pos;i++){
        if(path[i]==v){
            return false; // if vertex already included
        }
    }
    return true;
}

bool cycle(vector<vector<int>>& graph, vector<int>& path, int n, int pos){
    if(pos==n){
        if(graph[path[pos-1]][path[0]]){
            return true; //if there is an edge from last included vertex to first vertex
        }
        else{
            return false;
        }
    }
    for(int v=1;v<n;v++){
        //check if vertex can be added to hamiltonian path
        if(isSafe(v,graph,path,n,pos)){
            path[pos]=v;
            if(cycle(graph, path, n, pos+1)){
                return true;
            }
            path[pos]=-1;
        }
    }
    return false;
}

bool hamCycle(vector<vector<int>> & graph){
    int n=graph[0].size();
    vector<int> path(n,-1);
    path[0]=0;
    if(cycle(graph,path,n,1)){
        for(int i=0;i<n;i++){
            cout<<path[i]<<" ";
        }
        return true;
    }
    else{
        cout<<"Hamiltonian Cycle does not exist.";
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> graph(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>graph[i][j];
        }
    }
    hamCycle(graph);
    return 0;
}