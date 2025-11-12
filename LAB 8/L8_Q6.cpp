#include <iostream>
using namespace std;

struct Product {
    int id;
    int quantity;
    Product(int i=0, int q=0) : id(i), quantity(q) {}
};

struct Node {
    Product data;
    Node* left;
    Node* right;
    Node(Product p) : data(p), left(nullptr), right(nullptr) {}
};

class InventoryBST {
public:
    Node* root;
    InventoryBST() : root(nullptr) {}

    Node* insert(Node* node, Product p) {
        if (!node) return new Node(p);
        if (p.id < node->data.id)
            node->left = insert(node->left, p);
        else if (p.id > node->data.id)
            node->right = insert(node->right, p);
        else
            node->data.quantity += p.quantity;
        return node;
    }

    void insert(Product p) { root = insert(root, p); }

    Node* search(Node* node, int id) {
        if (!node || node->data.id == id) return node;
        if (id < node->data.id) return search(node->left, id);
        return search(node->right, id);
    }

    void search(int id) {
        Node* res = search(root, id);
        if (res)
            cout << "Product ID: " << res->data.id << " | Quantity: " << res->data.quantity << endl;
        else
            cout << "Product ID " << id << " not found.\n";
    }

    void updateQuantity(int id, int qty) {
        Node* res = search(root, id);
        if (res) {
            res->data.quantity = qty;
            cout << "Quantity updated for product " << id << endl;
        } else {
            cout << "Product not found, inserting new product.\n";
            insert(Product(id, qty));
        }
    }

    void inorder(Node* node) {
        if (node) {
            inorder(node->left);
            cout << "ID: " << node->data.id << " | Qty: " << node->data.quantity << endl;
            inorder(node->right);
        }
    }

    void display() { inorder(root); }

    Product findMaxQuantity(Node* node, Product maxP) {
        if (!node) return maxP;
        if (node->data.quantity > maxP.quantity) maxP = node->data;
        maxP = findMaxQuantity(node->left, maxP);
        maxP = findMaxQuantity(node->right, maxP);
        return maxP;
    }

    void highestQuantityProduct() {
        if (!root) {
            cout << "Inventory is empty.\n";
            return;
        }
        Product maxP = findMaxQuantity(root, root->data);
        cout << "Product with highest stock:\n";
        cout << "ID: " << maxP.id << " | Quantity: " << maxP.quantity << endl;
    }
};

int main() {
    InventoryBST inventory;
    inventory.insert(Product(101, 50));
    inventory.insert(Product(205, 30));
    inventory.insert(Product(150, 70));
    inventory.insert(Product(120, 25));
    inventory.insert(Product(300, 90));

    cout << "Current Inventory:\n";
    inventory.display();

    cout << "\nSearching for product ID 150:\n";
    inventory.search(150);

    cout << "\nUpdating quantity of product ID 205 to 100...\n";
    inventory.updateQuantity(205, 100);

    cout << "\nInventory after update:\n";
    inventory.display();

    cout << "\nProduct with highest quantity:\n";
    inventory.highestQuantityProduct();

    return 0;
}
