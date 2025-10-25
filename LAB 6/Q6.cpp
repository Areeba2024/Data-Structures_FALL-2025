#include <iostream>
#include <string>
using namespace std;

/*
Task 6 Explanation:
In this scenario, messages arrive and must be processed in the exact same order they were received.
Once a message is sent, the next one in line is processed.
Therefore, the best data structure is a FIFO Queue.
Each message enters from the rear (enqueue) and leaves from the front (dequeue).
If we needed priority (urgent messages processed first), we would use a Priority Queue,
but since all messages are handled in the order they arrive, a simple Linear Queue works perfectly.
*/

class MessageQueue {
    string messages[100];
    int front, rear;
public:
    MessageQueue() { front = 0; rear = -1; }
    bool isEmpty() { return rear < front; }
    void enqueue(string msg) { messages[++rear] = msg; }
    void dequeue() {
        if (!isEmpty()) {
            cout << "Processed message: " << messages[front++] << endl;
        } else {
            cout << "No messages to process.\n";
        }
    }
    void display() {
        if (isEmpty()) cout << "Queue is empty.\n";
        else {
            cout << "Messages in queue:\n";
            for (int i = front; i <= rear; i++)
                cout << i - front + 1 << ". " << messages[i] << endl;
        }
    }
};

int main() {
    MessageQueue mq;

    mq.enqueue("Message 1: Hello!");
    mq.enqueue("Message 2: How are you?");
    mq.enqueue("Message 3: Meeting at 5 PM.");
    mq.enqueue("Message 4: Please confirm attendance.");

    cout << "Before processing:\n";
    mq.display();

    cout << "\nProcessing messages:\n";
    mq.dequeue();
    mq.dequeue();

    cout << "\nAfter processing two messages:\n";
    mq.display();

    return 0;
}
