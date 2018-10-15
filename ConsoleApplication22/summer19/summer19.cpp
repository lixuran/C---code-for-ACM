// summer19.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <queue>
#include <string.h>
using namespace std;
#pragma warning( disable : 4996)

struct Point {
	char a1[5];
	int c;
	int check[30] = {0};
	Point(const char *a, int c):c(c)  {
		strcpy(a1, a);
	};
};
queue<Point> d;
queue<char *> e;
int main()
{
	string s;
	char a[5], b[5] ,c[30][5];
	cin >> a >> b;
	int l = strlen(a),g=0;
	while (cin >> c[g++]);
	//cin.getline(cc,300);
	//strcpy(c[i], b);
	/*
	for (int i = 0;i < strlen(cc);i++)
	{
		g = 0;
			 int gg=0;
		if (isalpha(cc[i]))
		{
			c[g][gg++] = cc[i];
		}
		else
		{
			g++;
		}
	}*/
	strcpy(c[g], b);
	d.push(Point(a,1));
	//cout << Point(a, 0).a1<<endl;
	while (!d.empty())
	{
		Point x = d.front();
		if (strcmp(x.a1, b)==0)
		{
			//cout << x.a1<<endl;
			cout << x.c;
			return 0;
		}
		d.pop();
		//cout << x.a1<<endl;
		
		for (int j = 0;j < g+1;j++)
		{
			
			int k,count=0;
			if (x.check[j])
				continue;
			for ( k = 0;k < l;k++)
			{
				if (c[j][k] != x.a1[k])
					count++;
				if (count > 1)
					break;
			}
			//cout << j<<' '<<count<< endl;
			if (count == 1  )
			{
				//cout << j <<' '<<c[j]<< endl;
				Point e= Point(c[j], x.c + 1);
				for (int i = 0;i < 30;i++)
					e.check[i] = x.check[i];
				e.check[j] = 1;
				d.push(e);
			}

		}
	}
	cout << 0;
    return 0;
}

