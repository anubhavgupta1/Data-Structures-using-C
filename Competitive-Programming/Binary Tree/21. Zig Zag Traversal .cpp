


void helper(stack<BinaryTreeNode<int> *> &s1, stack<BinaryTreeNode<int> *> &s2) {
  
    while(!s1.empty()){
        BinaryTreeNode<int> *top = s1.top();
        s1.pop();
        cout<<top->data<<" ";
        if(top->left){
            s2.push(top->left);
        }
        if(top->right){
            s2.push(top->right);
        }
    }
    cout<<"\n";
    
    while(!s2.empty()){
        BinaryTreeNode<int> *top = s2.top();
        s2.pop();
        cout<<top->data<<" ";
        if(top->right){
             s1.push(top->right);   
        }
        if(top->left){
            s1.push(top->left);
        }
    }
    cout<<"\n";
    if(s1.empty() && s2.empty()){
        return;
    }
    if(s1.empty() || s2.empty()){
        helper(s1,s2);
    }
    
 
}

void zigZagOrder(BinaryTreeNode<int> *root){
    stack<BinaryTreeNode<int> *> s1; stack<BinaryTreeNode<int> *> s2;
    if(root){
        s1.push(root);
    }
    helper(s1,s2);
}
