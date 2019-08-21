int length(node *head) {
    if(head==NULL){
        return 0;
    }
    return 1 + length(head->next);
    
}

node* findTail(node *temp){
    if(temp->next==NULL){
        return temp;
    }
    return findTail(temp->next);
}


node* helper(node *head, node *curr, int n, int count){
    if(count==n){
        node *head1 =head;
        head = curr->next;
        curr->next = NULL;
        node* tail = findTail(head);
        tail->next = head1;
        return head;
    }
    return helper(head,curr->next,n,count+1);
}
node* append_LinkedList(node* head,int n)
{
    int len = length(head);
    return helper(head,head,len-n,1);
}
