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


int height(TreeNode<int>* root) {
  	//cout<<"root data is : "<<root->data<<"\n";
  	int h = 0,ans =0;
  	for(int i=0;i<root->child.size();i++)
    {   	
      	h = height(root->child[i]);
      	//cout<<"Height is : "<<h<<"\n";
      	if(h>ans){
      		ans = h;	
		}
    }
  	return ans+1;
  
}

int main(){
	TreeNode<int> *root  = takeInput();
	cout<<height(root);
}
