/*Task#1:
You are given the array (3 1 2, 5, 8) of size 5 print that array on screen. Then create singly linked list from
that array , Now add the 9 at the end , 11 pos 3, and 4 at the front and list. Now delete the 1, 2, and 5 then
print the linked list.*/
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
		Node *tail;
	public:
		linkedList(){
			head = nullptr;
			tail = nullptr;
		}
		
		void add_node_at_end(int data){
			Node *temp = new Node(data);
			if(head == NULL){
				head = temp;
				tail = temp;
			}
			else{
				tail->next = temp;
				tail = temp;
			}
		}
		void insert_at_position(int pos,int data){
			Node *prev;
			Node *curr;
			Node *newNode = new Node(data);
			curr = head;
			if(pos == 1){
				newNode->next = head;
				head = newNode;
				return;
			}
			for(int i= 0;i<pos-1;i++){
				prev = curr;
				curr = curr->next;
			}
			
			prev->next = newNode;
			newNode->next = curr;
			
			if(curr == NULL){
				cout<<"Position out of bound!"<<endl;
			}
		}
		void add_at_front(int data){
			Node *temp = new Node(data);
			temp->next = head;
			head = temp;
		}
		
		void search_and_delete(int deleteData){
			Node *temp = head;
			Node *prevNode;
			bool flag = false;
			while(temp->next != NULL){
				if(temp->data == deleteData)
				{
					prevNode->next = temp->next;
					flag = true;
					delete temp;
					return;  
				}
				prevNode = temp;
				temp= temp->next;
			}
			if(flag == false){
				cout<<"Element not found to delete!"<<endl;
			}
		}
		void display(){
			Node *temp = head;
			while(temp != NULL){
				cout<<temp->data;
				if(temp->next != NULL){
					cout<<"->";
				}
				temp = temp->next;
			}
		}
	
};
int main(){
	int arr[] = {3,1,2,5,8};
	for(int i = 0; i<5;i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\nLINKED LIST:"<<endl;
	linkedList l1;
	for(int i=0;i<5;i++){
		l1.add_node_at_end(arr[i]);
	}
	l1.add_node_at_end(9);
	l1.insert_at_position(3,11);
	l1.add_at_front(4);
	l1.search_and_delete(1);
	l1.search_and_delete(2);
	l1.search_and_delete(5);
	l1.display();
}