// summer252.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int parent[30010], sum[30010] , under[30010] ;


int getparent(int a)
{//获取a的根,并把a的父节点改为根
	if (parent[a] == a)
		return a;
	int t = getparent(parent[a]);
	under[a] += under[parent[a]];
	parent[a] = t;
	//cout << 1;
	return parent[a];
}

void merge(int a, int b)
{
	int p1 = getparent(a);
	int p2 = getparent(b);
	//cout << a << ' ' << b << ' ' << p1 << ' ' << p2 << endl;
	//if (p1 == p2)return;
	under[p1] = sum[p2];
		sum[p2] += sum[p1];
		//cout << sum[p2] << ' ' << sum[p1] << endl;
		parent[p1] = p2;
	
}
int main()
{
	int p;
	cin >> p;
	for (int i = 0;i < 30010;i++)
	{
		parent[i] = i;
		sum[i] = 1;
	}
	while (p--)
	{
		char c;
		int x, y;
		cin >> c;
		if (c == 'M')
		{
			cin >> x >> y;
			merge(x, y);
		}
		else
		{
			cin >> x;
			getparent(x);
			cout << under[x]<<endl;
		}
	}
    return 0;
}

