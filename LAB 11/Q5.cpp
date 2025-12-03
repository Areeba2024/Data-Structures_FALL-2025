#include <iostream>
#include <string>
using namespace std;

struct Student {
    int roll;
    string name;
    bool used;
    Student() {
        used = false;
    }
};

class StudentHashTable {
public:
    Student t[15];

    int hashF(int r) {
        return r % 15;
    }

    void InsertRecord(int r, string n) {
        int idx = hashF(r);
        for (int a = 0; a < 15; a++) {
            int pos = (idx + a * a) % 15;
            if (!t[pos].used) {
                t[pos].used = true;
                t[pos].roll = r;
                t[pos].name = n;
                return;
            }
        }
    }

    void SearchRecord(int r) {
        int idx = hashF(r);
        for (int a = 0; a < 15; a++) {
            int pos = (idx + a * a) % 15;
            if (t[pos].used && t[pos].roll == r) {
                cout << t[pos].name;
                return;
            }
        }
        cout << "Record not found";
    }

    void Display() {
        for (int i = 0; i < 15; i++) {
            if (t[i].used)
                cout << "Index " << i << ": (" << t[i].roll << ", " << t[i].name << ")\n";
        }
    }
};

int main() {
    StudentHashTable sht;
    sht.InsertRecord(10, "Ali");
    sht.InsertRecord(25, "Sara");
    sht.InsertRecord(40, "Hamid");

    cout << "Search Roll 25: ";
    sht.SearchRecord(25);
    cout << "\n\nFull Table:\n";
    sht.Display();
}
