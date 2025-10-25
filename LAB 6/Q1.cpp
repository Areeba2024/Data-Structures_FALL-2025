#include <iostream>
#include <string>
using namespace std;

class Stack {
    string items[100];
    int top;
public:
    Stack() { top = -1; }
    bool isEmpty() { return top == -1; }
    void push(string item) { if (top < 99) items[++top] = item; }
    string pop() { if (!isEmpty()) return items[top--]; return ""; }
    string peek() { if (!isEmpty()) return items[top]; return ""; }
};

int main() {
    Stack todo;
    todo.push("Finish project report");
    todo.push("Reply to emails");
    cout << "Stack empty? " << (todo.isEmpty() ? "Yes" : "No") << endl;
    cout << "Removed: " << todo.pop() << endl;
    return 0;
}
