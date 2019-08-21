


node* helper(node * head, node *curr, node *OHead, node *OTail, node *EHead, node *ETail){
    if(curr==NULL){
        if(OTail==NULL){
            ETail->next = NULL;
            return EHead;
        }
        OTail->next=EHead;
        if(EHead==NULL){
            return OHead;
        }
        ETail->next=NULL;
        return OHead;
    }
    
    
    if(curr->data%2==1){
        if(OHead==NULL){
            OHead=curr;
            OTail=OHead;
            return helper(head,curr->next, OHead,OTail, EHead, ETail );
        }
        else{
            OTail->next=curr;
            return helper(head,curr->next, OHead,OTail->next, EHead, ETail );
        }
    }
    else{
        if(EHead==NULL){
            EHead=curr;
            ETail=EHead;
            return helper(head,curr->next, OHead,OTail, EHead, ETail );
        }
        else{
            ETail->next = curr;
            return helper(head,curr->next, OHead,OTail, EHead, ETail->next );
        }
    }
}


node* arrange_LinkedList(node* head)
{
    if(head==NULL || head->next==NULL){
        return head;
    }
    return helper(head,head,NULL,NULL,NULL,NULL);
}
