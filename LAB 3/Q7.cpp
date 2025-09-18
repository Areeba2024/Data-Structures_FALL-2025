#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* tail;

public:
    CircularLinkedList() {
        tail = nullptr;
    }

    void insert_at_end(int val) {
        Node* newNode = new Node(val);
        if (tail == nullptr) {
            tail = newNode;
            tail->next = tail;
            return;
        }
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }

    void insert_at_beginning(int val) {
        Node* newNode = new Node(val);
        if (tail == nullptr) {
            tail = newNode;
            tail->next = tail;
            return;
        }
        newNode->next = tail->next;
        tail->next = newNode;
    }

    void insert_at_position(int pos, int val) {
        if (pos < 1) {
            cout << "Invalid position\n";
            return;
        }
        if (tail == nullptr && pos > 1) {
            cout << "List is empty. Can't insert at position " << pos << "\n";
            return;
        }
        if (pos == 1) {
            insert_at_beginning(val);
            return;
        }
        Node* temp = tail->next;
        int count = 1;
        while (count < pos - 1 && temp != tail) {
            temp = temp->next;
            count++;
        }
        if (count != pos - 1) {
            cout << "Position out of range\n";
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        if (temp == tail) {
            tail = newNode;
        }
    }

    void delete_node(int val) {
        if (tail == nullptr) {
            cout << "List is empty\n";
            return;
        }
        Node* curr = tail->next;
        Node* prev = tail;
        bool found = false;
        do {
            if (curr->data == val) {
                found = true;
                if (curr == prev) {
                    delete curr;
                    tail = nullptr;
                    cout << "Node deleted\n";
                    return;
                }
                prev->next = curr->next;
                if (curr == tail) {
                    tail = prev;
                }
                if (curr == tail->next) {
                    tail->next = curr->next;
                }
                delete curr;
                cout << "Node deleted\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != tail->next);
        if (!found) {
            cout << "Node not found\n";
        }
    }

    void print_list() {
        if (tail == nullptr) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = tail->next;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << endl;
    }
};

int main() {
    CircularLinkedList cll;

    cll.insert_at_end(10);
    cll.insert_at_end(20);
    cll.insert_at_end(30);
    cll.print_list();
    cll.insert_at_beginning(5);
    cll.print_list();
    cll.insert_at_position(3, 15);
    cll.print_list();
    cll.delete_node(20);
    cll.print_list();
    cll.delete_node(100);

    return 0;
}
