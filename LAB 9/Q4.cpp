#include<iostream>
using namespace std;

class node{
    public:
        int data,height;
        node* left;
        node* right;
        node():left(nullptr),right(nullptr){}
        node(int data):data(data),height(1),left(nullptr),right(nullptr){}
};
class tree{
    public:
        node* root;
        tree():root(nullptr){}

        node* insertNode(node* root,int d){
            if(root == nullptr) return new node(d);
            
            if(d < root->data)
                root->left = insertNode(root->left , d);
            else if(d > root->data)
                root->right = insertNode(root->right , d);
            
            root->height = 1 + max(getHeight(root->left) , getHeight(root->right));
            int balance = getBalance(root);

            if (balance > 1 && d < root->left->data)
                return rightRotate(root);
            if (balance < -1 && d > root->right->data)
                return leftRotate(root);

            if (balance > 1 && d > root->left->data){
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
            if (balance < -1 && d < root->right->data){
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }

            return root; 
        }
        void insertNode(int d){ root = insertNode(root,d);  }
        void preOrder(){ preOrder(root); }
        void preOrder(node* r){
    		if(r == nullptr)
        		return;

		    cout<<r->data<<" ";
		    preOrder(r->left);
		    preOrder(r->right);
		}
        int getHeight(node* r){
            if(r == nullptr) 
                return 0;
            return r->height;
        }
        int getBalance(node* root){  return(getHeight(root->left) - getHeight(root->right)); }

        node* rightRotate(node* y){
            node* x = y->left;
            node* temp = x->right;

            x->right = y;
            y->left = temp;

            y->height = 1 + max(getHeight(y->left) , getHeight(y->right));
            x->height = 1 + max(getHeight(x->left) , getHeight(x->right));
            return x;
        }

        node* leftRotate(node* x){
            node* y = x->right;
            node* temp = y->left;

            y->left = x;
            x->right = temp;
            
            x->height = 1 + max(getHeight(x->left) , getHeight(x->right));
            y->height = 1 + max(getHeight(y->left) , getHeight(y->right));
            return y;
        }
};
int main(){
    tree t;
    t.insertNode(10);
    cout<<endl<<"Balance Factor of node with value '10' : "<<t.getBalance(t.root)<<endl;
    t.insertNode(5);
    cout<<"Balance Factor of node with value '5' : "<<t.getBalance(t.root)<<endl;
    t.insertNode(15);
    cout<<"Balance Factor of node with value '15' : "<<t.getBalance(t.root)<<endl;
    t.insertNode(3);
    cout<<"Balance Factor of node with value '3' : "<<t.getBalance(t.root)<<endl;
    t.insertNode(7);
    cout<<"Balance Factor of node with value '7' : "<<t.getBalance(t.root)<<endl;

    cout<<endl<<"Elements in the tree through preOrder traversal:"<<endl;
    t.preOrder();
    t.insertNode(12);
    cout<<endl<<endl<<"Balance Factor of node with value '12' : "<<t.getBalance(t.root)<<endl;
    cout<<endl<<"preOrder traversal after adding node with value '12':"<<endl;
    t.preOrder();

    cout<<endl<<endl<<"Height of the AVL Tree: "<<t.getHeight(t.root);

    return 0;
}