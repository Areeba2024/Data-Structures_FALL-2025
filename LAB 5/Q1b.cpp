#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int d) { data = d; next = prev = NULL; }
};

class DoublyLinkedList {
public:
    Node* head;
    DoublyLinkedList() { head = NULL; }

    void insertAtPos(int data, int pos) {
        Node* newNode = new Node(data);
        if (pos == 1 || head == NULL) {
            newNode->next = head;
            if (head) head->prev = newNode;
            head = newNode;
            return;
        }
        Node* temp = head;
        for (int i = 1; temp->next && i < pos - 1; i++)
            temp = temp->next;
        newNode->next = temp->next;
        if (temp->next) temp->next->prev = newNode;
        newNode->prev = temp;
        temp->next = newNode;
    }

    void deleteAtPos(int pos) {
        if (!head) return;
        Node* temp = head;
        if (pos == 1) {
            head = head->next;
            if (head) head->prev = NULL;
            delete temp;
            return;
        }
        for (int i = 1; temp && i < pos; i++)
            temp = temp->next;
        if (!temp) return;
        if (temp->next) temp->next->prev = temp->prev;
        if (temp->prev) temp->prev->next = temp->next;
        delete temp;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    list.insertAtPos(10, 1);
    list.insertAtPos(20, 2);
    list.insertAtPos(30, 3);
    list.insertAtPos(25, 3);
    cout << "List after insertion: ";
    list.display();
    list.deleteAtPos(2);
    cout << "List after deletion: ";
    list.display();
    return 0;
}
