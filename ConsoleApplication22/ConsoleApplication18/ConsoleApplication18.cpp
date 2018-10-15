// ConsoleApplication18.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
struct Node
{
	double pie;
	int eater;
	double pro=pie*pie / eater;
	bool operator<(const Node & a) const
	{
		return pro < a.pro;
	}
	Node(double p = 0, int e= 0):pie(p), eater(e),pro(p*p) { }
};
priority_queue <Node> a;
int main()
{
	int n, f,x;
	Node b;
	cin >> n >> f;
	f++;
	for (int i = 0;i < n;i++)
	{
		cin >>x;
		a.push(Node(x,1));
	}
	while (f--)
	{
		b = a.top();
		a.pop();
		if(f==0)printf("%.3f", b.pro*3.14159265358979323846);
		b.eater++;
		b.pro = b.pie*b.pie / b.eater;
		//cout << b.pro << endl;
		a.push(b);
	}
    return 0;
}

