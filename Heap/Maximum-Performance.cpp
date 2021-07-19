#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<math.h>
using namespace std;

int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minh;
        int performance=0, m=INT_MAX;
        for(int i=0;i<n;i++){
            minh.push(make_pair(speed[i]*efficiency[i],i));
            if(minh.size()>k){
                minh.pop();
            }
        }
        while(!minh.empty()){
                int x=minh.top().second;
                m=min(m,efficiency[x]);
                performance+=speed[x];
                minh.pop();
            }
        return (m*performance)%1000000007;
    }

int main() {
    int n,k;
    cin>>n;
    vector<int> efficiency(n), speed(n);
    for(int i=0;i<n;i++){
        cin>>speed[i];
    }
    for(int i=0;i<n;i++){
        cin>>efficiency[i];
    }
    cin>>k;
    cout<<maxPerformance(n,speed,efficiency,k);
    return 0;
}