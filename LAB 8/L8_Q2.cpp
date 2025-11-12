#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Combatant {
    int id;
    string name;
    int health;
    int attackPower;
    Combatant(int i=0, string n="", int h=0, int a=0)
        : id(i), name(n), health(h), attackPower(a) {}
};

struct Node {
    Combatant data;
    Node* left;
    Node* right;
    Node(Combatant c) : data(c), left(nullptr), right(nullptr) {}
};

class BST {
public:
    Node* root;
    BST() : root(nullptr) {}

    Node* insert(Node* node, Combatant c) {
        if (!node) return new Node(c);
        if (c.id < node->data.id)
            node->left = insert(node->left, c);
        else if (c.id > node->data.id)
            node->right = insert(node->right, c);
        return node;
    }

    void insert(Combatant c) { root = insert(root, c); }

    Node* minNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    Node* deleteNode(Node* root, int id) {
        if (!root) return root;
        if (id < root->data.id)
            root->left = deleteNode(root->left, id);
        else if (id > root->data.id)
            root->right = deleteNode(root->right, id);
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
            Node* temp = minNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data.id);
        }
        return root;
    }

    void inorder(Node* node) {
        if (node) {
            inorder(node->left);
            cout << node->data.name << "(" << node->data.health << " HP)  ";
            inorder(node->right);
        }
    }

    void showTeam() { inorder(root); cout << endl; }

    Node* getFrontline() { return minNode(root); }

    bool isEmpty() { return root == nullptr; }
};

void performAttack(BST& attackerTeam, BST& defenderTeam, bool isPlayerTurn) {
    Node* attacker = attackerTeam.getFrontline();
    Node* defender = defenderTeam.getFrontline();
    if (!attacker || !defender) return;
    int damage = attacker->data.attackPower + rand() % 5;
    defender->data.health -= damage;
    cout << (isPlayerTurn ? "Player" : "Enemy") << " attacks! "
         << attacker->data.name << " ? " << defender->data.name
         << " | Damage: " << damage << endl;
    if (defender->data.health <= 0) {
        cout << defender->data.name << " is defeated!\n";
        defenderTeam.root = defenderTeam.deleteNode(defenderTeam.root, defender->data.id);
    }
}

int main() {
    srand(time(0));
    BST playerTeam, enemyTeam;
    playerTeam.insert(Combatant(1, "Auron", 30, 6));
    playerTeam.insert(Combatant(3, "Luna", 28, 7));
    playerTeam.insert(Combatant(5, "Rex", 25, 8));
    playerTeam.insert(Combatant(7, "Mira", 22, 6));
    playerTeam.insert(Combatant(9, "Dax", 20, 9));
    enemyTeam.insert(Combatant(2, "Goblin", 25, 5));
    enemyTeam.insert(Combatant(4, "Orc", 30, 6));
    enemyTeam.insert(Combatant(6, "Troll", 28, 7));
    enemyTeam.insert(Combatant(8, "Vampire", 26, 8));
    enemyTeam.insert(Combatant(10, "Dragon", 35, 9));
    int round = 1;
    while (!playerTeam.isEmpty() && !enemyTeam.isEmpty()) {
        cout << "\n Round " << round << "\n";
        cout << "Player Team: "; playerTeam.showTeam();
        cout << "Enemy Team : "; enemyTeam.showTeam();
        performAttack(playerTeam, enemyTeam, true);
        if (enemyTeam.isEmpty()) break;
        performAttack(enemyTeam, playerTeam, false);
        round++;
    }
    cout << "\nBattle Over\n";
    if (playerTeam.isEmpty() && enemyTeam.isEmpty())
        cout << "It's a draw!\n";
    else if (enemyTeam.isEmpty())
        cout << "Player Team Wins!\n";
    else
        cout << "Enemy Team Wins!\n";
    return 0;
}
