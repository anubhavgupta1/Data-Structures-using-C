#include<iostream>
#include<queue>
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
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(data);
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while(pendingNodes.size()!=0){
		BinaryTreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout<<"Enter left child of "<<front->data<<" : ";
		int leftChild;
		cin>>leftChild;
		if(leftChild!=-1){
			front->left = new BinaryTreeNode<int>(leftChild);
			pendingNodes.push(front->left);
		}
		cout<<"Enter right child of "<<front->data<<" : ";
		int rightChild;
		cin>>rightChild;
		if(rightChild!=-1){
			front->right = new BinaryTreeNode<int>(rightChild);
			pendingNodes.push(front->right);
		}
	}
	return root;
}


bool isNodePresent(BinaryTreeNode<int>* root,int x){
	if(!root){
		return 0;
	}
	if(root->data==x){
		return 1;
	}
	bool res1 =  isNodePresent(root->left,x);
	bool res2 =  isNodePresent(root->right,x);
	return res1 || res2;
}


int main() {
	BinaryTreeNode<int>* root = takeInput();
	cout<<isNodePresent(root,4);
	delete root;
}

