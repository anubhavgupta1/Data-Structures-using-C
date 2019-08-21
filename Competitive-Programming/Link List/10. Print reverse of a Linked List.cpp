/*** Print reverse of a Linked List without actually reversing *****/




void print_linkedlist_spl(node*head)
{
    if(head==NULL){
        return;
    }
    print_linkedlist_spl(head->next);
    cout<<head->data<<" ";
}
