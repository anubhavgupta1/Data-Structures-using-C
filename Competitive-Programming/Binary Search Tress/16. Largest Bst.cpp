#include<climits>



int height(BinaryTreeNode<int>* root){
	if(!root){
		return 0;
	}
	int leftH =  height(root->left);
	int rightH =  height(root->right);
	return (leftH>rightH)?leftH+1:rightH+1;
}

bool isBST(BinaryTreeNode<int>* root, int min = INT_MIN, int max = INT_MAX) {
	if (root == NULL) {
		return true;
	}
	if (root->data < min || root->data > max) {
		return false;
	}
	bool isLeftOk = isBST(root->left, min, root->data - 1);
	bool isRightOk = isBST(root->right, root->data, max);
	return isLeftOk && isRightOk;
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    if(!root){
        return NULL;
    }
    if(isBST(root)){
        return height(root);
    }
    return max(largestBSTSubtree(root->left),largestBSTSubtree(root->right)); 

}
