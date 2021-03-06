#include <iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* next;
	Node(int data){
		this->data = data;
		next = NULL;
	} 
};

int main(){
	//statically
	Node n1(10);
	Node *head = &n1;
	Node n2(20);
	n1.next = &n2;
	
	//dynamically
	Node *n3 = new Node(30);
	Node *n4 = new Node(40);
	n2.next = n3;
	n3->next = n4;
	Node *i;
	for(i=head;i!=NULL;i=i->next){
		cout<<i->data<<" ";
	}
	
}
