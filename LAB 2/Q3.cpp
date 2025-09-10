#include <iostream>
using namespace std;

int main() {
    int departments;
    cout << "Enter number of departments: ";
    cin >> departments;
    int* students = new int[departments];
    int*** marks = new int**[departments];

    for (int i = 0; i < departments; i++) {
        cout << "Enter number of students in Department " << i+1 << ": ";
        cin >> students[i];

        marks[i] = new int*[students[i]];
        for (int j = 0; j < students[i]; j++) {
            marks[i][j] = new int[5];
            cout << "Enter 5 subject marks for Student " << j+1 
                 << " of Department " << i+1 << ":\n";
            for (int sub = 0; sub < 5; sub++) {
                cin >> marks[i][j][sub];
            }
        }
    }

    for (int d = 0; d < departments; d++) {
        int highest = -1, lowest = 0, totalSum = 0;

        for (int s = 0; s < students[d]; s++) {
            int sum = 0;
            for (int sub = 0; sub < 5; sub++) {
                sum += marks[d][s][sub];
            }
            if (sum > highest) highest = sum;
            if (sum < lowest) lowest = sum;
            totalSum += sum;
        }

        double avg = (double)totalSum / students[d];
        cout << "Department " << (d + 1) << ":\n";
        cout << "  Highest = " << highest << endl;
        cout << "  Lowest  = " << lowest << endl;
        cout << "  Average = " << avg << endl;
    }

    
    for (int i = 0; i < departments; i++) {
        for (int j = 0; j < students[i]; j++) {
            delete[] marks[i][j];
        }
        delete[] marks[d];
    }
    delete[] marks;
    delete[] students;

    return 0;
}
