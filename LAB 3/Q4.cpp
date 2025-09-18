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

class linkedList {
private:
    Node* head;

public:
    linkedList() {
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

    void rearrange() {
        Node* evenStart = NULL;
        Node* evenEnd = NULL;
        Node* oddStart = NULL;
        Node* oddEnd = NULL;

        Node* current = head;

        while (current != NULL) {
            int value = current->data;

            if (value % 2 == 0) {
                if (evenStart == NULL) {
                    evenStart = current;
                    evenEnd = evenStart;
                } else {
                    evenEnd->next = current;
                    evenEnd = evenEnd->next;
                }
            } else {
                if (oddStart == NULL) {
                    oddStart = current;
                    oddEnd = oddStart;
                } else {
                    oddEnd->next = current;
                    oddEnd = oddEnd->next;
                }
            }

            current = current->next;
        }

        if (evenStart == NULL || oddStart == NULL)
            return;

        evenEnd->next = oddStart;
        oddEnd->next = NULL;
        head = evenStart;
    }

    void display() {
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
    linkedList list;

    int arr[] = {17, 15, 8, 12, 10, 5, 4, 1, 7, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++) {
        list.insert_at_end(arr[i]);
    }

    cout << "Original List:\n";
    list.display();

    list.rearrange();

    cout << "Modified List:\n";
    list.display();

    return 0;
}
