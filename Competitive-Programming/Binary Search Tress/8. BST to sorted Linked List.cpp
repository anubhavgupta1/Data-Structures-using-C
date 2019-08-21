



void helper(BinaryTreeNode<int>* root,Node<int> **head, Node<int> **tail) {
	if (root == NULL) {
		return;
	}
	helper(root->left,&(*head),&(*tail));
    Node<int>* newNode = new Node<int>(root->data);
    if(!(*head)){
        *head = newNode;
        *tail = *head;
    }
    else{
        (*tail)->next = newNode;
        *tail =  (*tail)->next;
    }
	helper(root->right,&(*head),&(*tail));

}


Node<int>* constructBST(BinaryTreeNode<int>* root) {
    Node<int> *head = NULL;
    Node<int> *tail = NULL;
    helper(root,&head,&tail);
    return head;
        
    
}
