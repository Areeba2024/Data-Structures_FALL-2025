/*Task#1 Write a Program that ask user to enter 10 elements and finds the 4 minimum elements
from given array using selection Sort.*/
#include<iostream>
using namespace std;
int main(){
	int arr[10];
	for(int i=0;i<10;i++){
		cout<<"Enter the element "<<i+1<<": ";
		cin>>arr[i];
	}
	
	for(int i=0;i<10-1;i++){
		int min_index = i;
		for(int j=i+1;j<10;j++){
			if(arr[j] < arr[min_index]){
				min_index = j;	
			}
		}
		int temp = arr[i];
		arr[i] = arr[min_index];
		arr[min_index] = temp;
	}
	for(int i = 0;i<10;i++){
	cout<< arr[i]<<" ";
}
	cout<<"\nFIRST 4 MINIMUM ELEMENTS:"<<endl;
	for(int i = 0;i<4;i++){
	cout<< arr[i]<<" ";
}	
}
