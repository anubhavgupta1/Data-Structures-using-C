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

TreeNode<int>* helperNextLargerElement(TreeNode<int> *root, int x,TreeNode<int> *ans) {
	/*if root is better than x and ans node 
        is null then ans node will be assigned root
        but if root is better than x and ans is not null
        then we have to compare if root is small then assign 
        it to ans otherwise continue with previous ans
        in that case ans is not null so our both conditions fail
        and we continue with previous ans without entering if*/
    if(root->data>x){
		if(!ans || ans->data>root->data){
			ans = root;
		}
	}
	for(int i = 0; i<root->child.size();i++){
		ans = helperNextLargerElement(root->child[i],x,ans);
	}
	return ans;
}

TreeNode<int>* nextLargerElement(TreeNode<int> *root, int x) {
    return helperNextLargerElement(root,x,NULL);
}

int main(){
	TreeNode<int> *root  = takeInput();
	cout<<nextLargerElement(root,10)->data;
	delete root;
}
