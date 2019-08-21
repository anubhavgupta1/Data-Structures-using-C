#include <iostream>
using namespace std;
#include<vector>

template <typename T>
class TreeNode{
	public:
	T data;
	vector<TreeNode<T>*> child;
	TreeNode(T data){
		this->data = data;
	}
};


TreeNode<int>* takeInput(){
	int data,n,i;
	cout<<"Enter Data : ";
	cin>>data;
	TreeNode<int> *root  = new TreeNode<int>(data);
	cout<<"Enter number of child of "<<data<<" : ";
	cin>>n;
	for(i=0;i<n;i++){
		root->child.push_back(takeInput());
	}
	return root;
	
}
void printTree(TreeNode<int> *root){
	//edge case not a base case
	if(root==NULL){
		return;
	}
	cout<<root->data<<" : ";
	int i = 0;
	for(i=0;i<root->child.size();i++){
		cout<<root->child[i]->data<<" , ";
	}
	cout<<"\n";
	for(i=0;i<root->child.size();i++){
		printTree(root->child[i]);
	}
}

int main(){
	TreeNode<int> *root  = takeInput();
	printTree(root);
}
