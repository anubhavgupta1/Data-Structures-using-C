
Node* helper(Node *head, Node *tail, Node *head1, Node *head2){
    
    if(head1==NULL && head2==NULL){
        tail->next = NULL;
        return head;
    }

    if(head1==NULL){
        if(head2!=NULL){
            tail->next= head2;
            return helper(head,tail->next,head1,head2->next);
        }
    }
    
    if(head2==NULL){
        if(head1!=NULL){
            tail->next=head1;
            return helper(head,tail->next,head1->next,head2);
        }
    }

    if(head1!=NULL && head2!=NULL){
        if(head1->data<head2->data){
            tail->next = head1;
            return helper(head,tail->next,head1->next,head2);
        }
        else{
            tail->next=head2;
            return helper(head,tail->next,head1,head2->next);
        }
    }
}





Node* mergeTwoLLs(Node *head1, Node *head2) {
   Node* head;
   if(head1->data<head2->data){
       head = head1;
       head1 = head1->next;
   }
   else{
       head = head2;
       head2 = head2->next;
   }
   return helper(head,head,head1,head2);
    
}
