

vector<int>* helper(BinaryTreeNode<int> *root, vector<int> *v, int x) { 
    if(!root){
        return NULL;
    }
    
   

    if(x==root->data){
        v->push_back(root->data);
    }
    else if(x<root->data){
        if(!helper(root->left,v,x)){
            return NULL;
        }
        v->push_back(root->data);
       
    }
    else if(x>root->data){
        if(!helper(root->right,v,x)){
            return NULL;
        } 
        v->push_back(root->data);
    }
    return v;
} 

vector<int>* findPath(BinaryTreeNode<int> *root , int data){
   vector<int> *v = new vector<int>();
    return helper(root,v,data);
    


}
