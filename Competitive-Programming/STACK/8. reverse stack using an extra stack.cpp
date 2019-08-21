
void reverse(stack<int> &input, stack<int> &extra){
	if(input.empty()){
		return;
	}
	int x = input.top();
	input.pop();
	reverse(input,extra);
	extra.push(x);
}


void reverseStack(stack<int> &input, stack<int> &extra) {
	reverse(input,extra);
	while(!extra.empty()){
		int x = extra.top();
		extra.pop();
		input.push(x);
	}	

}
