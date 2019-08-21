#include<iostream>
using namespace std;

template <typename T>
class Node {
	public : 
		T data;
		Node<T> *next;

		Node(T data) {
			this -> data = data;
			next = NULL;
		}
};


template <typename T>
class Queue {
	Node<T> *head;
	Node<T> *tail;
	int size;

	public : 

	Queue() {
		head=tail=NULL;
		size=0;
	}

	int getSize() {
		return size;
	}

	bool isEmpty() {
		return head==NULL;
	}

	void enqueue(T element) {
		size++;
		Node<T> *newNode = new Node<T>(element);
		if(isEmpty()){
			newNode->next = head;
			head = newNode;
			tail = head;
			return;
		}
		tail->next = newNode;
		tail = tail->next;
	}

	T front() {
		if(isEmpty(){
			return 0;
		}
		return head->data;
	}

	T dequeue() {
		if(isEmpty()){
			return 0;
		}
		T ans = head->data;
		Node<T> *temp = head;
		head = head->next;
		delete temp;
        size--;
		return ans;
	}
};



int main() {
    
    Queue<int> q;
    
    int choice;
    cin >> choice;
    int input;
    
    while (choice !=-1) {
        if(choice == 1) {
            cin >> input;
            q.enqueue(input);
        }
        else if(choice == 2) {
            int ans = q.dequeue();
            if(ans != 0) {
                cout << ans << endl;
            }
            else {
                cout << "-1" << endl;
            }
        }
        else if(choice == 3) {
            int ans = q.front();
            if(ans != 0) {
                cout << ans << endl;
            }
            else {
                cout << "-1" << endl;
            }
        }
        else if(choice == 4) {
            cout << q.getSize() << endl;
        }
        else if(choice == 5) {
            if(q.isEmpty()) {
                cout << "true" << endl;
            }
            else {
                cout << "false" << endl;
            }
        }
        cin >> choice;
    }
    
}
