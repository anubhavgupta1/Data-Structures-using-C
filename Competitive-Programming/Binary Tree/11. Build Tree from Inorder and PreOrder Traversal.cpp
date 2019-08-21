

BinaryTreeNode<int>* buildTreeHelper(int *preorder,int *inorder,int preS, int preE, int inS, int inE){
    if(inS>inE){
        return NULL;
    }
    int rootData=preorder[preS];
    
    int rootIndex = -1;
    for(int i = inS;i<=inE;i++){
        if(inorder[i]==rootData){
            rootIndex=i;
            break;
        }
    }
    
    
    int lPreS = preS+1; 
    int lInS=inS; 
    int lInE = rootIndex-1;  
    int rPreE=preE; 
    int rInS=rootIndex+1; 
    int rInE=inE; 
    int lPreE= lInE - lInS + lPreS;
    int rPreS = lPreE+1;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    root->left = buildTreeHelper(preorder,inorder, lPreS,lPreE, lInS, lInE);
    root->right = buildTreeHelper(preorder,inorder, rPreS,rPreE, rInS, rInE);
    return root;
}

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
     return buildTreeHelper(preorder,inorder,0,preLength-1,0,inLength-1);

}
