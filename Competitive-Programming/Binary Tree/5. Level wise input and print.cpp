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


void printTree(BinaryTreeNode<int>* root){
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while(pendingNodes.size()!=0){
		BinaryTreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout<<front->data<<" : ";
		if(front->left){
			cout<<"L "<<front->left->data<<" ";
			pendingNodes.push(front->left);
		}
		if(front->right){
			cout<<"R "<<front->right->data<<" ";
			pendingNodes.push(front->right);
		}
		cout<<"\n";
	}
	
}


int main() {
	BinaryTreeNode<int>* root = takeInput();
	printTree(root);
	delete root;
}

/**************


void printLevelWise(BinaryTreeNode<int>* root){
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while(pendingNodes.size()!=0){
		BinaryTreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout<<front->data<<":";
		if(front->left){
			cout<<"L:"<<front->left->data<<",";
			pendingNodes.push(front->left);
		}
        else{
            cout<<"L:"<<"-1"<<",";
        }
		if(front->right){
			cout<<"R:"<<front->right->data;
			pendingNodes.push(front->right);
		}
        else{
            cout<<"R:"<<"-1";
        }
		cout<<"\n";
	}
	
}
****************/
