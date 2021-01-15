#include<iostream>
#include<assert.h>
using namespace std;
template<class t>
//const int max_length = 100;
class arrayqueuetype {
private:
	int rear;
	int front;
	int length; // help me with check if it full or empty
	t *arr;
	int max_length;
public:
	arrayqueuetype(int size):rear(max_length -1),front(0),length(0){
		if (size <= 0)
			max_length = 100;
		else
			max_length = size;
		arr = new t[max_length];
	}
	bool isempty() {
		return length == 0;
	}
	bool isfull() {
		return length == max_length;
	}
	void addqueue(t element) {
		if (isfull()) {
			cout << "queue full baby \n";
		}
		// step forward 
		rear = (1 + rear) % max_length;
		arr[rear] = element;
		length++;
	}
	void delqueue() {
		if (isempty()) {
			cout << "empty queue \n";
		}
		front = (1 + front) % max_length;
		length--;
	}
	void getqueadded(t &element) {
		if (isfull()) {
			cout << "queue full baby \n";
		}
		rear = (1 + rear) % max_length;
		arr[rear] = element;
		length++;
	}
	void getquedel(t &element) {
		if (isempty()) {
			cout << "queue empty baby \n";
		}
		front = (1 + front) % max_length;
		arr[rear] = element;
		length--;
	}
	int frontqueue() {
		assert(! isempty());
		return arr[front];
	}
	int rearqueue() {
		assert(!isempty());
		return arr[rear];
	}
	/*void getfront(int &getfront) {
		getfront = arr[front];
	}*/
	void display() {
		/*for (int i = 0; i < length; i++)
		{
			cout << arr[i];

		}*/
		//circular queue:-
		if (isempty()) {
			cout << "empty queue \n";
		}
		else
		{
			cout << "[";
			for (int i = front; i !=rear; i= (1+i)%max_length)
			{
				cout << arr[i]<< " " ;
				// last element isn't here so 
			}
			cout << arr[rear];
			cout << "] \n";
		// but i want add all in the for 
			}
		
	}
	int queuesearch(t element) {
		int pos = -1;
		if (!isempty()) {
			for (int i = 0; i != rear; i = (i + 1) % max_length) {
				if (arr[i] == element) {
					pos = i;
					break;
				}
				// 3amel di 3shan bs lw = arr[rear] a5r element.
				if (pos == -1) {
					if (arr[rear] == element) {
						pos = rear;
					}
				}
				else
					cout << "is empty ! \n";
			}
		}
		return pos;
	}

};
void main() {
	arrayqueuetype<int> q1(5);
	q1.addqueue(10);
	q1.addqueue(20);
	q1.addqueue(30);
	q1.addqueue(40);
	q1.addqueue(50);
	//q1.delqueue();
	//cout<<q1.frontqueue()<<endl; //20
	//cout << q1.rearqueue() << endl;
	//q1.display();
	cout << q1.queuesearch(20) << endl;
}