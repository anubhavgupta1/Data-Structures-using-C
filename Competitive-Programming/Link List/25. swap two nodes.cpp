class Obj{
    public:
    node *prev;
    node *cur;
};


Obj findNodes(node* curr, int i){
    int count=0; node *pre;   Obj ans;
    pre=NULL;
    while(count<i && curr!=NULL){
        pre = curr;
        curr=curr->next;
        count++;
    }
    ans.cur = curr;
    ans.prev = pre;    
    return ans;
}


node* swapNodes(node *head,node *prevX,node *prevY,node *currX,node *currY ){  


    
    if(prevX!=NULL){
             prevX->next = currY; 
    }
    else{
        //currX is head
         head = currY;
    }
    
    if(prevY!=NULL){
          prevY->next = currX;    
    }
    else{
        //currY is head
        head = currX;
    }
    node *temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
    return head;
}  




node* helper(node *head, int i, int j){
    Obj ans1 = findNodes(head,i);
    Obj ans2 = findNodes(head,j);
    node *p1, *p2, *c1, *c2;
    p1 = ans1.prev;
    p2 = ans2.prev;
    c1 = ans1.cur;
    c2 = ans2.cur;
    if(c1==NULL || c2==NULL){
        return NULL;
    }
    return swapNodes(head,p1,p2,c1,c2);
    
}


node* swap_nodes(node *head,int i,int j)
{ 
    if(i==j){
        return NULL;
    }
    return helper(head,i,j);

}
 
