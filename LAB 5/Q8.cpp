#include <iostream>
using namespace std;

bool isSafe(char board[][4], int rows, int cols, int n) {
    if (rows < n && cols < n) {
        // horizontal
        for (int i = 0; i < n; i++) {
            if (board[rows][i] == 'F') {
                return false;
            }
        }

        // vertical
        for (int i = 0; i < n; i++) {
            if (board[i][cols] == 'F') {
                return false;
            }
        }

        // upper-left diagonal
        for (int i = rows, j = cols; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'F') {
                return false;
            }
        }

        // upper-right diagonal
        for (int i = rows, j = cols; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'F') {
                return false;
            }
        }

        // lower-right diagonal
        for (int i = rows, j = cols; i < n && j < n; i++, j++) {
            if (board[i][j] == 'F') {
                return false;
            }
        }

        // lower-left diagonal
        for (int i = rows, j = cols; i < n && j >= 0; i++, j--) {
            if (board[i][j] == 'F') {
                return false;
            }
        }
        return true;
    }
    return false; 
}

bool nFlags(char board[][4], int rows, int n,int &FlagCount) {

    if (rows == n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout<<"Total flag count: "<<FlagCount;
        cout << endl;
        return false; 
    }
	
    for (int cols = 0; cols < n; cols++) {
        if (isSafe(board, rows, cols, n)) {
            board[rows][cols] = 'F'; 
			
			FlagCount++;
            nFlags(board, rows + 1, n,FlagCount); 

            board[rows][cols] = 'X';
			FlagCount--; 
        }
    }
    return false;
}

int main() {
    int n = 4;
    char board[4][4];
	int FlagCount = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = 'X';
        }
    }

    nFlags(board, 0, n,FlagCount);
    return 0;
}
