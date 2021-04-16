#include<iostream>
#include<list>
#include<map>
#include<stack>
using namespace std;

template<typename T>
class Graph{
    map<T,list<T>> l;
    public:
    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void DFSrec(T src,map<T,bool> &visited){
        cout<<src<<" ";
        visited[src]=true;
        for(T nbr:l[src]){
            if(!visited[nbr]){
                DFSrec(nbr,visited);
            }
        }
    }
    void DFS(T src){
        map<T,bool> visited;
        for(auto p:l){
            T node = p.first;
            visited[node]=false;
        }
        DFSrec(src, visited);
    }
};
int main(){
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.DFS(1);
    return 0;
}