#pragma once
template<typename T>
class Graph {
private:
	int leng = 6;
	T edges[6][6] =
	{
	{0   ,10    ,100   ,100  ,100  ,3},
	{100  ,0    ,12     ,5  ,100  ,100} ,
	{100  ,100   ,0    ,100  ,100  ,100},
	{3    ,100   ,100     ,0  ,7    ,100},
	{100  ,100   ,100   ,100  ,0   ,100},
	{100  ,2     ,100   ,6    ,1    ,0}
	};
	string vertex[100] = { "v0","v1","v2","v3","v4","v5" };
	bool sign[100] = { false };

public:
	int check(int dist[])
	{
		int resul = 0, resul2 = 100;
		for (int j = 0; j < 6; j++)
		{
			if (sign[j] == 0)
				if (resul2 > dist[j])
				{
					resul2 = dist[j];
					resul = j;
				}

		}
		return resul;
	}
	void dijkstra(int v)
	{

		string path[100] = { "0" };
		int dist[100] = { 0 };
		sign[v] = { 1 };
		for (int j = 0; j < leng; j++)
		{
			dist[j] = edges[v][j];
			if (dist[j] != 100 || j != v)
				path[j] = vertex[v] + vertex[j];
		}
		for (int num = 0; num < 6; num++)
		{
			int k = check(sign, dist);
			for (int j = 0; j < leng; j++)
			{
				if (dist[j] > dist[k] + edges[k][j])
				{
					dist[j] = dist[k] + edges[k][j];
					path[j] = path[k] + vertex[j];
				}

			}
			sign[k] = 1;
		}
		for (int j = 0; j < 6; j++)
		{
			cout << " The short path from " << vertex[v] << " to " << vertex[j];
			cout << " path " << path[j] << "  short " << dist[j] << endl;
		}
	}
	void Floyd()
	{
		for (int poi = 0; poi < leng; poi++)
		{
			for (int enter = 0; enter < leng; enter++)
				if (edges[enter][poi] != 0 && edges[enter][poi] != 100)
				{
					for (int exit = 0; exit < leng; exit++)
					{
						if (edges[enter][exit] > edges[enter][poi] + edges[poi][exit])

							edges[enter][exit] = edges[enter][poi] + edges[poi][exit];
					}
				}
		}


		for (int j = 0; j < leng; j++)
		{
			for (int k = 0; k < leng; k++)
				cout << edges[j][k] << "  ";
			cout << endl;
		}
	}
	void deep_first_traverse(T start)
	{
		Stack<T>Stack1;
		Stack1.SqInitial();
		Stack1.SqPush(start);
		while (1)
		{
			start = check(start);
			if (start)
			{
				Stack1.SqPush(start);
			}
			else
			{
				cout << Stack1.SqPop;
				start = Stack1.SqGetPop;
			}
		}

	}
};