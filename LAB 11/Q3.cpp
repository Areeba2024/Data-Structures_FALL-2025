#include <iostream>
using namespace std;

struct Node {
    int key;
    int value;
    Node* next;
    Node(int k, int v) {
        key = k;
        value = v;
        next = NULL;
    }
};

class Hash {
public:
    Node* table[10];

    Hash() {
        for (int i = 0; i < 10; i++)
            table[i] = NULL;
    }

    int hashF(int k) {
        return k % 10;
    }

    void insertItem(int k, int v) {
        int index = hashF(k);
        Node* n = new Node(k, v);
        n->next = table[index];
        table[index] = n;
    }

    void deleteItem(int k) {
        int index = hashF(k);
        Node* temp = table[index];
        Node* prev = NULL;

        while (temp) {
            if (temp->key == k) {
                if (prev == NULL)
                    table[index] = temp->next;
                else
                    prev->next = temp->next;

                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    void searchItem(int k) {
        int index = hashF(k);
        Node* temp = table[index];

        while (temp) {
            if (temp->key == k) {
                cout << temp->value;
                return;
            }
            temp = temp->next;
        }
        cout << "not found";
    }

    void display() {
        for (int i = 0; i < 10; i++) {
            cout << i << ": ";
            Node* temp = table[i];
            while (temp) {
                cout << "(" << temp->key << "," << temp->value << ") ";
                temp = temp->next;
            }
            cout << "\n";
        }
    }
};

int main() {
    Hash h;
    h.insertItem(12, 100);
    h.insertItem(22, 200);
    h.insertItem(32, 300);

    h.display();

    cout << "Search 22: ";
    h.searchItem(22);
    cout << "\n";

    h.deleteItem(22);
    h.display();
}
