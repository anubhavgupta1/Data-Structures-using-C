/***** mid of linked list ****/

node* helper(node *fast, node *slow){
    if(fast->next == NULL){
        return slow;
    }
    if(fast->next->next == NULL){
        return slow;
    }
    return helper(fast->next->next,slow->next);
}


node* midpoint_linkedlist(node *head)
{
    return helper(head,head);

}
