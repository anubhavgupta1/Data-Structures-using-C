
node* mergeList(node *a, node *b){
    node* result = NULL;
     if (a == NULL) 
        return (b); 
    else if (b == NULL) 
        return (a); 
  
    /* Pick either a or b, and recur */
    if (a->data <= b->data) { 
        result = a; 
        result->next = mergeList(a->next, b); 
    } 
    else { 
        result = b; 
        result->next = mergeList(a, b->next); 
    } 
    return (result); 
}



node* findMid(node *fast, node *slow){
    if(fast->next == NULL){
        return slow;
    }
    if(fast->next->next == NULL){
        return slow;
    }
    return findMid(fast->next->next,slow->next);
}


void helper(node **headRef){
	node *head = *headRef;  
    if ((head == NULL) || (head->next == NULL)) { 
        return; 
    }
    node *mid = findMid(head,head);
    node *head2=mid->next;
    helper(&head2);
    mid->next=NULL;
    helper(&head);
    *headRef = mergeList(head,head2);
    
}





node* mergeSort(node *head) {
    helper(&head);
    return head;
    
}
