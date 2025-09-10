#include <iostream>
using namespace std;

class DynamicMatrix {
private:
    int** mat;
    int rows, cols;

    void allocate(int r, int c, int initVal = 0) {
        mat = new int*[r];
        for (int i = 0; i < r; i++) {
            mat[i] = new int[c];
            for (int j = 0; j < c; j++) {
                mat[i][j] = initVal;
            }
        }
    }

    void deallocate() {
        if (mat) {
            for (int i = 0; i < rows; i++) {
                delete[] mat[i];
            }
            delete[] mat;
            mat = nullptr;
        }
    }

public:
    DynamicMatrix(int r, int c, int initVal = 0) : rows(r), cols(c) {
        allocate(rows, cols, initVal);
    }

    ~DynamicMatrix() {
        deallocate();
    }

    void inputValues() {
        cout << "Enter matrix values:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> mat[i][j];
            }
        }
    }

    void print() const {
        cout << "Matrix (" << rows << "x" << cols << "):\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int val = mat[i][j];
                if ((i + j) % 2 == 1) val += 2;
                cout << val << " ";
            }
            cout << endl;
        }
    }

    void resize(int newRows, int newCols, int initVal = 0) {
        int** newMat = new int*[newRows];
        for (int i = 0; i < newRows; i++) {
            newMat[i] = new int[newCols];
            for (int j = 0; j < newCols; j++) {
                if (i < rows && j < cols) {
                    newMat[i][j] = mat[i][j];
                } else {
                    newMat[i][j] = initVal;
                }
            }
        }
        deallocate();
        mat = newMat;
        rows = newRows;
        cols = newCols;
    }

    void transpose() {
        int** newMat = new int*[cols];
        for (int i = 0; i < cols; i++) {
            newMat[i] = new int[rows];
            for (int j = 0; j < rows; j++) {
                newMat[i][j] = mat[j][i];
            }
        }
        deallocate();
        int temp = rows;
        rows = cols;
        cols = temp;
        mat = newMat;
    }
};

int main() {
    int r, c;
    cout << "Enter initial rows and cols: ";
    cin >> r >> c;

    DynamicMatrix matrix(r, c);
    matrix.inputValues();

    int choice;
    do {
        cout << "\nOPTIONS:\n";
        cout << "1. Print Matrix\n";
        cout << "2. Transpose Matrix\n";
        cout << "3. Resize Matrix\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            matrix.print();
        } 
        else if (choice == 2) {
            matrix.transpose();
            cout << "Matrix transposed.\n";
        } 
        else if (choice == 3) {
            int newR, newC, val;
            cout << "Enter new rows and cols: ";
            cin >> newR >> newC;
            cout << "Enter value to fill new elements: ";
            cin >> val;
            matrix.resize(newR, newC, val);
            cout << "Matrix resized.\n";
        } 
        else if (choice == 4) {
            cout << "Exiting\n";
        } 
        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
