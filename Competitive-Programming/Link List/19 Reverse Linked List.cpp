



node* helper(node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node *smallHead = helper(head->next);
	node *tail = head -> next;
	tail -> next = head;
	head -> next = NULL;
	return smallHead;
   
}



node *reverse_linked_list_rec(node *head)
{
    return helper(head);
}
