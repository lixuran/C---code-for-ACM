// summer25.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int parent[30010], t[30010] = {1};

int GetParent(int a)
{//获取a的根,并把a的父节点改为根
	if (parent[a] != a)
		parent[a] =
		GetParent(parent[a]);
	return parent[a];
}

void merge(int a, int b)
{
	int p1 = GetParent(a);
	int p2 = GetParent(b);
	if (p1 == p2)
		return;
	t[p1] += t[p2];
	parent[p2] = p1;
}


int main()
{
	int m, n,num,x,y,j=0;
	while (cin >> n >> m)
	{
		j = 0;
		if (n == 0 && m == 0)break;
		for (int i = 0;i < n; ++i) {
			parent[i] = i;t[i] = 1;
		}
		while (j++ != m)
		{
			cin >> num >> x;
			num--;
			while (num--)
			{
				cin >> y;
				merge(x, y);
			}
		}
		cout << t[GetParent(0)] << endl;

	}

    return 0;
}

