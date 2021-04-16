#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

class Graph{

    unordered_map<string,list<pair<string, int>>> l;
    public:
    void addEdge(string u,string v, bool bidir, int wt){
        l[u].push_back(make_pair(v,wt));
        if(bidir){
            l[v].push_back(make_pair(u,wt));
        }
    }
    void printAdjList(){
        for(auto p:l){
            string city=p.first;
            list<pair<string,int>> neighbours = p.second;
            cout<<city<<"->";
            for(auto n:neighbours){
                string dest=n.first;
                int d=n.second;
                
                cout << "(" << dest << "," <<d<< "),";
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph g;
    g.addEdge("A","B",true,20);
    g.addEdge("B","D",true,40);
    g.addEdge("A","C",true,10);
    g.addEdge("C","D",true,40);
    g.addEdge("A","D",false,50);
    g.printAdjList();
    return 0;
}