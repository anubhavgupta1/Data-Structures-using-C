BinaryTreeNode<int>* helper(int *post,int *in, int pS, int pE, int inS, int inE){  
    if(inS>inE){
        return NULL;
    }
    int rootData = post[pE];
    
    int rootIndex = -1;
    for(int i = inS;i<=inE;i++){
        if(in[i]==rootData){
            rootIndex=i;
            break;
        }
    }
    
    int lPS=pS;
    int lIS=inS;
    int lIE=rootIndex-1;
    int lPE = lIE - lIS + lPS;
        
    
    int rPE = pE-1;
    int rIS= rootIndex + 1;
    int rIE = inE;
    int rPS = lPE + 1; 
    
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    root->left = helper(post,in,lPS,lPE,lIS,lIE);
    root->right = helper(post,in,rPS, rPE, rIS,rIE);
    return root;
}

BinaryTreeNode<int>* getTreeFromPostorderAndInorder(int *post, int postLength, int *in, int inLength) {
    return helper(post,in,0,postLength-1,0,inLength-1);

}
