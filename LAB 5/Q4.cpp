#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node *next;
		
		Node(int d){
			data = d;
			next = NULL;
		}
};

class linkedList{
	private:
		Node *head;
	
	public:
		linkedList(){
			head = NULL;
		}
		Node *getHead(){
			return head;
		}
		void addNode(int data){
			Node *newNode = new Node(data);
			if(head == NULL){
				head = newNode;
			}
			else{
				Node *temp = head;
			    while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = newNode;
				
			}
		}
		bool searchList(int data, Node *temp){
			while(temp != NULL){
				bool isFound = searchList(data,temp->next);
				if(temp->data == data){
					return true;
				}
				return isFound;
			}
			
		}
		
		
		void display(){
			Node *temp = head;
			while(temp != NULL){
				cout<<temp->data<<"->";
				temp = temp->next;
			}
			cout<<"NULL"<<endl;
		}
};

int main(){
	linkedList l1;
	l1.addNode(23);
	l1.addNode(2);
	l1.addNode(45);
	l1.addNode(56);
	l1.display();
	Node *tmp = l1.getHead();
	if(l1.searchList(2,tmp) == true){
		cout<<"Value found!"<<endl;
	}
	else
	{
		cout<<"Value Not Found!"<<endl;
	}
	
}