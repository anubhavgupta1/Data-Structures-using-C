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


Node* helper(Node* head, Node * temp,Node *node, int i, int count= 0){
    
    if(temp==NULL){
        return head;
    }
    
    if(i==0){
		node->next=temp;
		head = node;
		return head;
	}
	if(temp!=NULL && count==i-1){
		node->next= temp->next;
		temp->next = node;
		return head;	
	}
	helper(head,temp->next,node,i,count+1);
}


Node* insertNodeRec(Node *head, int i, int data){
	Node *node= new Node(data);
    return helper(head,head,node,i);
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
