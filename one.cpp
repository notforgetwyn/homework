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
}int non_recurion_fast_exponen(int num, int times)
{
	int resul = num;
	while (times)
	{
		if (times & 1)
		{
			resul = resul * num;
			times = times - 1;
		}
		else
		{
			resul *= resul;
			times = times / 2;
		}
	}
	return resul;
}
int recurion_fast_exponen(int num, int times)
{

}