


int max(int a, int b){  
    return (a >= b)? a: b;  
}


int height(BinaryTreeNode<int> *root){
    if(!root){
        return 0;
    }
    return 1 + max(height(root->left),height(root->right));
}


bool isBalanced(BinaryTreeNode<int> *root) {
   if(!root){
       return true;
   }
   int lh = height(root->left);
   int rh = height(root->right);
   if(((abs(lh-rh))<=1) && isBalanced(root->left) && isBalanced(root->right)){
       return true;
   }
   return false; 

}
