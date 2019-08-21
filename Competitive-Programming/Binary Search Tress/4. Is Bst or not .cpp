#include<climits>


int maximum(BinaryTreeNode<int> *root){
    if(!root){
        return INT_MIN;
    }
    
    return max(root->data, max(maximum(root->left),maximum(root->right)));
}


int minimum(BinaryTreeNode<int> *root){
    if(!root){
        return INT_MAX;
    }
    return min(root->data, min(minimum(root->left),minimum(root->right)));
}



bool isBST(BinaryTreeNode<int> *root){
      if(!root){
           return 1;
       }
       int right = minimum(root->right);
       int left = maximum(root->left);
       return ((left<root->data) && (right>=root->data) && isBST(root->right) && isBST(root->left)); 

}
