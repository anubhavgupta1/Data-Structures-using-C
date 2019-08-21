


int sumOfAllNodes(BinaryTreeNode<int>* root) {
    if(!root){
        return 0;
    }
    return root->data + sumOfAllNodes(root->left) + sumOfAllNodes(root->right);

}
