/*
Shell Sort Implementation
Sequence: Knuth's [(3^k - 1)/2], not greater than N/3;
Concrete Gaps: 1, 4, 13, 40, 121, ...
Method: Enhance Bubble + Insertion Sort
Time Complexity:
  Worst Case: O(N^1.5)
Space Comlexity: O(1)
Stable:No
*/


#include <iostream>
#include <vector>
using namespace std;

void shellSort(vector<int>& arr, int n){
	int h=1, i, j, key;
    while(h<=n)
        h=3*h+1;
 
    while(h>=1){
        for(i=h; i<n; i++){
        	key=arr[i];
        	j=i-h;
            while(j>=0 && key<arr[j]){
                arr[j+h]=arr[j];
                j-=h;
        	}
            arr[j+h]=key;
        }
        h=h/3;
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
		
	shellSort(arr,n);
	
	cout<<"\nAfter Shell Sort:\n";
	for(int i=0; i<n; i++)
		cout<<arr[i]<<"\t";
  return 0;
}
