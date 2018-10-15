// summer8.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
//#include <steamstring>
using namespace std;
int b[60];
struct Bigint {
	int a[60] = {-1};
	Bigint(int x, int y)
	{
		int j = 0;
		for (int i = x;i < y;i++)
		{
			a[j++] = b[i];
		}
	}


};
Bigint d[60][50];
int main()
{
	int i, j,m,c[60];
	string a;
	while (cin >> m)
	{
		cin >> a;
		cout << a.size() << endl;
		for (i = 0;i < a.size();i++)
		{
			b[i] = a[i];
			cout << a[i];
		}
		for (i = 0;i < a.size();i++)
		{
			d[i][0] = Bigint(i, a.size() - 1);
		}
		Bigint min=Bigint(0,a.size());
		for (j = 1;j <= m;j++)
		{
			for (i = a.size() - j - 1;i > 0;i--)
			{
				for (int x = i;x <= a.size() - j - 1;x++)
				{
					if (Bigint(i, x) + d[x][m - 1] < min)
					{
						min = Bigint(i, x) + d[x][m - 1];
					}
				}
				d[i][m] = min;
			}
		}
		for (i = 0; d[a.size()-1][m].a[i] != -1;i++)
		{
			cout << d[a.size()][m].a[i];
		}
		cout << endl;
	}
    return 0;
}

