/*
Merge Sort Implementation
Approach: Divide and Conquer
Time Complexity:
    Best: nlog(n)
    Average: nlog(n)
    Worst : O(nlog(n))
Space Complexity: O(n)
*/



#include<iostream>
#include<vector>
#include <stdlib.h>

using namespace std;

void merge(vector<int>& arr, int l, int m, int r){
	int i,j,k;
	int n1 = (m-l)+1, n2 = r-m;
	int L[n1], R[n2];
	
	for(int i=0;i<n1;i++){
		L[i]=arr[l+i];
	}
	
	for(int j=0;j<n2;j++){
		R[j]=arr[m+1+j];
	}
	i=0;
	j=0;
	k=l;
	
	while(i<n1 && j<n2){
		if(L[i] <= R[j]){
			arr[k++] = L[i++];
		}
		else{
			arr[k++] = R[j++];
		}
	}
	
	while(i<n1){
		arr[k++] = L[i++];
	}
	while(j<n2){
		arr[k++] = R[j++];
	}
	
	
}

void mergeSort(vector<int>& arr, int l, int r){
	if (l < r) {
        int m = l + (r - l) / 2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
        merge(arr, l, m, r); 
    }
}

int main(){
	int n;
	cout<<"Enter Size: ";
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	cout<<"\nBefore MergeSort:\n";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<"\t";
	} 
  
	mergeSort(arr,0,n-1);
	
	cout<<"\nAfter MergeSort:\n";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<"\t";
	}
  
	return 0;
}
