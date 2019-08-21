#include <iostream>
#include <climits>
using namespace std;

/*

#include <iostream>
#include <climits>
using namespace std;

class StackUsingArray {

	int nextIndex;
	int capacity;
	int *data;	

	public :

	StackUsingArray(int n) {
		data = new int[n];
		nextIndex = -1;
		capacity = n;
	}

	// return the number of elements present in my stack
	int size() {
		return nextIndex+1;
	}

	bool isEmpty() {
		return nextIndex == -1;
	}
	bool isFull(){
		return nextIndex==capacity;
	}

	// insert element
	void push(int element) {
		if(isFull()) {
			cout << "Stack full " << endl;
			return;
		}
		data[++nextIndex] = element;
	}

	// delete element
	int pop() {
		if(isEmpty()) {
			cout << "Stack is empty " << endl;
			return INT_MIN;	
		}
		return data[nextIndex--];
	}

	int top() {
		if(isEmpty()) {
			cout << "Stack is empty " << endl;
			return INT_MIN;
		}
		return data[nextIndex];
	}
};

*/

//or


class StackUsingArray {
	int *data;
	int nextIndex;
	int capacity;	

	public :

	StackUsingArray(int totalSize) {
		data = new int[totalSize];
		nextIndex = 0;
		capacity = totalSize;
	}

	// return the number of elements present in my stack
	int size() {
		return nextIndex;
	}

	bool isEmpty() {
		return nextIndex == 0;
	}

	// insert element
	void push(int element) {
		if(nextIndex == capacity) {
			cout << "Stack full " << endl;
			return;
		}
		data[nextIndex] = element;
		nextIndex++;
	}

	// delete element
	int pop() {
		if(isEmpty()) {
			cout << "Stack is empty " << endl;
			return INT_MIN;	
		}
		nextIndex--;
		return data[nextIndex];
	}

	int top() {
		if(isEmpty()) {
			cout << "Stack is empty " << endl;
			return INT_MIN;	
		}
		return data[nextIndex - 1];
	}
};

int main() {
	StackUsingArray s(4);
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);


	cout << s.top() << endl;

	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;

	cout << s.size() << endl;

	cout << s.isEmpty() << endl;

}

