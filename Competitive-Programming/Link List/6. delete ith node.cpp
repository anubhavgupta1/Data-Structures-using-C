#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};


void print(Node *head){
    Node *temp = head;
	cout<<"\nList is : ";
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

Node* input(Node* head){
	int data; char ch;
	Node* tail = NULL;
	cout<<"\nEnter data : (y/n) ? ";
	cin>>ch;
	while(ch=='y'||ch=='Y'){
		cin>>data;
		Node *newNode= new Node(data);
		if(head==NULL){
			head = newNode;
			tail = newNode;	
		}
		else{
			tail->next  = newNode;
			tail= newNode;
			//or
			//tail= tail->next;		
		}
		cout<<"\nEnter more data : (y/n) ? ";
		cin>>ch;
	}
	return head;
}

Node* deleteNode(Node* head, int i){
	Node* temp=head, *prev;
	int count=0;
	if(i==0){
		head = head->next;
		delete temp;
		return head;
	}
	for(;temp!=NULL&&count<i;count++,prev= temp,temp=temp->next){
	}
	if(temp!=NULL){
		Node *a = temp;
		prev->next=temp->next;
		delete a;	
	}
	return head;
}


int main(){
	Node *head = NULL;
	head = input(head);
    print(head);
    cout<<"\nEnter the position : ";
    int i;cin>>i;
    head = deleteNode(head,i);
    print(head);
}
