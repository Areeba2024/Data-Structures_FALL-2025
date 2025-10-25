#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
    Node(string d) { data = d; next = NULL; }
};

class Stack {
public:
    Node* top;
    Stack() { top = NULL; }
    void push(string x) {
        Node* n = new Node(x);
        n->next = top;
        top = n;
    }
    string pop() {
        if (!top) return "";
        Node* temp = top;
        string val = top->data;
        top = top->next;
        delete temp;
        return val;
    }
};

int main() {
    Stack s;
    s.push("x");
    s.push("=");
    s.push("12");
    s.push("+");
    s.push("13");
    s.push("-");
    s.push("5");
    s.push("*");
    s.push("(0.5+0.5)");
    s.push("+");
    s.push("1");
    double result = 12 + 13 - 5 * (0.5 + 0.5) + 1;
    s.push(to_string((int)result));
    Node* cur = s.top;
    while (cur) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    return 0;
}
