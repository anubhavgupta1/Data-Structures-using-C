

void insertDuplicateNode(BinaryTreeNode<int> *root) {
    if(!root){
        return;
    }
    BinaryTreeNode<int> *duplicate = new BinaryTreeNode<int>(root->data);
    BinaryTreeNode<int> *Left = root->left;
    BinaryTreeNode<int> *Right = root->right;
    root->left = duplicate;
    duplicate->left = Left;
    insertDuplicateNode(Left);
    insertDuplicateNode(Right);

}
