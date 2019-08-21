#include <iostream>
using namespace std;

template <typename T>
class QueueUsingArray {
	T *data;
	int f;//front
	int r;//rear
	int size;
	int capacity;
	
	public :
	QueueUsingArray(int s) {
		data = new T[s];
		f = r= -1;
		capacity = s;
		size =0;
	}

	int getSize() {
		return size;
	}

	bool isEmpty() {
		return f==-1;
	}
	bool isFull(){
		return (r+1)%capacity==f;
	}

	// insert element
	void enqueue(T element) {
		if(isFull()) {
			cout << "Queue Full ! " << endl;
			return;
		}
		size++;
		r = (r+1)%capacity;
		
		data[r] = element;
		if(f==-1){
			f = r;
		}
	}
	
	T front() {
		if(isEmpty()) {
			cout << "Queue is empty ! " << endl;
			return 0;
		}
		return data[f];
	}
	T rear() {
		if(isEmpty()) {
			cout << "Queue is empty ! " << endl;
			return 0;
		}
		return data[r];
	}

	T dequeue() {
		if(isEmpty()) {
			cout << "Queue is empty ! " << endl;
			return 0;
		}
		size--;
		T ans = data[f];
		if(f==r){
			f = r = -1;
		}
		else{
			f = (f+1)%capacity;
		}
		return ans;
	}
};

int main() {
	QueueUsingArray<int> q(5);
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	//q.enqueue(60);


	
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.front() << endl;
	cout << q.getSize() << endl;
	q.enqueue(70);
	q.enqueue(80);
	q.enqueue(90);
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.front() << endl;
	cout << q.rear() << endl;
	
	/*cout << q.isEmpty() << endl;*/
}

