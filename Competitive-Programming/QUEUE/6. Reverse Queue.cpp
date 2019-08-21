#include <queue>



void  reverseQueue(queue<int> &q){
    // Base case 
    if (q.empty()) 
        return; 
  
    // Dequeue current item (from front)   
    long long int data = q.front(); 
    q.pop(); 
  
    // Reverse remaining queue   
    reverseQueue(q); 
  
    // Enqueue current item (to rear)   
    q.push(data); 
}
