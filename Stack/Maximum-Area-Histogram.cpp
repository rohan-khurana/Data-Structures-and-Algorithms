#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<climits>
#include<math.h>

using namespace std;

vector<int> NSL(vector<int>& arr, int n){
    vector<int> left;
    stack<pair<int,int>> s;
    for(int i=0;i<n;i++){
        if(s.empty()){
            left.push_back(-1); //pseudoindex=-1
        }
        else if(!s.empty() && s.top().first<arr[i]){
            left.push_back(s.top().second);
        }
        else if(!s.empty() && s.top().first>=arr[i]){
            while(!s.empty() && s.top().first>=arr[i]){
                s.pop();
            }
            if(s.empty())
                left.push_back(-1); //pseudoindex=-1
            else
                left.push_back(s.top().second);
        }
        s.push(make_pair(arr[i],i));
    }
    return left;
}
vector<int> NSR(vector<int>& arr, int n){
    vector<int> right;
    stack<pair<int,int>> s;

    for(int i=n-1;i>=0;i--){
        if(s.empty()){
            right.push_back(n); //pseudoindex=n
        }
        else if(!s.empty() && s.top().first<arr[i]){
            right.push_back(s.top().second);
        }
        else if(!s.empty() && s.top().first>=arr[i]){
            while(!s.empty() && s.top().first>=arr[i]){
                s.pop();
            }
            if(s.empty())
                right.push_back(n); //pseudoindex=n
            else
                right.push_back(s.top().second);
        }
        s.push(make_pair(arr[i],i));
    }

    reverse(right.begin(),right.end());
    return right;
}

int MAH(vector<int>& arr,int n){
    vector<int> area(n), left(n), right(n);

    left=NSL(arr,n);
    right=NSR(arr,n);

    int mah=INT_MIN;

    for(int i=0;i<n;i++){
        area[i]=arr[i]*((right[i]-left[i])-1);
        mah=max(mah,area[i]);
    }
    return mah;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<MAH(arr,n);
}