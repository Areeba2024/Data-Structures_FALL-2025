#include <iostream>
#include <string>
using namespace std;

class Stack {
    char arr[100];
    int top;
public:
    Stack() { top = -1; }
    bool isEmpty() { return top == -1; }
    void push(char x) { arr[++top] = x; }
    char pop() { return (top >= 0) ? arr[top--] : '\0'; }
    char peek() { return (top >= 0) ? arr[top] : '\0'; }
};

int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

string infixToPostfix(string exp) {
    Stack st;
    string result = "";
    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];
        if (isalnum(c)) result += c;
        else if (c == '(') st.push(c);
        else if (c == ')') {
            while (!st.isEmpty() && st.peek() != '(') result += st.pop();
            st.pop();
        } else {
            while (!st.isEmpty() && prec(st.peek()) >= prec(c)) result += st.pop();
            st.push(c);
        }
    }
    while (!st.isEmpty()) result += st.pop();
    return result;
}

int main() {
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    cout << "Postfix: " << infixToPostfix(exp);
    return 0;
}
