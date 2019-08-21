/**** Eliminate duplicates from a sorted Linked List ****/



node* helper(node *head, node *t1, node *t2 ){
    if(t2==NULL){
        t1->next=t2;
        return head;
    }
    if(t1->data==t2->data){
        node *temp = t2;
        t1->next = t2->next;
        delete temp;
        return helper(head,t1,t2->next);
    }
    return helper(head,t2,t2->next);
}




node* eliminate_duplicate(node* head)
{
    if(head==NULL && head->next==NULL){
        return head;
    }
    return helper(head,head, head->next);
    
}
