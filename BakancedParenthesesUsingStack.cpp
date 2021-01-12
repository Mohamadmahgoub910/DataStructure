#include<iostream>
#include<string>
#include<stack>
using namespace std;
//paired 
bool arePaired(char open , char close) {
	if (open == '(' && close == ')') 
		return true;
	else if (open == '{' && close == '}') 
		return true;
	else if (open == '[' && close == ']') 
		return true;
	else
		return false;
}
// check 
bool areBalanced(string exp) {
	stack<char>s;
	for (size_t i = 0; i < exp.length(); i++)
	{
		if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(') {
			s.push(exp[i]);
		}
		else if(exp[i] == '}' || exp[i] == ']' || exp[i] == ')')
		{
			if (s.empty() || !arePaired(s.top(),exp[i])) 
				return false;
			else
				s.pop();
			
		}
		//special case if stack is empty
	}
	if (s.empty())
		return true;
	// may u tell him return s.empty this is mean it's wrong;
}

void main() {
	string expression;
	cout << "Enter expression: ";
	cin >> expression;
	if (areBalanced(expression)){
		cout << "Balanced \n";
	}
	else
	{
		cout << "Not Balnced! \n";
	}
}