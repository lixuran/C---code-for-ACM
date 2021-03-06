// kuangbin2c.cpp: 定义控制台应用程序的入口点。
//

#define _CRT_SBCURE_NO_DEPRECATE
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int a[20][3]; int path[20];

int vi[20];
int m;
int cnt = 0;
void printroute()
{
	printf("%d: ", ++cnt);
	int cur = m;
	while (path[cur] != m) { printf(" %d", cur); }
	printf(" %d\n", m);
}
void dfs(int cur, int step)
{
	if (step == 19) { cout << "19: "<< a[cur - 1][0] << a[cur - 1][1] << a[cur - 1][2]  << '\n'; }
	if (step == 20)
	{
		cout << cur;
		if (cur == m)
			printroute();
		return;
	}
	for (int i = 0; i < 3; i++)
	{
		if (!vi[a[cur-1][i]] && a[cur - 1][i]!=m)
		{
			vi[a[cur-1][i]] = 1;
			path[cur] = a[cur-1][i];
			dfs(a[cur-1][i], step + 1);
				vi[a[cur-1][i]] = 0;

			path[cur] = -1;
		}
	}

}
int main()
{
	for (int i = 0; i < 20; i++)
	{
		//may need to sort the input here
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}
	int index=0;
	while (cin >> m,m!=0) 
	
	{

	
		memset(vi, 0, sizeof(vi));
		memset(path, -1, sizeof(path));
		
		dfs(m, 0);
		
	}
    return 0;
}
/*
using namespace std;

bool v[21][21];//保存结点连通情况
bool f[21];//记录已经过的结点
int p[21];//记录路径
int num;

void dfs(int m, int x, int k)
{
	p[k] = x;
	if (k == 20)
	{
		if (x == m)
		{
			cout << num++ << ": ";
			for (int i = 0; i <= 20; ++i)
				cout << " " << p[i];
			cout << endl;
		}
		return;
	}
	for (int i = 1; i <= 20; ++i)
	{
		if (!f[i] && v[i][x])
		{
			f[i] = 1;
			dfs(m, i, k + 1);
			f[i] = 0;
		}
	}
}

int main()
{
	int a, b, c;
	while (1)
	{
		memset(f, 0, sizeof(f));
		memset(v, 0, sizeof(v));
		num = 1;
		cin >> a;
		if (a == 0)
			break;
		cin >> b >> c;
		v[1][a] = v[1][b] = v[1][c] = 1;
		for (int i = 2; i <= 20; ++i)
		{
			cin >> a >> b >> c;
			v[i][a] = v[i][b] = v[i][c] = 1;
		}
		int m;
		cin >> m;
		dfs(m, m, 0);
	}
	return 0;
}