#include<iostream>
using namespace std;
bool isSafe(int maze[4][4], int row, int col,int n){
	if(row >=0 && row <n && col>=0 && col<n && maze[row][col] != 0){
		return true;
	}
	return false;
}

bool inMaze(int maze[4][4],int sol[4][4], int row, int col,int n){
	if(row == 2 && col == 0){
		sol[row][col] = 1;
		for(int i = 0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<sol[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		sol[row][col] = 0;
		return false;
	}
	
	if(isSafe(maze,row,col,n) && sol[row][col] == 0){
		sol[row][col] = 1;
		if(inMaze(maze,sol,row+1,col,n)) return true;
		if(inMaze(maze,sol,row,col+1,n)) return true;
		if(inMaze(maze,sol,row-1,col,n)) return true;
		if(inMaze(maze,sol,row,col-1,n)) return true;
		sol[row][col] = 0;
	}
	return false;
}
int main(){
	int maze[4][4] ={{1,1,1,1},
					{0,0,0,1},
					{1,1,0,1},
					{1,1,1,1}
					};
	int sol[4][4] = {0};
	inMaze(maze,sol,0,0,4);
	
}