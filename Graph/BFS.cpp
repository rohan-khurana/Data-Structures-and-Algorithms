#include<iostream>
#include<list>
#include<map>
#include<queue>
using namespace std;

template<typename T>
class Graph{
    map<T,list<T>> l;
    public:
    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void BFS(T src){
        map<T,bool> visited;
        queue<T> q;
        q.push(src);
        visited[src]=true;
        while(!q.empty() ){
            T node = q.front();
            q.pop();
            cout<<node;
            for(int nbr:l[node]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr]=true;
                }
            }
        }
    }
};
int main(){
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(3,5);
    g.BFS(0);
    return 0;
}
