#include <iostream>
using namespace std;

template <typename T>

class QueueUsingArray {
	T *data;
	int nextIndex;
	int firstIndex;
	int capacity;

	public :
	QueueUsingArray() {
		data = new T[1];
		nextIndex = firstIndex = -1;
		capacity = 1;
	}

	int getSize() {
		return (capacity-firstIndex+nextIndex+1)%capacity;
	}

	bool isEmpty() {
		return firstIndex == -1;
	}
	bool isFull(){
		return ((nextIndex+1)%capacity)==firstIndex;
	}
	void doubleQueue(){
		int *newData = new int[capacity*2];
		int i=0,j=0;
		for(i=firstIndex;i<capacity;i++){
			newData[j++]=data[i];
		}
		for(i=0;i<firstIndex;i++){
			newData[j++]=data[i];
		}
		capacity = capacity *2;
		delete [] data;
		data=newData;
	}
	// insert element
	void enqueue(T element) {
		if(isFull()) {
			doubleQueue();
		}
		nextIndex= (nextIndex+1)%capacity;
		data[nextIndex]= element;
		if(firstIndex == -1) {
			firstIndex = nextIndex;
		}
	}
	
	T front() {
		if(isEmpty()) {
			cout << "Queue is empty ! " << endl;
			return 0;
		}
		return data[firstIndex];
	}

	T dequeue() {
		if(isEmpty()) {
			cout << "Queue is empty ! " << endl;
			return 0;
		}
		T ans = data[firstIndex];
		if(firstIndex==nextIndex){
			firstIndex=nextIndex=-1;
		}
		else{
			firstIndex = (firstIndex + 1) % capacity;
		}
		return ans;
	}
};


int main() {
	QueueUsingArray<int> q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.enqueue(60);


	cout << q.front() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;

	cout << q.getSize() << endl;
	cout << q.isEmpty() << endl;
}
