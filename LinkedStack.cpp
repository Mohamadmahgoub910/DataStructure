#include<iostream>
#include<string>
using namespace std;
template<class t>
class stack {
	struct node {
		t item;
		node* next;
	};
private:
	node*top , *cur;
public:
	stack():top(null){}
	void push(t newitem) {
		node newitemptr = new node;
		if (newitemptr == null) {
			cout << "stack push can't allocate mem \n";
		}
		else {
			newitemptr->item = newitem;
			newitemptr->next = top;
			top = newitemptr;

		}
		
	}
	bool ismpty() {
		return top == null;
	}
	void pop() {
		if (is_empty()) {
			cout << "empty ! \n";
		}
		else
		{
			node *temp = top;
			top = top->next;
			temp = temp->next = null;
			delete temp;
		}
	}
	void getpop(t &element) {
		if (is_empty()) {
			cout << "empty ! \n";
		}
		else
		{
			element = top->item;
			node *temp = top;
			top = top->next;
			temp = temp->next = null;
			delete temp;
		}
	}
	void gettop(t &element) {
		element = top->item;
	}
	void display() {
		cout << "[";
		while (curr != null) {
			cout<<top->item;
			top->next;
		}cout << "]";
	}cout << endl;
};


void main() {
	stack<int>s;
	s.push(2);
	s.push(4);
	s.push(6);
	int y = 0;
	s.gettop(y);
	cout << y << endl;

	int s1 = 0;
	s.pop();
	s.getpop(s1);
	cout << s1 << endl;
}
