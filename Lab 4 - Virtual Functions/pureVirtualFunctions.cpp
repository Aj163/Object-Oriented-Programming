#include <bits/stdc++.h>
using namespace std;

class A
{
public:
	virtual void disp() = 0;
};

class B : public A
{
public:
	void disp(){
		cout<<"B\n";
	}
};

class C : public A
{
public:
	void disp(){
		cout<<"C\n";
	}
};

int main()
{
	A *ptr;
	//A a; //Error
	B b;
	C c;

	ptr = &b;
	ptr->disp();
	ptr = &c;
	ptr->disp();
}