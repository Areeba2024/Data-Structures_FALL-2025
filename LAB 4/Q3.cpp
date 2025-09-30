/*Task#3: Given an array of strings arr[]. Sort given strings using Bubble Sort and display the
sorted array.
Input: string arr[] = {"banana", "apple", "cherry", "date", "grape"};
Output: apple banana cherry date grape*/

#include<iostream>
#include<string>
using namespace std;
int main() {
string arr[] = {"banana", "apple", "cherry", "date", "grape"};
int size = sizeof(arr)/sizeof(arr[0]);
string temp;
for(int i = 0;i<size-1;i++){
	for(int j=0;j<size-1-i;j++){
		if(arr[j] > arr[j+1]){
			temp = arr[j];
			arr[j] = arr[j+1];
			arr[j+1] = temp;
		}
	}
}
for(int i = 0;i<size;i++){
	cout<< arr[i]<<" ";
}	
}
