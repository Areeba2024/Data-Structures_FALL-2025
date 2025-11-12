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

    bool search(Node* node, int val) {
        if (!node) return false;
        if (node->data == val) return true;
        if (val < node->data)
            return search(node->left, val);
        else
            return search(node->right, val);
    }

    void inorder(Node* node) {
        if (node) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    void show() { inorder(root); cout << endl; }
};

int main() {
    BST tree;
    int arr[] = {20, 10, 30, 5, 15, 25, 35};
    for (int i = 0; i < 7; i++) tree.insert(arr[i]);

    cout << "Current BST (Inorder): ";
    tree.show();

    int val;
    cout << "Enter a value to search: ";
    cin >> val;

    if (tree.search(tree.root, val))
        cout << val << " found in the tree.\n";
    else {
        cout << val << " not found. Inserting it...\n";
        tree.insert(val);
    }

    cout << "Updated BST (Inorder): ";
    tree.show();
    return 0;
}
