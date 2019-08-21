class Pair{
    public: 
    node *head;
    node *tail;
};




Pair reverse1(node *head){
    if(head==NULL || head->next==NULL){
        Pair ans;
        ans.head= head;
        ans.tail= head;
        return ans;
    }
    Pair smallHead = reverse1(head->next);
    smallHead.tail->next = head;
    head->next = NULL;
    Pair temp; 
    temp.head = smallHead.head;
    temp.tail =  head;
    return temp;
   
}

node* reverse(node *head){
    return reverse1(head).head;
}

node *reverse_linked_list_rec(node *head)
{
    return reverse(head);
}
