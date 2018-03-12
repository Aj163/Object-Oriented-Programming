#include <bits/stdc++.h>
using namespace std;

class A
{
public:
	A(){
		cout<<"A\n";
	}
};

class B : virtual public A
{
public:
	B(){
		cout<<"B\n";
	}
};

class C : virtual public A
{
public:
	C(){
		cout<<"C\n";
	}
};

class D : public B, public C
{
public:
	D(){
		cout<<"D\n";
	}
};

int main()
{
	D d;
}