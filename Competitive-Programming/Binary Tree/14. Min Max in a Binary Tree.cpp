#include<climits>


int findMin(BinaryTreeNode<int> *root){
    if(root==NULL){
          return INT_MAX;
      }
    
      int res = root->data;
      int leftRes = findMin(root->left);
      int rightRes = findMin(root->right);
      if(leftRes < res){
          res = leftRes;
      }
      if(rightRes < res){
          res = rightRes;
      }
      return res;
}

int findMax(BinaryTreeNode<int> *root){
      if(root==NULL){
          return INT_MIN;
      }
      
      int res = root->data;
      int leftRes = findMax(root->left);
      int rightRes = findMax(root->right);
      if(leftRes > res){
          res = leftRes;
      }
      if(rightRes > res){
          res = rightRes;
      }
      return res;
}
 

PairAns minMax(BinaryTreeNode<int> *root) {
    PairAns ans;
    ans.min = findMin(root);
    ans.max = findMax(root);
    return ans;
}
