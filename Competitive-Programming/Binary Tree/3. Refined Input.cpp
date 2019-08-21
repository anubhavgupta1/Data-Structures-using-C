#include<iostream>
using namespace std;

template <typename T>
class BinaryTreeNode {
	public:
	T data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;

	BinaryTreeNode(T data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}

	~BinaryTreeNode() {
		delete left;
		delete right;
	}
};

BinaryTreeNode<int>* takeInput(){
	int data;
	cout<<"Enter data : ";
	cin>>data;
	if(data==-1){
		return NULL;
	}
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(data);
	cout<<"Enter left child of "<<root->data<<" : ";
	root->left  = takeInput();
	cout<<"Enter right child of "<<root->data<<" : ";
	root->right = takeInput();
	return root;
	
}

void printTree(BinaryTreeNode<int>* root){
	if(!root){
		return;
	}
	cout<<root->data<<" : ";
	if(root->left){
		cout<<" L "<<root->left->data<<" ";
	}
	if(root->left){
		cout<<" R "<<root->right->data<<" ";
	}
	cout<<"\n";
	printTree(root->left);
	printTree(root->right);	
}

int main() {
	BinaryTreeNode<int>* root = takeInput();
	printTree(root);
	delete root;
}

