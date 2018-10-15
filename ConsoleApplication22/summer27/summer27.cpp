// summer252.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int parent[30010], r[30010];


int getparent(int a)
{//获取a的根,并把a的父节点改为根
	if (parent[a] == a)
		return a;
	int t = getparent(parent[a]);
	r[a] = (r[a] + r[parent[a]]) % 3;
	parent[a] = t;
	//cout << 1;
	return parent[a];
}

bool merge(int x,int a, int b)
{
	int p1 = getparent(a);
	int p2 = getparent(b);
	//cout << a << ' ' << b << ' ' << p1 << ' ' << p2 << endl;
	if (p1 == p2) { 
		
		int x1 = (r[a] - r[b] + 3) % 3;
		if(!x1 && x==1)
		return true;
		if (x1 == 1 && x == 2)
		return true;
		//cout << x << ' ' << a << ' ' << b <<' '<<r[b]<<' '<<r[a]<< endl;
		return false;
	}
	parent[p1] = p2;int x2;
	if (x == 1)
		x2 = r[b];
	else
		x2 = (r[b] + 1) % 3;
		r[p1] = (x2-r[a]+3)%3;
	return true;
}
int main()
{
	int n,k,count=0;
	cin >> n >> k;
	for (int i = 0;i < 30010;i++)
	{
		parent[i] = i;
		r[i] = 0;
	}
	while (k--)
	{
		int x, y,z,p1,p2;
		cin >> x >> y >> z;
		if ((y == z&&x==2) || y > n || z > n)
		{
			//cout << x << ' ' << y << ' ' << z << endl;
			count++;
			continue;
		}
		
		if (!merge(x,y, z))
			count++;
	}
	cout << count;
	return 0;
}

