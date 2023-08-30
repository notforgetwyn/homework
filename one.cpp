#include<iostream>
#include<vector>
using namespace std;
void common_divivor_multiple(int a, int b)
{
	int tm1 = a*b, tm2 = 0;
	while (b != 0)
	{
		tm2 = b;
		b = a%b;
		a = b;
	}
	cout << a << tm1 / a;
}