#include <bits/stdc++.h>
using namespace std;

class Person
{
	char name[100];
public:
	Person(char n[])
	{
		strcpy(name, n);
	}

	Person()
	{
		name[0] = '\0';
	}

	Person operator +(Person p)
	{
		char t[100];
		strcpy(t, name);
		Person temp(strcat(t, p.name));
		return temp;
	}

	int operator <(Person p)
	{
		return strcmp(name, p.name) < 0;
	}

	int operator ==(Person p)
	{
		return strcmp(name, p.name) == 0;
	}

	int operator >(Person p)
	{
		return strcmp(name, p.name) > 0;
	}

	void disp()
	{
		cout<<name;
	}
};

int main()
{
	system("clear");

	char n[4][100] = {"Praveen", "Shashank", "Ashwin", " Joisa"};

	Person p1(n[0]);
	Person p2(n[1]);
	Person p3(n[2]);
	Person p4(n[3]);

	p1.disp();
	cout<<" < ";
	p2.disp();
	cout<<" : "<<(p1<p2)<<endl;

	p1.disp();
	cout<<" > ";
	p2.disp();
	cout<<" : "<<(p1>p2)<<endl;

	p1.disp();
	cout<<" == ";
	p2.disp();
	cout<<" : "<<(p1==p2)<<endl;

	p1.disp();
	cout<<" == ";
	p1.disp();
	cout<<" : "<<(p1==p1)<<endl;

	p3.disp();
	cout<<" + ";
	p4.disp();
	Person p5 = p3+p4;
	cout<<" : ";
	p5.disp();
	cout<<endl;
}