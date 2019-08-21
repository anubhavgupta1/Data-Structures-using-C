void printPathsUtil(BinaryTreeNode<int> *curr_node, int sum,int sum_so_far, vector<int> &path) 
{ 
    if (curr_node == NULL) 
        return; 
  
    // add the current node's value 
    sum_so_far += curr_node->data; 
  
    // add the value to path 
    path.push_back(curr_node->data); 
  
    // print the required path 
    if (sum_so_far == sum ) 
    {  
        for (int i=0; i<path.size(); i++) 
            cout << path[i] << " "; 
  
        cout << endl; 
    } 
  
    // if left child exists 
    if (curr_node->left != NULL) 
        printPathsUtil(curr_node->left, sum, sum_so_far, path); 
  
    // if right child exists 
    if (curr_node->right != NULL) 
        printPathsUtil(curr_node->right, sum, sum_so_far, path); 
  
  
    // Remove last element from path 
    // and move back to parent 
    path.pop_back(); 
} 
   

void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    vector<int> path; 
    printPathsUtil(root, k, 0, path);
}
