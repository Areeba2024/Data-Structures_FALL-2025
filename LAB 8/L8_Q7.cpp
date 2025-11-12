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

    int countNodes(Node* node) {
        if (!node) return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    void inorderMedian(Node* node, int& count, int target1, int target2, int& val1, int& val2) {
        if (!node) return;
        inorderMedian(node->left, count, target1, target2, val1, val2);
        count++;
        if (count == target1) val1 = node->data;
        if (count == target2) val2 = node->data;
        inorderMedian(node->right, count, target1, target2, val1, val2);
    }

    double findMedian() {
        int n = countNodes(root);
        int val1 = 0, val2 = 0, count = 0;
        if (n % 2 == 1) {
            int target = (n + 1) / 2;
            inorderMedian(root, count, target, target, val1, val2);
            return val1;
        } else {
            int target1 = n / 2;
            int target2 = n / 2 + 1;
            inorderMedian(root, count, target1, target2, val1, val2);
            return (val1 + val2) / 2.0;
        }
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
    tree.insert(20);
    tree.insert(10);
    tree.insert(30);
    tree.insert(5);
    tree.insert(15);
    tree.insert(25);
    tree.insert(35);

    cout << "BST Inorder: ";
    tree.display();

    cout << "Median of BST: " << tree.findMedian() << endl;
    return 0;
}
