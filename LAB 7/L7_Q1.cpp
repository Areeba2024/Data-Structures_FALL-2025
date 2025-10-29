#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Node {
    string name;
    int score;
    Node* next;
    Node(string n, int s) : name(n), score(s), next(nullptr) {}
};

void addNode(Node** head, string name, int score) {
    Node* newNode = new Node(name, score);
    if (*head == nullptr) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

int getMax(Node* head) {
    int mx = 0;
    while (head) {
        if (head->score > mx)
            mx = head->score;
        head = head->next;
    }
    return mx;
}

int getCount(Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

Node* getNodeAt(Node* head, int index) {
    int count = 0;
    while (head && count < index) {
        head = head->next;
        count++;
    }
    return head;
}


Node* countingSort(Node* head, int exp) {
    Node* buckets[10] = {nullptr};
    Node* tails[10] = {nullptr};

    for (Node* curr = head; curr != nullptr; curr = curr->next) {
        int digit = (curr->score / exp) % 10;
        if (buckets[digit] == nullptr) {
            buckets[digit] = curr;
            tails[digit] = curr;
        } else {
            tails[digit]->next = curr;
            tails[digit] = curr;
        }
    }

    Node* newHead = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < 10; i++) {
        if (buckets[i] != nullptr) {
            if (newHead == nullptr) {
                newHead = buckets[i];
                tail = tails[i];
            } else {
                tail->next = buckets[i];
                tail = tails[i];
            }
        }
    }

    if (tail)
        tail->next = nullptr;

    return newHead;
}


void radixSort(Node** head) {
    int m = getMax(*head);
    for (int exp = 1; m / exp > 0; exp *= 10)
        *head = countingSort(*head, exp);
}

void displayList(Node* head) {
    while (head) {
        cout << head->name << " " << head->score << endl;
        head = head->next;
    }
}

int binarySearch(Node* head, string name, int score) {
    int left = 0;
    int right = getCount(head) - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        Node* midNode = getNodeAt(head, mid);
        if (midNode->score == score && midNode->name == name)
            return mid;
        else if (midNode->score < score)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}


void deleteNode(Node** head, string name, int score) {
    Node* temp = *head;
    Node* prev = nullptr;

    while (temp != nullptr) {
        if (temp->name == name && temp->score == score) {
            if (prev == nullptr)
                *head = temp->next;
            else
                prev->next = temp->next;
            delete temp;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

int main() {
    Node* head = nullptr;
s
    addNode(&head, "Ayan", 90);
    addNode(&head, "Zameer", 60);
    addNode(&head, "Sara", 70);
    addNode(&head, "Sohail", 30);
    addNode(&head, "Ahmed", 20);

    cout << "Before Sorting:\n";
    displayList(head);

    radixSort(&head);

    cout << "\nAfter Sorting:\n";
    displayList(head);

    string name;
    int score;
    cout << "\nEnter student name to delete: ";
    cin >> name;
    cout << "Enter score: ";
    cin >> score;

    int idx = binarySearch(head, name, score);
    if (idx != -1) {
        deleteNode(&head, name, score);
        cout << "\nRecord deleted. Updated list:\n";
        displayList(head);
    } else {
        cout << "\nRecord not found. No changes made.\n";
    }

    return 0;
}
