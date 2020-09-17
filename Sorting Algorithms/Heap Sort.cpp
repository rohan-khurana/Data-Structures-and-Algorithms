/*
Heap Sort Implementation
Approach: Heap Data Structure
Method: Selection
Time Complexity:
    Best: nlog(n)
    Average: nlog(n)
    Worst : nlog(n)
Space Complexity: O(1)
Stable: No
*/


#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b){
  int c = *a;
  *a = *b;
  *b = c;
}

void heapify(vector<int>& arr, int n, int i){
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	
	if(left<n && arr[left]>arr[largest]){
		largest=left;
	}
	
	if(right<n && arr[right]>arr[largest]){
		largest=right;
	}
	
	if(largest!=i){
		swap(&arr[i],&arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapSort(vector<int>& arr, int n){
	int i;
	for(i=(n/2)-1; i>=0; i--){
		heapify(arr,n,i);
	}
	for(i=n-1; i>=0; i--){
		swap(&arr[0], &arr[i]);
		heapify(arr,i,0);
	}
}

int main(void) {
  int n;
	cout<<"Enter Size: ";
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	cout<<"\nBefore HeapSort:\n";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<"\t";
	} 
  
	heapSort(arr,n);
	
	cout<<"\nAfter HeapSort:\n";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<"\t";
	}
  
	return 0;
}
