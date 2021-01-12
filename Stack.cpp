#include<iostream>
#include<string>
using namespace std;
const int MAX_SIZE = 5;
class stack {
private:
	int top;
	int item[MAX_SIZE];
public:
	stack() :top(-1) {}
	bool isEmpty()
	{
		return top < 0;
	}
	void push(int element) {
		if (top >= MAX_SIZE-1) {
			cout << "It's Full \n";
		}
		else
		{
			top++;
			item[top] = element;
		}
	}
	void getTop(int &element) {
		if (isEmpty()) {
			cout << "stack empty on getTop";
		}
		else
		{
			element = item[top];
			cout << "top element is " << element << endl;
		}
	}
	void pop() {
		if (isEmpty()){
			cout << "stack empty on pop";
		}
		else
		{
			top--;
		}
	}

	void getpop(int &element) {
		if (isEmpty()) {
			cout << "stack empty on pop";
		}
		else
		{
			element = item[top];
			cout << element << endl;
		}
	}
	void print() {
		cout << "[ ";
		for (int i = top; i >= 0; i--)
		{
			cout << item[i] << " ";
		}
		cout << "]";
		cout << endl;

	}

};
void main() {
	stack s;
	s.push(5);
	s.push(15);
	s.push(20);
	s.pop();
	int y = 0;
	//s.getTop(y);
	s.getpop(y);
	s.print();
}