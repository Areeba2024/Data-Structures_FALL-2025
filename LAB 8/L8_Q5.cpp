#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    Node* root;
    BinaryTree() : root(nullptr) {}

    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);
        if (val < node->data)
            node->left = insert(node->left, val);
        else
            node->right = insert(node->right, val);
        return node;
    }

    void insert(int val) { root = insert(root, val); }

    bool isBSTUtil(Node* node, int minVal, int maxVal) {
        if (!node) return true;
        if (node->data <= minVal || node->data >= maxVal) return false;
        return isBSTUtil(node->left, minVal, node->data) &&
               isBSTUtil(node->right, node->data, maxVal);
    }

    bool isBST() {
        return isBSTUtil(root, INT_MIN, INT_MAX);
    }
};

int main() {
    BinaryTree tree;
    tree.insert(20);
    tree.insert(10);
    tree.insert(30);
    tree.insert(5);
    tree.insert(15);
    tree.insert(25);
    tree.insert(35);

    cout << "Checking if tree is a BST...\n";
    if (tree.isBST())
        cout << "Yes, it is a Binary Search Tree.\n";
    else
        cout << "No, it is NOT a Binary Search Tree.\n";

    return 0;
}
