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

Node* helper(Node *head, Node *prev, Node *curr,int i,int count=0){
	if(curr==NULL){
		return head;
	}
	if(i==0){
		head = head->next;
		delete curr;
		return head;
	}
	if(curr!=NULL && count==i){
		Node *a = curr;
		prev->next=curr->next;
		delete a;
		return head;	
	}
	return helper(head,curr, curr->next,i,count+1);
}


Node* deleteNodeRec(Node *head, int i ){
	return helper(head,NULL,head,i)
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
