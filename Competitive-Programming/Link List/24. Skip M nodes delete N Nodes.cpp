

node* helper(node *head,int m, int n){
 
    node * t1= head, *t2, *temp; int count;
    while(t1){
        for(count=1;count<m && t1!=NULL;count++,t1=t1->next){}
        if(t1==NULL){
            return head;
        }
        if(t1->next!=NULL){
             t2=t1->next;
        }
       for(count=1;count<n && t2->next!=NULL;){
            t2=t2->next;
            count++;
            
        }
        if(t2!=NULL){
            temp=t2;
            t2= t2->next;
            t1->next=t2;
            t1=t1->next;
            delete temp;
        }
    }
    return head;
  }

node* skipMdeleteN(node  *head, int M, int N) {
     return helper(head,M,N);

}
