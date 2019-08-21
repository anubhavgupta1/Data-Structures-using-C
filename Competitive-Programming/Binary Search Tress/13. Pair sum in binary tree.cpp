#include <algorithm> 

void pairSum(int a[], int n, int x) {
    int i=0,j=n-1,c1=1,c2=1,c,r;
    while(i<j){
        if(a[i]+a[j]==x){
            while(a[i]==a[i+1]){
                i++;
                c1++;
            }
            while(a[j]==a[j-1]){
                j--;
                c2++;
            }
            r = (i<j)?c1*c2:(c1*(c1-1))/2;
            for(c=0;c<r;c++){
                cout<<a[i]<<" "<<a[j]<<"\n";
            }
            i++;j--;
        }
        else if(a[i]+a[j]>x){
            j--;
        }
        else if(a[i]+a[j]<x){
            i++;
        }
        c1=1;c2=1;
    }
}



int convertArray(BinaryTreeNode<int> *node, int arr[], int i)
{
     if(!node){
         return i;
     }
     arr[i++] = node->data;
     if(node->left){
         i = convertArray(node->left, arr, i);
     }
          
     if(node->right){
          i = convertArray(node->right, arr, i);
     }
         
     return i;
}





void nodesSumToS(BinaryTreeNode<int> *root, int sum) {
    int a[1000];
    int n = convertArray(root,a,0);
    sort(a,a+n);
    pairSum(a,n,sum);
    
}
