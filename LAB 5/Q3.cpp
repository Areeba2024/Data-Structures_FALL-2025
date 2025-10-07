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
		
		
		int countNodes(Node *temp,int &count){
			if(temp == NULL )
				return 0;
				return 1+ countNodes(temp->next,count);
		
		}
};

int main(){
	linkedList l1;
	l1.addNode(23);
	l1.addNode(2);
	l1.addNode(45);
	l1.addNode(56);
	int count;
	Node *tmp = l1.getHead();
	cout<<"Total Nodes are: "<<l1.countNodes(tmp,count)<<endl;
	
	
}