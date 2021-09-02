#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>> pt(n);
    for(int i=0;i<n;i++){
        pt[i].resize(i+1);
        pt[i][0]=pt[i][i]=1;
        for(int j=1;j<i;j++){
            pt[i][j]=pt[i-1][j-1]+pt[i-1][j];
        }
    }
    
    for(int i=0;i<pt.size();i++){
        for(int j=pt.size();j>i;j--){
            cout<<" ";
        }
        for(int j=0;j<pt[i].size();j++){
            cout<<pt[i][j]<<" ";
        }
        cout<<endl;
    }
}