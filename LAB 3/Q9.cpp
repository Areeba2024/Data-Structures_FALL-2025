#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}

    void addEnd(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    void processList() {
        if (!head || !head->next) return;

        Node* original = head;
        Node* extracted = head->next;
        Node* extractedHead = extracted;

        while (original && extracted) {
            if (extracted->next)
                original->next = extracted->next;
            else
                original->next = nullptr;

            original = original->next;

            if (original)
                extracted->next = original->next;
            else
                extracted->next = nullptr;

            extracted = extracted->next;
        }

        extractedHead = reverseList(extractedHead);

        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = extractedHead;
    }

private:
    Node* reverseList(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        Node* nextNode = nullptr;

        while (curr) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
};

int main() {
    LinkedList list;
    int arr[] = {10, 4, 9, 1, 3, 5, 9, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++) {
        list.addEnd(arr[i]);
    }

    list.processList();

    list.display();

    return 0;
}
