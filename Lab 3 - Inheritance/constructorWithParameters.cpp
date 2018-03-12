#include <bits/stdc++.h>
using namespace std;

class A
{
	int a;
public:
	A(int x){
		a = x;
	}

	void disp(){
		cout<<a<<endl;
	}
};

class B : public A
{
	int b;
public:
	B(int y, int x):A(x){
		b = y;
	}

	void disp(){
		cout<<b<<endl;
	}
};

int main()
{
	B b(2, 3);
	b.A::disp();
	b.disp();
}