#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
    Node(string d) { data = d; next = NULL; }
};

class LinkedList {
public:
    Node* head;
    LinkedList() { head = NULL; }
    void addFront(string data) {
        Node* n = new Node(data);
        n->next = head;
        head = n;
    }
    void removeFront() {
        if (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void display() {
        Node* cur = head;
        while (cur) {
            cout << cur->data << " -> ";
            cur = cur->next;
        }
        cout << "NULL\n";
    }
};

class Stack {
    string arr[100];
    int top;
public:
    Stack() { top = -1; }
    void push(string x) { arr[++top] = x; }
    string pop() { return (top >= 0) ? arr[top--] : ""; }
    string peek() { return (top >= 0) ? arr[top] : ""; }
    int size() { return top + 1; }
};

int main() {
    LinkedList history;
    Stack st;
    string sites[] = {"Google", "Facebook", "Twitter", "LinkedIn", "Instagram"};
    for (int i = 0; i < 5; i++) {
        history.addFront(sites[i]);
        st.push(sites[i]);
    }
    st.pop();
    st.pop();
    history.removeFront();
    history.removeFront();
    cout << "Current page: " << st.peek() << endl;
    cout << "Linked list after going back:\n";
    history.display();
    return 0;
}
