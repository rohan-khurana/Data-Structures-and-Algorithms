#include<iostream>
#include<math.h>

using namespace std;

int solve(int n, int k){
    if(n==1 && k==1)
        return 0;
    int m2id=pow(2,n-1)/2;
    if(k<=mid)
        return solve(n-1,k);
    else 
        return !(solve(n-1,k-mid));
}

int main(){
    int n,k;
    cin>>n;
    cin>>k;

    cout<<solve(n,k);
}