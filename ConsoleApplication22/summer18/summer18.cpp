// summer18.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <string>
using namespace std;
int	a, b, c;
struct Point {
	int a;
	int b;
	int c;
	int p;
	Point(int a=0, int b=0,int c=0,int p=0 ) :a(a), b(b),c(c),p(p) {};
};
queue<Point> d;
Point used[10000];
int check[10000] = {0};
int main()
{
	cin >> a >> b >> c;
	d.push(Point(0, 0,0,-1));Point e;
	while (!d.empty())
	{
		e = d.front();
		d.pop();
		if (check[e.a * 100 + e.b])
			continue;
		check[e.a * 100 + e.b] = 1;
		used[e.a * 100 + e.b] = e;
		if (e.a == c || e.b == c)
			break;
		if (e.a != 0)
		{
			d.push(Point(0, e.b, 1, e.a * 100 + e.b));
		}
		if (e.b != 0)	
		{
			d.push(Point(e.a, 0, 2, e.a * 100 + e.b));

		}
		if (e.a != a)
		{
			d.push(Point(a, e.b, 3, e.a * 100 + e.b));

		}
		if (e.b != b)
		{
			d.push(Point(e.a, b, 4, e.a * 100 + e.b));

		}
		if (e.a != 0 && e.b != b)
		{
			if (e.a > b - e.b)
			{

				d.push(Point(e.a - b + e.b, b, 12, e.a * 100 + e.b));
			}
			else
			{
				d.push(Point(0, e.b + e.a, 12, e.a * 100 + e.b));
			}
		}
		if (e.a != a && e.b != 0)
		{
			if (e.b > a - e.a)
			{

				d.push(Point(a, e.b - a + e.a, 21, e.a * 100 + e.b));
			}
			else
			{
				d.push(Point(e.a + e.b, 0, 21, e.a * 100 + e.b));
			}
		}
	}
	if (d.empty())
	{
		cout << "impossible";
		return 0;
	}
	string x;int y = 0;
	while (e.p != -1)
	{
		y++;
		//cout << e.a << ' ' << e.b << endl;
		if (e.c == 1)
			x = "DROP(1)\n"+x;
			
		if (e.c == 2)
			x= "DROP(2)\n"+x ;
		if (e.c == 3)
			x="FILL(1)\n"+x ;
		if (e.c == 4)
			x = "FILL(2)\n"+x;
		if (e.c == 12)
			x= "POUR(1,2)\n"+x;
		if (e.c == 21)
			x= "POUR(2,1)\n" +x;
		e = used[e.p];
	}
	cout << y << endl;
	cout << x;
    return 0;
}

