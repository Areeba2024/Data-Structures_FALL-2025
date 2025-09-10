#include <iostream>
using namespace std;

int main() {
    int students = 5, subjects = 4;

    int** marks = new int*[students];
    for (int i = 0; i < students; i++) {
        marks[i] = new int[subjects];
    }

    cout << "Enter marks of " << students << " students in " << subjects << " subjects:\n";
    for (int i = 0; i < students; i++) {
        cout << "Student " << i+1 << ":"<<endl;
        for (int j = 0; j < subjects; j++) {
            cout << "  Subject " << j+1 << ": ";
            cin >> marks[i][j];
        }
    }

    int topperIndex = 0, maxTotal = 0;
    cout << "\nTotal Marks of Each Student: "<<endl;
    for (int i = 0; i < students; i++) {
        int total = 0;
        for (int j = 0; j < subjects; j++) {
            total += marks[i][j];
        }
        cout << "Student " << i + 1 << " = " << total << endl;

        if (total > maxTotal) {
            maxTotal = total;
            topperIndex = i;
        }
    }

    cout << "\nAverage Marks of Each Subject:\n";
    for (int j = 0; j < subjects; j++) {
        int sum = 0;
        for (int i = 0; i < students; i++) {
            sum += marks[i][j];
        }
        double avg = sum / students;
        cout << "Subject " << j + 1 << " = " << avg << endl;
    }

   
    cout << "\nTopper is Student " << topperIndex + 1
         << " with total marks = " << maxTotal << endl;

   
    for (int i = 0; i < students; i++) {
        delete[] marks[i];
    }
    delete[] marks;

    return 0;
}
