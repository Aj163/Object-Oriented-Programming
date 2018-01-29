#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

class Time
{
	int m, s;
public:
	Time()
	{
		m = s = 0;
	}

	void disp()
	{
		system("clear");
		cout<<"\n\n\n\t\t\t"<<m/10<<m%10<<":"<<s/10<<s%10<<"\n\n\n";
	}

	void operator++()
	{
		s++;
		if(s==60)
		{
			m++;
			s=0;
		}
	}
};

int main()
{
	Time t;
	t.disp();

	while(1)
	{
		sleep(1);
		++t;
		t.disp();
	}
}