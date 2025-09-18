#include <iostream>
using namespace std;

class DNode {
public:
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
public:
    DNode* head;
    DNode* tail;

    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void add_node_at_end(int val) {
        DNode* newNode = new DNode(val);
        if (!head) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void display() {
        DNode* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << " <-> ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Concatenate another doubly linked list M to this list L
    void concatenate(DoublyLinkedList& M) {
        if (!head) {
            head = M.head;
            tail = M.tail;
            return;
        }
        if (!M.head) {
            return;
        }
        tail->next = M.head;
        M.head->prev = tail;
        tail = M.tail;
    }
};

int main() {
    DoublyLinkedList L;
    L.add_node_at_end(1);
    L.add_node_at_end(2);
    L.add_node_at_end(3);

    DoublyLinkedList M;
    M.add_node_at_end(4);
    M.add_node_at_end(5);
    M.add_node_at_end(6);

    cout << "List L before concatenation: ";
    L.display();

    cout << "List M before concatenation: ";
    M.display();

    L.concatenate(M);

    cout << "List L after concatenation: ";
    L.display();

    return 0;
}
