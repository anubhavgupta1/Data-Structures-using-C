
int helper(Node *head, Node *curr, int n, int count){
	if(curr==NULL){
		return -1;
	}
	if(curr->data==n){
		return count;
	}
	return helper(head,curr->next,n,count+1);
} 


int indexOfNRecursive(Node *head, int n) {
	return helper(head,head,n,0);    
}


