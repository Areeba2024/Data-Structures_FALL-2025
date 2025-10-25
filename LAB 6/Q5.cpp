#include <iostream>
using namespace std;

class Queue {
    int arr[100];
    int front, rear;
public:
    Queue() { front = 0; rear = -1; }
    bool isEmpty() { return rear < front; }
    void enqueue(int x) { arr[++rear] = x; }
    int dequeue() {
        if (!isEmpty()) return arr[front++];
        return -1;
    }
    void display() {
        for (int i = front; i <= rear; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q;
    int customers[] = {13, 7, 4, 1, 6, 8, 10};
    for (int i = 0; i < 7; i++) q.enqueue(customers[i]);
    cout << "Checkout order: ";
    while (!q.isEmpty()) cout << q.dequeue() << " ";
    return 0;
}
