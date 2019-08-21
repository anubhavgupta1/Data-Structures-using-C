#include<stack>



bool checkBalanced(char *str) {
	stack<char> s; 
    char x; 
  
    for (int i=0; str[i]!='\0'; i++) 
    {
        
        if (str[i]=='('||str[i]=='['||str[i]=='{') 
        { 
            s.push(str[i]); 
            continue; 
        } 
  
            if(str[i]==')'){
                if (s.empty()){
                   return false; 
                } 
            x = s.top();
            if(x=='{' || x=='['){
                return false;
            }
            s.pop();
        }
        else if(str[i]=='}'){
        if (s.empty()){
           return false; 
        }
            x = s.top();
            if(x=='(' || x=='['){
                return false;
            }
            s.pop();
        }
        else if(str[i]==']'){
           if (s.empty()){
           return false; 
        }             
            x = s.top();
            if(x=='{' || x=='('){
                return false;
            }
            s.pop();
        }   
    } 
  
    return (s.empty()); 

}
