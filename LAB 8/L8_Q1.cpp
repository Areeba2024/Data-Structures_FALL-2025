#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int val) {
        key = val;
        left = right = nullptr;
    }
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int key) {
        if (node == nullptr)
            return new Node(key);
        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        return node;
    }

    Node* search(Node* node, int key) {
        if (node == nullptr || node->key == key)
            return node;
        if (key < node->key)
            return search(node->left, key);
        return search(node->right, key);
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    Node* deleteNode(Node* root, int key) {
        if (root == nullptr) return root;

        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else {
           
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
        return root;
    }

    void inorder(Node* root) {
        if (root != nullptr) {
            inorder(root->left);
            cout << root->key << " ";
            inorder(root->right);
        }
    }

    void preorder(Node* root) {
        if (root != nullptr) {
            cout << root->key << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void postorder(Node* root) {
        if (root != nullptr) {
            postorder(root->left);
            postorder(root->right);
            cout << root->key << " ";
        }
    }

public:
    BST() { root = nullptr; }

    void insert(int key) { root = insert(root, key); }

    void search(int key) {
        Node* res = search(root, key);
        if (res != nullptr)
            cout << key << " found in the BST.\n";
        else
            cout << key << " not found in the BST.\n";
    }

    void deleteKey(int key) { root = deleteNode(root, key); }

    void inorder() {
        cout << "Inorder Traversal: ";
        inorder(root);
        cout << endl;
    }

    void preorder() {
        cout << "Preorder Traversal: ";
        preorder(root);
        cout << endl;
    }

    void postorder() {
        cout << "Postorder Traversal: ";
        postorder(root);
        cout << endl;
    }
};


int main() {
    BST tree;
    int choice, val;

    while (true) {
        cout << "\nBinary Search Tree\n";
        cout << "1. Insert\n2. Delete\n3. Search\n4. Inorder Traversal\n";
        cout << "5. Preorder Traversal\n6. Postorder Traversal\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            tree.insert(val);
            break;
        case 2:
            cout << "Enter value to delete: ";
            cin >> val;
            tree.deleteKey(val);
            break;
        case 3:
            cout << "Enter value to search: ";
            cin >> val;
            tree.search(val);
            break;
        case 4:
            tree.inorder();
            break;
        case 5:
            tree.preorder();
            break;
        case 6:
            tree.postorder();
            break;
        case 7:
            cout << "Exiting\n";
            return 0;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}
