


int lcaBinaryTree(BinaryTreeNode <int>* root , int val1, int val2){
    if(!root){
        return NULL;
    }
     if((val1==root->data)||(val2==root->data)){
         return root->data;
     }
    int a,b;
     if((val1<root->data)&&(val2<root->data)){
        return lcaBinaryTree(root->left,val1,val2);
     }
     if((val1>root->data)&&(val2>root->data)){
        return lcaBinaryTree(root->right,val1,val2);
     }
     if((val1<root->data)&&(val2>root->data)){
        a = lcaBinaryTree(root->left,val1,val2);
        b = lcaBinaryTree(root->right,val1,val2);
     }
     if((val1>root->data)&&(val2<root->data)){
        a = lcaBinaryTree(root->right,val1,val2);
        b = lcaBinaryTree(root->left,val1,val2);
     }
     if((!a) && b){
         return b;
     }
    if((!b) && a){
        return a;
    }
    if(!a && !b){
        return NULL;
    }
    if(a && b){
        return root->data;
    }
}

int lcaInBST(BinaryTreeNode<int>* root , int val1 , int val2){
    return lcaBinaryTree(root,val1,val2);

}
