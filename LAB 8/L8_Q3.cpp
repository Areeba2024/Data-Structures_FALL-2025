#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Student {
    string name;
    int roll;
    int score;
    Student(string n="", int r=0, int s=0)
        : name(n), roll(r), score(s) {}
};

struct Node {
    Student data;
    Node* left;
    Node* right;
    Node(Student s) : data(s), left(nullptr), right(nullptr) {}
};

class BST {
public:
    Node* root;
    BST() : root(nullptr) {}

    Node* insert(Node* node, Student s) {
        if (!node) return new Node(s);
        if (s.name < node->data.name)
            node->left = insert(node->left, s);
        else if (s.name > node->data.name)
            node->right = insert(node->right, s);
        return node;
    }

    void insert(Student s) { root = insert(root, s); }

    Node* search(Node* node, string name) {
        if (!node || node->data.name == name) return node;
        if (name < node->data.name) return search(node->left, name);
        return search(node->right, name);
    }

    void search(string name) {
        Node* res = search(root, name);
        if (res)
            cout << "Found: " << res->data.name << " | Roll: " << res->data.roll << " | Score: " << res->data.score << endl;
        else
            cout << "Student " << name << " not found.\n";
    }

    Node* deleteLowScores(Node* node) {
        if (!node) return nullptr;
        node->left = deleteLowScores(node->left);
        node->right = deleteLowScores(node->right);
        if (node->data.score < 10) {
            node = deleteNode(root, node->data.name);
        }
        return node;
    }

    Node* deleteNode(Node* root, string name) {
        if (!root) return root;
        if (name < root->data.name)
            root->left = deleteNode(root->left, name);
        else if (name > root->data.name)
            root->right = deleteNode(root->right, name);
        else {
            if (!root->left) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data.name);
        }
        return root;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left)
            current = current->left;
        return current;
    }

    void inorder(Node* node) {
        if (node) {
            inorder(node->left);
            cout << node->data.name << " (Roll: " << node->data.roll << ", Score: " << node->data.score << ")\n";
            inorder(node->right);
        }
    }

    void show() { inorder(root); }

    Student findMaxScore(Node* node, Student best) {
        if (!node) return best;
        if (node->data.score > best.score) best = node->data;
        best = findMaxScore(node->left, best);
        best = findMaxScore(node->right, best);
        return best;
    }

    void deleteLowScores() { root = deleteLowScores(root); }

    void maxScoreStudent() {
        if (!root) { cout << "No students.\n"; return; }
        Student maxS = findMaxScore(root, root->data);
        cout << "Top Scorer: " << maxS.name << " | Roll: " << maxS.roll << " | Score: " << maxS.score << endl;
    }
};

int main() {
    srand(time(0));
    BST tree;
    Student arr[10] = {
        {"Ali", 1, 15}, {"Sara", 2, 8}, {"Bilal", 3, 22},
        {"Hina", 4, 5}, {"Omar", 5, 18}, {"Zara", 6, 30},
        {"Usman", 7, 12}, {"Mina", 8, 9}, {"Tariq", 9, 25}, {"Nida", 10, 14}
    };

    for (int i = 0; i < 7; i++) {
        int idx = rand() % 10;
        tree.insert(arr[idx]);
    }

    cout << "All Students in BST:\n";
    tree.show();

    cout << "\nSearching for 'Zara':\n";
    tree.search("Zara");

    cout << "\nDeleting students with score < 10...\n";
    tree.deleteLowScores();
    cout << "After Deletion:\n";
    tree.show();

    cout << "\nFinding student with max score:\n";
    tree.maxScoreStudent();
    return 0;
}
