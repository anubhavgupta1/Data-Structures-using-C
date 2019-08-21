/**** check Palindrome ****/

int length(node *head) {
    if(head==NULL){
        return 0;
    }
    return 1 + length(head->next);
    
}


node* findMid(node *temp,int n, int count){
    if(count==n){
        return temp;
    }
    findMid(temp->next,n,count+1);
}



node* reverse(node *head, node *curr, node *prev, node *temp){
    if(curr==NULL){
        head = prev;
        return head;
    }
    temp = curr->next;
    curr->next = prev;
    return reverse(head, temp, curr, temp);
   
}


bool helper(node *list1, node *list2){
    if(list2==NULL){
        return true;
    }
    if(list2->data!=list1->data){
        return false;
    }
    return helper(list1->next,list2->next);
    
}
bool check_palindrome(node* head)
{
  int n = length(head);
  n = (n%2==0)?n/2:(n+1)/2;
  node *mid = findMid(head, n, 1);
  node* head2 = mid->next;
  mid->next = NULL;
  head2 = reverse(head2,head2,NULL,NULL);
  return helper(head,head2);
}
