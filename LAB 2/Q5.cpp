#include<iostream>
using namespace std;

int main(){
	int rows;
	cout<<"Enter the number of departments: ";
	cin>> rows;
	string deptNames[rows];
	for(int i = 0;i<rows; i++)
	{
		cout<<"Enter the name of department "<<i+1<<": ";
		cin>>deptNames[i];
	}
	float **arr = new float*[rows];
	int size[rows];
	
	for(int i=0;i<rows;i++){
		cout<<"Enter number of courses of department "<<deptNames[i]<<":";
		cin>>size[i];
		arr[i] = new float[size[i]];
	}
	for (int i = 0; i < rows;i++){
		for(int j = 0;j<size[i];j++)
		{
			cout<<"Enter gpa for course " << j+1<< " for "<<deptNames[i]<<":";
			cin>>arr[i][j];
		}
		cout<<endl;
	}
	
	for (int i = 0;i<rows;i++){
		cout<<"Department "<<deptNames[i]<<":"<<endl;
		for(int j = 0;j<size[i];j++){
			cout<<"Course "<<j+1<<": "<<arr[i][j]<<endl;
		}
		cout<<endl;
	}
	
	for(int i = 0;i<rows;i++){
		delete[]arr[i];
	}
	delete[] arr;
}