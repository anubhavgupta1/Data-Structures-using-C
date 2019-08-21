#include <iostream>
using namespace std;
#include<vector>
#include<queue>
#include<climits>

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
TreeNode<int>* maxDataNode(TreeNode<int> *root){
	
	int max = INT_MIN,i =0;
	TreeNode<int> *maxNode;
	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while(pendingNodes.size()!=0){
		TreeNode<int> *front = pendingNodes.front();
		pendingNodes.pop();
		if(front->data>max){
			max = front->data;
			maxNode = front;
		}
		for(i=0;i<front->child.size();i++){
			pendingNodes.push(front->child[i]);
		}
	}
	 return maxNode; 
	
}

int main(){
	TreeNode<int> *root  = takeInput();
	cout<<maxDataNode(root)->data;
}
