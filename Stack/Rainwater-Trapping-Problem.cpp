#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

int rainwaterTrapping(vector<int>& arr, int n){
    vector<int> maxL(n), maxR(n), water(n);
    int sum=0;
    maxL[0]=arr[0];
    for(int i=1;i<n;i++){
        maxL[i]=max(maxL[i-1],arr[i]);
    }
    maxR[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        maxR[i]=max(maxR[i+1],arr[i]);
    }

    for(int i=0;i<n;i++){
        water[i]=min(maxL[i],maxR[i])-arr[i];
        sum+=water[i];
    }
    return sum;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<rainwaterTrapping(arr,n);
}