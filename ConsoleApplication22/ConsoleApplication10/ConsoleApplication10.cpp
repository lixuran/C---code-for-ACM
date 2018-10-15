// ConsoleApplication10.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <map>
#include <vector>
using namespace std;
vector <int > a,c;
map <vector<int>, int> b;
int id( vector<int> a1)
{
	if (b[a1] > 0)
	{
		return -1;
	}
	return b[a1] = b.size();
}
int main()
{
	int n,d;//d stands for dimension
	cin >> n;
	while(n--)
	{
		cin >> d;
		a.clear();
		b.clear();
		int check,a0;
		for (int j = 0; j < d;j++)
		{
			int ab;
			cin >> ab;
			a.push_back(ab);
		}
		b[a] = 1;
		while (1)
		{
			a0 = a[0];
			check = 1;
			c.clear();
			for (int i = 0; i < d - 1;i++)
			{
				a[i] = abs(a[i] - a[i + 1]);
				c.push_back(a[i]);
				if (a[i] != 0)
					check = 0;
			}
			a[d - 1] = abs(a0 - a[d - 1]);
			c.push_back(a[d-1]);
			if (check && a[d-1]==0)
			{
				printf("ZERO\n");
				break;
			}
			//printf("1 %d\n", b[a]);
			if (id(c) == -1)
			{
				printf("LOOP\n");
				break;
			}
			//printf("2 %d\n", b[a]);
		}

	}
    return 0;
}

