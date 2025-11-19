#include <iostream>
#include <string>
using namespace std;

struct Node {
    string key;
    string value;
    Node *next;

    Node(string k = "None", string v = "None") {
        key = k;
        value = v;
        next = nullptr;
    }
};

class HashTable {
public:
    static const int tableSize = 26;
    Node* table[tableSize];

    HashTable() {
        for (int i = 0; i < tableSize; i++) {
            table[i] = nullptr;
        }
    }

    int hashFunction(string key) {
        int length = key.length();
        int sum = 0;
        for (int i = 0; i < length; i++) {
            sum += key[i];
        }
        return sum % tableSize;
    }

    void insert(string key, string value) {
        int index = hashFunction(key);
        Node *newNode = new Node(key, value);

        newNode->next = table[index];
        table[index] = newNode;
    }

    void display() {
        for (int i = 0; i < tableSize; i++) {
            cout << i << ": ";
            Node* temp = table[i];

            while (temp != nullptr) {
                cout << "(" << temp->key << ", " << temp->value << ") -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    HashTable myhash;

    myhash.insert("A", "aaaa");
    myhash.insert("B", "bbbb");
    myhash.insert("C", "cccc");

    myhash.display();

    return 0;
}
