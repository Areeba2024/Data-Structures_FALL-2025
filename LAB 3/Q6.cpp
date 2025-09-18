#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void insert_at_end(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    void delete_value_from_list(int val) {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }

        if (head->data == val) {
            cout << "Cannot delete the first node value with this function.\n";
            return;
        }

        Node* prev = head;
        Node* curr = head->next;

        while (curr != NULL) {
            if (curr->data == val) {
                prev->next = curr->next;
                delete curr;
                cout << "Value " << val << " deleted from the list.\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        }

        cout << "Value " << val << " not found in the list.\n";
    }

    void display_list() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data;
            if (temp->next != NULL)
                cout << "->";
            temp = temp->next;
        }
        cout << "->NULL\n";
    }
};

int main() {
    LinkedList list;

    list.insert_at_end(10);
    list.insert_at_end(20);
    list.insert_at_end(30);
    list.insert_at_end(40);

    cout << "Original list:\n";
    list.display_list();

    list.delete_value_from_list(30);
    list.display_list();

    list.delete_value_from_list(10);
    list.display_list();

    list.delete_value_from_list(50);
    list.display_list();

    return 0;
}
