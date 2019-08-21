#include <iostream>
using namespace std;
#include<vector>
#include<queue>

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
	int data,n,i,numChild,childData;
	cout<<"Enter Data : ";
	cin>>data;
	TreeNode<int> *root  = new TreeNode<int>(data);
	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while(pendingNodes.size()!=0){
		TreeNode<int> *front = pendingNodes.front();
		pendingNodes.pop();
		cout<<"Enter the number of child of "<<front->data<<" : ";
		cin>>numChild;
		for(i=0;i<numChild;i++){
			cout<<"Enter the " <<i<<" th child of "<<front->data<<" : ";
			cin>>childData;
			TreeNode<int> *child  = new TreeNode<int>(childData);
			front->child.push_back(child);
			pendingNodes.push(child);
		}
	}
	return root;
}
void printTree(TreeNode<int> *root){
	//edge case not a base case
	if(root==NULL){
		return;
	}
	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while(pendingNodes.size()!=0){
		TreeNode<int> *front = pendingNodes.front();
		pendingNodes.pop();
		cout<<front->data<<" : ";
		int i = 0;
		for(i=0;i<front->child.size();i++){
			cout<<front->child[i]->data<<" , ";
		}
		cout<<"\n";
		for(i=0;i<front->child.size();i++){
			pendingNodes.push(front->child[i]);
		}
	}
	
}

int main(){
	TreeNode<int> *root  = takeInput();
	printTree(root);
}
