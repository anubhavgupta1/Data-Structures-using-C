

node* reverse(node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node *smallHead = reverse(head->next);
    node*temp=smallHead;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = head;
    head->next = NULL;
    return smallHead;
   
}

node *reverse_linked_list_rec(node *head)
{
    return reverse(head);
}

