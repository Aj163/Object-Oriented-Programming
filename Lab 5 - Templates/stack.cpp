#include <bits/stdc++.h>
using namespace std;

#define N 1000

template <class T> 
class Stack
{
	T arr[N];
	int pos;
public:
	Stack(){
		pos = -1;
	}

	T top()
	{
		try{
			if(pos == -1)
				throw(0);
			return arr[pos];
		}
		catch(...){
			cout << "\nStack empty\n";
			return (T)NULL;
		}
	}

	T pop()
	{
		try{
			if(pos == -1)
				throw(0);
			return arr[pos--];
		}
		catch(int z){
			cout << "\nStack empty\n";
			return (T)NULL;
		}
	}

	void push(T x)
	{
		try{
			if(pos == N-1)
				throw(0);
			arr[++pos] = x;
		}
		catch(...){
			cout << "\nStack Overflow\n";
		}
	}

	bool empty();
};

template <class T>
bool Stack<T>::empty(){
	if(pos == -1)
		return true;
	return false;
}

int main()
{
	cout << "Working with int...\n";
	Stack<int> s;

	cout << "Pushing 5...\n";
	s.push(5);
	cout << "Pushing 10...\n";
	s.push(10);
	cout << "Popping " << s.pop() << "...\n";
	cout << "Is stack empty ? --> " << s.empty() << endl;
	cout << "Top element : " << s.top() << "\n";
	cout << "Popping " << s.pop() << "...\n";
	cout << "Is stack empty ? --> " << s.empty() << endl;

	cout << "\nTrying to pop again...";
	s.pop();
	cout << endl;

	cout << "Working with string...\n";
	Stack<string> strStack;

	cout << "Pushing \'Hello\'...\n";
	strStack.push("Hello");
	cout << "Pushing \'World\'...\n";
	strStack.push("World");
	cout << "Popping " << strStack.pop() << "...\n";
	cout << "Is stack empty ? --> " << strStack.empty() << endl;
	cout << "Top element : " << strStack.top() << "\n";
	cout << "Popping " << strStack.pop() << "...\n";
	cout << "Is stack empty ? --> " << strStack.empty() << endl;

	

	cout << endl;
}