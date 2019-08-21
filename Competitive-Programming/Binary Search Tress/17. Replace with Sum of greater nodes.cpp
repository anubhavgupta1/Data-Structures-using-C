





// Recursive function to add all greater values in every node  
void modifyBSTUtil(BinaryTreeNode<int> *root, int *sum)  
{  
    // Base Case  
    if (root == NULL) return;  
  
    // Recur for right subtree  
    modifyBSTUtil(root->right, sum);  
  
    // Now *sum has sum of nodes in right subtree, add  
    // root->data to sum and update root->data  
    *sum = *sum + root->data;  
    root->data = *sum;  
  
    // Recur for left subtree  
    modifyBSTUtil(root->left, sum);  
}
void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
    int sum = 0;  
    modifyBSTUtil(root, &sum);

}
