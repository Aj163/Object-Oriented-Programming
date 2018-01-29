#include <bits/stdc++.h>
using namespace std;

class Complex
{
	int r, i;
public:
	Complex()
	{
		r = i = 0;
	}

	Complex(int a, int b)
	{
		r = a;
		i = b;
	}

	Complex operator+(Complex c2)
	{
		Complex temp;
		temp.r = r + c2.r;
		temp.i = i + c2.i;
		return temp;
	}

	Complex operator-(Complex c2)
	{
		Complex temp;
		temp.r = r - c2.r;
		temp.i = i - c2.i;
		return temp;
	}

	operator double()
	{
		return sqrt(r*r + i*i);
	}

	void disp(int num)
	{
		if(i>=0)
			cout<<"Complex number "<<num<<" : "<<r<<" + "<<i<<"i\n";
		else
			cout<<"Complex number "<<num<<" : "<<r<<" - "<<-i<<"i\n";
	}
};

int main()
{
	system("clear");

	Complex c1(1, 3);
	c1.disp(1);

	Complex c2(2, -7);
	c2.disp(2);

	cout<<"\nC1+C2+C2+C1-C2\n";
	Complex c3 = c1+c2+c2+c1-c2;
	c3.disp(3);

	cout<<"\nMagnitude of C3 : "<<(double)c3<<endl;
}