/******




bool containsX(TreeNode<int>* root, int x) {
  	bool isPresent;
    if(root->data == x)
        return true;
    
	for(int i=0;i<root->children.size();i++)
    {   	
    	isPresent= containsX(root->children[i],x);
        if(isPresent){
            return true;
        }
    }
    return false;
}


******/


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
	~TreeNode(){
		for(int i =0; i<child.size();i++){
			delete child[i];
		}
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


bool containsX(TreeNode<int>* root, int x) {
  	bool isPresent;
	for(int i=0;i<root->child.size();i++)
    {   	
    	isPresent= containsX(root->child[i],x); 
		if(isPresent){
			return isPresent;
		}  	
    }
    return (root->data==x);;
}

int main(){
	TreeNode<int> *root  = takeInput();
	cout<<containsX(root,4);
	delete root;
}
