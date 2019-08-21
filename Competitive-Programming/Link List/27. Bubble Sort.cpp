int findLength(node *head) {
    if(head==NULL){
        return 0;
    }
    return 1 + findLength(head->next);
 
}
 
 
node* bubble_sort_LinkedList_itr(node* head)
{
    node *curr,*prev , *temp; 
    int start =0, end=findLength(head),n=end,i=0;
    curr=NULL;
    for(i=0;i<n-1;i++){
        prev=temp=NULL;
        for(curr=head,start=0; curr->next!=NULL && start<end-i-1;start++){
            if(curr->data>curr->next->data){
                temp = curr->next;
                curr->next = temp->next;
                temp->next = curr;
                curr = temp;
                
                if(prev==NULL){
                    head = temp;
                }
                else{
                    prev->next = temp;
                }
 
            }
            prev=curr;
            curr=curr->next;
        }
 
    }
    return head;
}
