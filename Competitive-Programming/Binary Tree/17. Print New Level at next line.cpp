


void printLevelATNewLine(BinaryTreeNode<int>* root){
	queue<BinaryTreeNode<int>*> q;
	BinaryTreeNode<int> *front;
	q.push(root);
	q.push(NULL);
	while(q.size()>1){
		front = q.front();
		q.pop();
		if(!front){
			cout<<"\n";
			q.push(NULL);
		}
		else{
				if(front->left){
					q.push(front->left);
				}
				if(front->right){
					q.push(front->right);
				}
				cout<<front->data<<" ";	
		}
	}
	
}
