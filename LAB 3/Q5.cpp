#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
    char data;
    Node* next;

    Node(char val) {
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

    void insert_at_end(char val) {
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

    bool is_palindrome() {
        stack<char> dataStack;
        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL) {
            dataStack.push(slow->data);
            slow = slow->next;
            fast = fast->next->next;
        }

        // For odd length, skip the middle element
        if (fast != NULL) {
            slow = slow->next;
        }

        while (slow != NULL) {
            if (dataStack.top() != slow->data)
                return false;
            dataStack.pop();
            slow = slow->next;
        }

        return true;
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

    char arr[] = {'B','O','R','R','O','W','O','R','R','O','B'};

    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++) {
        list.insert_at_end(arr[i]);
    }

    cout << "Linked List:\n";
    list.display_list();

    if (list.is_palindrome())
        cout << "Linked List is a Palindrome\n";
    else
        cout << "Linked List is NOT a Palindrome\n";

    return 0;
}
