#include <iostream>
#include <string>
using namespace std;

struct Node {
    string key;
    string value;
    Node* next;
    Node(string k, string v) { key = k; value = v; next = NULL; }
};

class Dictionary {
public:
    Node* table[100];

    Dictionary() {
        for (int i = 0; i < 100; i++)
            table[i] = NULL;
    }

    int hashKey(string s) {
        int sum = 0;
        for (char c : s)
            sum += c;
        return sum % 100;
    }

    void Add_Record(string k, string v) {
        int idx = hashKey(k);
        Node* n = new Node(k, v);
        n->next = table[idx];
        table[idx] = n;
    }

    void Word_Search(string k) {
        int idx = hashKey(k);
        Node* t = table[idx];
        while (t) {
            if (t->key == k) {
                cout << t->value;
                return;
            }
            t = t->next;
        }
        cout << "error";
    }

    void Print_Dictionary() {
        for (int i = 0; i < 100; i++) {
            if (table[i]) {
                cout << "index " << i << ": ";
                Node* t = table[i];
                while (t) {
                    cout << "(" << t->key << ", " << t->value << ") ";
                    t = t->next;
                }
                cout << "\n";
            }
        }
    }
};

int main() {
    Dictionary d;
    d.Add_Record("AB", "FASTNU");
    d.Add_Record("CD", "CS");
    cout << "search key AB: ";
    d.Word_Search("AB");
    cout << "\n";
    d.Print_Dictionary();
}
