/***
#include <iostream>
#include <vector>
#include <queue>

template <typename T>
class node{
public:
    T data;
    node<T> * next;
    node(T data){
        this->data=data;
        this->next=NULL;
    }
};

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;
#include "solution.h"

BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void print(node<int> *head)
{
    node<int> *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    vector<node<int>*> ans = createLLForEachLevel(root);
    for(int i = 0; i < ans.size(); i++) {
	    print(ans[i]);
    }
}
****/




#include<queue>
#include<vector>


void helper(vector<node<int>*> &ans,queue<BinaryTreeNode<int>*> &q) {
    node<int> *head;
    node<int> *tail;
    head = tail = NULL;
    if(!q.empty()){
        q.push(NULL);    
    }
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
           helper(ans,q);
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
