#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

unordered_map<string,int> mp;

void printSubsets(string ip, string op){
    if(ip.length()==0){
        if(mp.find(op)==mp.end())
            mp[op]++;

        return;
    }
    string op1=op;
    string op2=op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin()+0);

    printSubsets(ip,op1);
    printSubsets(ip,op2);
    return;
}

using namespace std;
int main(){
    string ip;
    string op="";
    getline(cin,ip);
    printSubsets(ip,op);
    for (auto i : mp)
        cout<<i.first <<" ";
}