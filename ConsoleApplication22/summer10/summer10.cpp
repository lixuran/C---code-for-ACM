	// summer10.cpp : 定义控制台应用程序的入口点。
	//

	#include "stdafx.h"
	#include <iostream>
	//#include <cstdio>
	using namespace std;
	int c;
	int a[51][51][51];
	
	int main()
	{
		int n; 
			for (int i = 1;i <= 50;i++)
			{
				for (int j = 1; j <= i;j++)
				{
					for (int k = 1;k <= i - j + 1;k++)
					{
						a[i][j][k] = 0;

						
					}
				}
			}
			for (int j = 1; j <= 50;j++)
			{
				for (int k = j; k <= 50;k++)
				{
					a[j][1][k] = 1;
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
						a[i][j][k] = a[i - 1][j - 1][1];
						continue;
					}
					if (k <= i)
						a[i][j][k] = a[i][j][k - 1] + a[i - k][j - 1][k];
					else
						a[i][j][k] = a[i][j][k - 1];
				}
			}
		}
		while (cin>>n)
		{
			int sum = 0;
			for (int i = 1;i <= n;i++)
			{
				sum+=a[n][i][n-i+1];
			}
			cout << sum<<endl;
			//cout << a[2][2][2] << a[2][2][1];
		}
		return 0;
	}

