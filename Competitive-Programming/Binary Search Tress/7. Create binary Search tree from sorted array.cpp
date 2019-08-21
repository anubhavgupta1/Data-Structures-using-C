



BinaryTreeNode<int>* helper(int *a, int start, int end,int mid) {
    if(start>end){
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(a[mid]);
    root->left = helper(a,start,mid-1, (start + mid -1)/2);
    root->right = helper(a,mid+1,end, (mid+1+end)/2);
    return root;
    

}



BinaryTreeNode<int>* constructTree(int *a, int n) {
    int mid = (n-1)/2;
    return helper(a,0,n-1,mid);

}
