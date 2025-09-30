/*Task#4: Given an unsorted array that may contain duplicates. Write a function that returns true
if the array contains duplicates.*/

#include<iostream>
using namespace std;

int main(){
	int arr[] = {1,4,5,7,4,3,6,7};
	int size = sizeof(arr)/sizeof(arr[0]);
	int temp;
	for(int i=0;i<size -1;i++){
		for(int j=0; j<size-1-i ;j++){
			if(arr[j] > arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
			
		}
	}
	cout<<"SORTED ARRAY"<<endl;
	for(int i= 0;i<size;i++){
		cout<< arr[i] <<" ";
		}
	cout<<endl;
	
	for(int i= 0;i<size;i++){
		if(arr[i] == arr[i+1]){
			cout<<"Duplicates found at position "<<i+1<<" and "<<i+2<<endl;
			break;
		}
	}
}
