#include <bits/stdc++.h>
using namespace std;

template <class T1, class T2>
void copy(T1 a[], T2 b[], int n)
{
	for(int i=0; i<n; i++)
		a[i] = b[i];
}

template <class T>
void copy(T a[], T b[], int n)
{
	for(int i=0; i<n; i++)
		a[i] = b[i];
}


int main()
{
	int b[10] = {65, 66, 67, 68, 69};
	int c[10];
	char a[10];

	cout << "Contents of B :\t";
	for(int i=0; i<5; i++)
		cout << b[i] << "\t";
	cout << endl;

	cout << "\nCopying B into A of type char...\n";
	copy(a, b, 5);

	cout << "Contents of A :\t";
	for(int i=0; i<5; i++)
		cout << a[i] << "\t";
	cout << endl;

	cout << "\nCopying B into C of type int...\n";
	copy(c, b, 5);

	cout << "Contents of C :\t";
	for(int i=0; i<5; i++)
		cout << c[i] << "\t";
	cout << endl;
}