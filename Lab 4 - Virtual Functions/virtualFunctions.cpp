#include <bits/stdc++.h>
using namespace std;

class A
{
public:
	virtual void disp(){
		cout<<"A\n";
	}
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
	A a;
	B b;
	C c;

	ptr = &a;
	ptr->disp();
	ptr = &b;
	ptr->disp();
	ptr = &c;
	ptr->disp();
}