#include<iostream>
#include<string>
using namespace std;

int main(){
	int rows;
	cout<<"Enter the number of rows: ";
	cin>> rows;
	string **arr = new string*[rows];
	int size[rows];
	
	for(int i=0;i<rows;i++){
		cout<<"Enter capacity of Row "<<i+1<<":";
		cin>>size[i];
		arr[i] = new string[size[i]];
	}
	for (int i = 0; i < rows;i++){
		for(int j = 0;j<size[i];j++)
		{
			cout<<"Enter name for seat " << j+1<< " for Row "<<i+1<<":";
			cin>>arr[i][j];
		}
	}
	
	for (int i = 0;i<rows;i++){
		cout<<"Row "<<i+1<<":"<<endl;
		for(int j = 0;j<size[i];j++){
			cout<<"Seat "<<j+1<<": "<<arr[i][j]<<endl;
		}
		cout<<endl;
	}
	
	for(int i = 0;i<rows;i++){
		delete[]arr[i];
	}
	delete[] arr;
}