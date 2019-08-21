
void helperSecondLargest(TreeNode<int> *root,TreeNode<int> **L,TreeNode<int> **S) {
    if(!(*L)){
		*L = root;
	}
	else if( root->data>(*L)->data){
		(*S) = (*L);
		(*L) = root;
	}
	else if(!(*S) || root->data>(*S)->data){
		(*S) = root;
	}
	for(int i = 0; i<root->children.size();i++){
	 	helperSecondLargest(root->children[i],L,S);
	}
	
}

TreeNode<int>* secondLargest(TreeNode<int> *root) {
    TreeNode<int>* L = NULL;
    TreeNode<int>* S = NULL;
	helperSecondLargest(root,&L,&S);
   if(!S){
        return NULL;
    }
    if(L->data==S->data){
        return NULL;
    }
	return S; 
}
