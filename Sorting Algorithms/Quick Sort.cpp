/*
Quick Sort Implementation
Approach: Divide and Conquer
Method: Partitioning
Time Complexity:
    Best: nlog(n)
    Average: nlog(n)
    Worst : n^2
Space Complexity: O(n)
Stable: No
*/


#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b){
  int c = *a;
  *a = *b;
  *b = c;
}

int partition(vector<int>& arr, int low, int high){
	int i,j,pivot;
	pivot = arr[high];  
    i = (low-1);
    for (j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return(i+1);
}

void quickSort(vector<int>& arr, int low, int high){
	int pi;
	if(low<high){
		pi = partition(arr, low, high);
		quickSort(arr, low, pi-1);
		quickSort(arr, pi+1, high);
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
	
	cout<<"\nBefore QuickSort:\n";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<"\t";
	} 
  
	quickSort(arr,0,n-1);
	
	cout<<"\nAfter QuickSort:\n";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<"\t";
	}
  
	return 0;
}
