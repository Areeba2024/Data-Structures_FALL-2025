#include <iostream>
#include <string>
using namespace std;

class Queue {
    string arr[100];
    int front, rear;
public:
    Queue() { front = 0; rear = -1; }
    bool isEmpty() { return rear < front; }
    void enqueue(string name) { arr[++rear] = name; }
    void dequeue() {
        if (!isEmpty()) front++;
    }
    void display() {
        if (isEmpty()) cout << "No patrons in queue\n";
        else {
            for (int i = front; i <= rear; i++) cout << arr[i] << " ";
            cout << endl;
        }
    }
};

int main() {
    Queue patrons;
    patrons.enqueue("Ali");
    patrons.enqueue("Sara");
    patrons.enqueue("Hassan");
    patrons.enqueue("Fatima");
    cout << "Current queue: "; patrons.display();
    patrons.dequeue();
    cout << "After serving one patron: "; patrons.display();
    patrons.enqueue("Zain");
    cout << "After adding new patron: "; patrons.display();
    return 0;
}
