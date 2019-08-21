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

void printTree(TreeNode<int> *root){
	cout<<root->data<<" ";
	int i = 0;
	for(i=0;i<root->child.size();i++){
		printTree(root->child[i]);
	}
}

int main(){
	TreeNode<int> *root  = new TreeNode<int>(1);
	TreeNode<int> *node1 = new TreeNode<int>(2);
	TreeNode<int> *node2 = new TreeNode<int>(3);
	root->child.push_back(node1);
	root->child.push_back(node2);
	printTree(root);
}
