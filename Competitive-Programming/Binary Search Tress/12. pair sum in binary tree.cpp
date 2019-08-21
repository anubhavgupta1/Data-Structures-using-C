#include<climits>


bool hasNode(BinaryTreeNode<int> * node, int data){
   if(!node){
			return false;
		}
		else if(node->data==data){
			return true;
		}
		return hasNode(node->left,data) || hasNode(node->right,data);
}

void printPairs(BinaryTreeNode<int> *curr,BinaryTreeNode<int> *root,int sum){
    if(!curr){
        return;
    }
    if(hasNode(root,sum-curr->data) && curr->data!=INT_MIN ){
        if(curr->data<sum-curr->data){
            cout<<curr->data<<" "<<sum-curr->data<<"\n";    
        }
        else{
            cout<<sum-curr->data<<" "<<curr->data<<"\n"; 
        }
        
        curr->data = INT_MIN;
    }
    printPairs(curr->left,root,sum);
    printPairs(curr->right,root,sum);
}

void nodesSumToS(BinaryTreeNode<int> *root, int sum) {
    printPairs(root,root,sum);
}
