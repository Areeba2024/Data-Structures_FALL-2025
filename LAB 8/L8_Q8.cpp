#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
public:
    Node* root;
    BST() : root(nullptr) {}

    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);
        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);
        return node;
    }

    void insert(int val) { root = insert(root, val); }

    int countInRange(Node* node, int a, int b) {
        if (!node) return 0;
        if (node->data < a)
            return countInRange(node->right, a, b);
        else if (node->data > b)
            return countInRange(node->left, a, b);
        else
            return 1 + countInRange(node->left, a, b) + countInRange(node->right, a, b);
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void display() { inorder(root); cout << endl; }
};

int main() {
    BST tree;
    tree.insert(5);
    tree.insert(10);
    tree.insert(40);
    tree.insert(50);
    tree.insert(1);
    tree.insert(30);
    tree.insert(20);

    cout << "BST Inorder: ";
    tree.display();

    int a, b;
    cout << "Enter range [a b]: ";
    cin >> a >> b;

    int count = tree.countInRange(tree.root, a, b);
    cout << "Number of nodes in range [" << a << ", " << b << "]: " << count << endl;

    return 0;
}
