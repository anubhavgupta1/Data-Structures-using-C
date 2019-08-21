


node* kReverse(node*head,int k)
{
    node* current = head;  
    node* temp = NULL;  
    node* prev = NULL;  
    int count = 0;  
      
    /*reverse first k nodes of the linked list */
    while (current != NULL && count < k)  
    {  
        temp = current->next;  
        current->next = prev;  
        prev = current;  
        current = temp;  
        count++;  
    }  
      
    /* next is now a pointer to (k+1)th node  
    Recursively call for the list starting from current.  
    And make rest of the list as next of first node */
    if (temp != NULL)  
    head->next = kReverse(temp, k);  
  
    /* prev is new head of the input list */
    return prev;  
    
    
}
