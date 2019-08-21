
void printIthNode(Node *head, int i, int x =0) {
    if(head==NULL){
        
        return;
    }
    
    if(i==x ){
        cout<<head->data;
        return;
    }
    printIthNode(head->next,i,x+1);
}
