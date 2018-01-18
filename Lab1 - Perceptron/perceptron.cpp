#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-7;

class perceptron
{
	bool i1, i2;
	double eta, bias;
	double w1, w2;

	int d(bool a, bool b, int ans)
	{
		if(logical_and(a, b) > ans)
			return -1;
		return 1;
	}

public:
	perceptron()
	{
		w1 = 39.0;
		w2 = 52.0;
		bias = 100.0;
		eta = 0.01;
	}

	void print()
	{
		cout<<"Weights : "<<w1<<", "<<w2<<endl;
		cout<<"Bias : "<<bias<<endl;
	}

	int logical_and(bool a, bool b)
	{
		return (a*w1 + b*w2 + bias >= 0.0)?1:-1;
	}

	bool train(bool a, bool b, bool o)
	{
		int ans = (o == 1 ?1:-1);
		if(logical_and(a, b) == ans)
		{
			//cout<<"Classified correctly!\n";
			return 1;
		}

		bias += eta*eta*d(a, b, ans);
		w1 += eta*a*d(a, b, ans);
		w2 += eta*b*d(a, b, ans);

		//cout<<"New weights : w1 = "<<w1<<", w2 = "<<w2<<", b = "<<bias<<endl;
		return 0;
	}
}per;

int main()
{
	bool flag = 1;
	bool a, b, o;
	while(flag)
	{
		flag = 0;
		if(per.train(0, 0, 0) == 0)
			flag = 1;
		if(per.train(1, 0, 0) == 0)
			flag = 1;
		if(per.train(0, 1, 0) == 0)
			flag = 1;
		if(per.train(1, 1, 1) == 0)
			flag = 1;
	}

	per.print();

	cout<<(per.logical_and(0, 0) == 1?1:0)<<endl;
	cout<<(per.logical_and(0, 1) == 1?1:0)<<endl;
	cout<<(per.logical_and(1, 0) == 1?1:0)<<endl;
	cout<<(per.logical_and(1, 1) == 1?1:0)<<endl;
}