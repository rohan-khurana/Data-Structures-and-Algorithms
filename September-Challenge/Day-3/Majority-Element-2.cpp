#include<bits/stdc++.h>
using namespace std;

#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

vector<int> majority(vector<int>& arr){
    vector<int> ans;
    int c1=0,c2=0, num1=-1, num2=-1;
    for(int i:arr){
        if(i==num1) c1++;
        else if(i==num2) c2++;
        else if(c1==0){
            num1=i;
            c1=1;
        }
        else if(c2==0){
            num2=i;
            c2=1;
        }
        else{
            c1--;
            c2--;
        }
    }
    c1=c2=0;
    for(int i:arr){
        if(i==num1) c1++;
        else if(i==num2) c2++;
    }
    if(c1>arr.size()/3)
        ans.push_back(num1);
    if(c2>arr.size()/3)
        ans.push_back(num2);

    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    vector<int> ans;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ans=majority(arr);
    for(int i:ans){
        cout<<i<<" ";
    }
    return 0;
}