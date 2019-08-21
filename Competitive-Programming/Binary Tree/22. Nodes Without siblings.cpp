



void nodesWithoutSibling(BinaryTreeNode<int>* root){
	if(root){
		if((root->left) && (!root->right)){
            cout<<root->left->data<<"\n";
        }
        if((!root->left) && (root->right)){
            cout<<root->right->data<<"\n";
        }
        nodesWithoutSibling(root->left);
        nodesWithoutSibling(root->right);
	}
	
}

