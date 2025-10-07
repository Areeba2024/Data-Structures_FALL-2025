#include<iostream>
using namespace std;
bool isSafe(int grid[][5], int rows, int cols , int n){
	if(rows >= 0 && rows < n && cols>= 0 && cols < n && grid[rows][cols] != 0){
		return true;
	}
	return false;
}

bool checkPath(int grid[][5],int solArr[][5], int rows, int cols, int n){
	if((rows == n-1) && (cols == n-1) ){
		solArr[rows][cols] = 1;
		for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << solArr[i][j] << " ";
            }
            cout << endl;
        }
        cout<<endl;
		return true;
	}
	if(isSafe(grid,rows,cols,n)){
		solArr[rows][cols] = 1;
		checkPath(grid,solArr,rows+1,cols,5);
		checkPath(grid,solArr,rows,cols+1,5);
		solArr[rows][cols] = 0;
	}
	return false;
}

int main(){
	int grid[5][5] = {{1,0,1,0,1},
					  {1,1,1,1,1},
					  {0,1,0,1,1},
					  {1,0,0,1,1},
					  {1,1,1,0,1}
					  };
	int solArr[5][5] = {0};
	checkPath(grid,solArr,0,0,5);
}