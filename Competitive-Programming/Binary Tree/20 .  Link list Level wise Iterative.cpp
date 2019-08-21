#include<queue>
#include<vector>


void helper(vector<node<int>*> &ans,queue<BinaryTreeNode<int>*> &q) {
    node<int> *head;
    node<int> *tail;
    head = tail = NULL;
    q.push(NULL);    
    while(q.size()!=0){
        BinaryTreeNode<int> *current = q.front();
        q.pop();
        if(current){
            if(current->left){
                q.push(current->left);
            }
            if(current->right){
                q.push(current->right);
            }
            node<int>* newNode = new node<int>(current->data);
            if(!head){
                head = newNode;
                tail = head;
            }
            else{
                tail->next = newNode;
                tail= tail->next;
            }
        }
        if(!current){
            ans.push_back(head);
            head=NULL;
            tail = NULL;
            if(q.size()!=0){
                q.push(NULL);    
            }
            
        }
    }

}

vector<node<int>*> createLLForEachLevel(BinaryTreeNode<int> *root){
    vector<node<int>*> ans;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    helper(ans,q);
    return ans;
}
