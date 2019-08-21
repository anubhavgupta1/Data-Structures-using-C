

BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root) {
    
    if(root){
        if(!root->left && !root->right){
            root= NULL;
            return root;
        }
        
        root->left   = removeLeafNodes(root->left);
        root->right = removeLeafNodes(root->right);
    }
    return root;
    

}
