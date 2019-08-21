

BinaryTreeNode<int>* searchInBST(BinaryTreeNode<int> *temp , int val){
   if(temp==NULL){
		return NULL;
	}
	else if(temp->data==val){
		return temp;
	}
	else if(temp->data>val){
		if(temp->left){
            return searchInBST(temp->left,val);   
        }
	}
	else{
		if(temp->right){
             return searchInBST(temp->right,val);   
        }
	}

}
