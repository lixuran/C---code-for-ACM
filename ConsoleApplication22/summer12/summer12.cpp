// summer10.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
//#include <cstdio>
using namespace std;
int c;
struct Point {
	int x;
	int y;
	int z;
	//bool a[51] = {false};
	Point(int x=0, int y=0, int z=0) :x(x), y(y), z(z) {
	
	}
};
Point a[51][51][51];

int main()
{
	int n;
	for (int i = 1;i <= 50;i++)
	{
		for (int j = 1; j <= i;j++)
		{
			for (int k = 1;k <= i - j + 1;k++)
			{
				a[i][j][k]= Point(0,0,0);


			}
		}
	}
	for (int j = 1; j <= 50;j++)
	{
		for (int k = j; k <= 50;k++)
		{
			a[j][1][k].x = 1;
			if(j%2==1)
				a[j][1][k].z = 1;
			a[j][1][k].y = 1;
			//a[j][1][k].a[j] = true;
		}
	}
	for (int i = 1;i <= 50;i++)
	{
		for (int j = 2; j <= i;j++)
		{
			for (int k = 1;k <= 50;k++)
			{


				if (k == 1)
				{
					a[i][j][k].x = a[i - 1][j - 1][1].x;
					a[i][j][k].z = a[i - 1][j - 1][1].z;
					a[i][j][k].y = 0;
					continue;
				}
				if (k <= i)
				{
					a[i][j][k].x = a[i][j][k - 1].x + a[i - k][j - 1][k].x;
					a[i][j][k].y = a[i][j][k - 1].y;
					
						a[i][j][k].y += a[i - k][j - 1][k-1].y;
					a[i][j][k].z = a[i][j][k - 1].z ;
					if(k%2)
						a[i][j][k].z +=  a[i - k][j - 1][k].z;
				}
				else
				{
					a[i][j][k] = a[i][j][k - 1];
				}
			}
		}
	}
	while (cin >> n)
	{

		int s1 = 0,m,s2=0;
		cin >> m;
		for (int i = 1;i <= n;i++)
		{
			s1 += a[n][i][n - i + 1].y;
			//cout << i<<' ' <<a[n][i][n - i + 1].y<<endl;
			s2 += a[n][i][n - i + 1].z;
		}
		cout << a[n][m][n].x << endl;
		cout << s1<< endl;
		cout << s2 << endl;
		//cout << a[2][2][2] << a[2][2][1];
	}
	return 0;
}

