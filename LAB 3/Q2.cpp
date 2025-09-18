/*Task#2:
Write a program that prompts the user to enter a number indicating how many elements to move to the
end of a linked list. The program should then move that exact number of elements from the beginning of
the linked list to the end.
Example: given list: 5, 3 1 8 6 4 2
Enter the number: 2
After rotation: 1 8 6 4 2 5 3*/
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
		void rotate_till_position(int pos){
			Node *prev;
			Node *curr;
			curr = head;
			int arr2[pos];
			for(int i= 0;i<pos;i++){
				prev = curr;
				arr2[i] = curr->data;
				curr = curr->next;
			}
			head = curr;
			prev->next = NULL; 
			for(int j=0;j<pos;j++)
			{
				add_node_at_end(arr2[j]);
			}
			if(curr == NULL){
				cout<<"Position out of bound!"<<endl;
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
	int arr[] = {5,3,1,8,6,4,2};
	int size = sizeof(arr)/sizeof(arr[0]);
	for(int i = 0; i<size;i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\nLINKED LIST:"<<endl;
	linkedList l1;
	for(int i=0;i<size;i++){
		l1.add_node_at_end(arr[i]);
	}
	l1.rotate_till_position(2);
	l1.display();
	
}