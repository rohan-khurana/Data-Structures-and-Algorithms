#include<iostream>
#include<vector>
#include<string>

using namespace std;

void solve(vector<int> v, int k, int index){
    if(v.size()==1){
        cout<<v[0];
        return;
    }
    index=(index+k)%v.size();
    v.erase(v.begin()+index);
    solve(v,k,index);
    return;
}

int main(){
    int n,k;
    int index=0;
    cin>>n>>k;
    vector<int> v;
    for(int i=1;i<=n;i++){
        v.push_back(i);
    }
    k=k-1;
    solve(v,k,index);
}