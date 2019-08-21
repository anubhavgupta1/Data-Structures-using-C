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


bool isIdentical1(TreeNode<int>* root1, TreeNode<int>* root2, bool isValid) {
    
    if(!root1 && !root2){
        return true;
    }
    
    if((root1 && !root2) || (!root1 && root2)){
        return false;
    }
    
    if(root1->data!=root2->data){
        return false;
    }
    if(root1->child.size()!=root2->child.size()){
        return false;
    }

    for(int i=0;i<root1->child.size();i++)
    {   	
        if(root1->child[i]->data!=root2->child[i]->data){
            isValid = false;
	    break;	
        }

    }

    if(isValid==false){
        return false;
    }
    for(int i=0;i<root1->children.size();i++)
    {   	
        isValid = isIdentical1(root1->children[i],root2->children[i],isValid);   	
    }
    return isValid;

}

bool isIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    
    return isIdentical1(root1,root2,true);
}

int main(){
	TreeNode<int> *root1  = takeInput();
	TreeNode<int> *root2 = takeInput();
	cout<<isIdentical(root1,root2);
	delete root1,root2;
}
