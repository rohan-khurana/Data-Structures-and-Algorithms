/*
Insertion Sort Implementation
Time Complexity:
    Best: n
    Average: n^2
    Worst : n^2
Space Complexity: O(1)
Stable: Yes
Class: Comparison Sort
*/


#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& arr, int n){
  int j,key;
  for(int i=1;i<n;i++){
    key=arr[i];
    j=i-1;
    while(j>=0 && arr[j]>key){
      arr[j+1]=arr[j];
      j--;
    }
    arr[j+1]=key;
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
		
	insertionSort(arr,n);
	
	cout<<"\nAfter Insertion Sorting:\n";
	for(int i=0; i<n; i++)
		cout<<arr[i]<<"\t";
  return 0;
}
