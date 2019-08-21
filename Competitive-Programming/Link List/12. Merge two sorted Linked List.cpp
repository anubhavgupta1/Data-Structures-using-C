


Node* helper(Node *a, Node *b){
    Node* result = NULL;
     if (a == NULL) 
        return (b); 
    else if (b == NULL) 
        return (a); 
  
    /* Pick either a or b, and recur */
    if (a->data <= b->data) { 
        result = a; 
        result->next = helper(a->next, b); 
    } 
    else { 
        result = b; 
        result->next = helper(a, b->next); 
    } 
    return (result); 
}





Node* mergeTwoLLs(Node *head1, Node *head2) {
   return helper(head1,head2);
    
    
}
