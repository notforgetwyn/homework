#include<iostream>
#include<vector>
#include<string>
using namespace std;
#include"STACK.h"
#include"Graph.h"
#include"List.h"
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
char maze[30][50] = { '0' };
//struct coordi
//{
//	int x;
//	int y;
//};
//coordi proce[4] = { {-1,0},{0,1},{1,0},{0,-1} };
//coordi text(coordi point)
//{
//	for (int j = 0; j < 4; j++)
//	{
//		point.x = point.x + proce[j].x;
//		point.y = point.y + proce[j].y;
//		if (point.x > 0 && point.y > 0 && point.x < 30 && point.y < 50&&maze[point.x][point.y]!=1)
//			return point;
//	}
//	coordi resul = { -1,-1 };
//	return resul;
//}
//void k(int x,int y)
//{
//	coordi path[100] = { {0,0} },proce={x,y};
//	int j = 0;
//	while (1)
//	{
//		
//		if (proce.x >= 0 && proce.y >= 0 && proce.x < 30 && proce.y < 50 && maze[proce.x][proce.y] != 1)
//		{
//			path[j].x = proce.x;
//			path[j].y = proce.y;
//			proce = text(proce);
//			j++;
//		}
//		else;
//	}
//}
int main()
{
	/*for (int i = 0; i < 30; i++)
		cin >> maze[i];*/
	List<int>V1;
	V1.CreateList_L(5);
	V1.Traversal_Array();


}