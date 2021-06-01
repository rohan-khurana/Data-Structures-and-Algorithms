#include<iostream>
using namespace std;
void toh(int n, int s, int h, int d, int& count){
    count++;
    if(n==1){
        cout<<"Move "<<n<<" from "<<s<<" to "<<d<<endl;
        return;
    }
    toh(n-1,s,d,h,count);
    cout<<"Move "<<n<<" from "<<s<<" to "<<d<<endl;
    toh(n-1,h,s,d,count);
}

int main(){
    int n, count=0, s=1, h=2, d=3;
    cin>>n;
    toh(n,s,h,d, count);
    cout<<"Steps: "<<count;
}