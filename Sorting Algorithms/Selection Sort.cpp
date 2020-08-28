/*
Selection Sort Implementation
Time Complexity:
    Best: n^2
    Average: n^2
    Worst : n^2
Space Complexity: O(1)
Stable: No
Class: Comparioson Sort
*/

#include <iostream>
#include <vector>

using namespace std;

void swap(int *a, int *b){
  int c = *a;
  *a = *b;
  *b = c;
}

void selectionSort(vector<int>& arr, int n){
  int min;
  for(int i=0;i<n-1;i++){
    min=i;
    for(int j=i+1;j<n;j++){
      if(arr[j]<arr[min]){
        min=j;
      }
    }
    swap(&arr[min],&arr[i]);
  }
}

int main(void) {
  int n;
  cout<<"Enter the size:";
  cin>>n;
  vector<int> arr(n);
  cout<<"Enter the elements:\n";
	for(int i=0; i<n; i++)
		cin>>arr[i];
	
	cout<<"\nBefore Sorting:\n";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<"\t";
		
	selectionSort(arr,n);
	
	cout<<"\nAfter Selection Sort:\n";
	for(int i=0; i<n; i++)
		cout<<arr[i]<<"\t";
  return 0;
}
