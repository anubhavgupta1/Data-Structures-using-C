

node* reverse(node *head, node *curr, node *prev, node *temp){
    if(curr==NULL){
        head = prev;
        return head;
    }
    temp = curr->next;
    curr->next = prev;
    return reverse(head, temp, curr, temp);
   
}

node *reverse_linked_list_rec(node *head)
{
    return reverse(head,head,NULL,NULL);
}
