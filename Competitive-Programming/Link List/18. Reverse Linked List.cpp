class Pair{
    public: 
    node *head;
    node *tail;
};




Pair helper(node *head){
    if(head==NULL || head->next==NULL){
        Pair ans;
        ans.head= head;
        ans.tail= head;
        return ans;
    }
    Pair smallHead = helper(head->next);
    smallHead.tail->next = head;
    head->next = NULL;
    smallHead.tail= smallHead.tail->next;
    return smallHead;
   
}

node* reverse(node *head){
    return helper(head).head;
}

node *reverse_linked_list_rec(node *head)
{
    return reverse(head);
}
