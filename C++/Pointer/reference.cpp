#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a = 10;
	int &r = a;
	a++;
	cout << r << endl;
	r++;
	cout << a << endl;


}