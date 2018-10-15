// summer6.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <queue>
using namespace std;
 int a[3410][2];
 int b[12900] ;
int main()
{
	int n, m,i=0;
	cin >> n >> m;
	//memset(b, 0, sizeof(b));
	while (i++,i!=n+1)
	{
		cin >> a[i][0] >> a[i][1];
	}
	for (i = 1;i <= m;i++)
	{
		if (a[1][0] <= i)
			b[i] = a[1][1];
		else
		{
			b[i] = 0;
		}
	}
	for (i = 2;i <= n;i++)
	{
		for (int j = m ;j>0;j--)
		{
			//cout << b[j - a[i][0]] + a[i][1] << " " << b[j] << endl;
			if (b[j - a[i][0]] + a[i][1]>b[j] && j>=a[i][0])
				b[j] = b[j - a[i][0]] + a[i][1];
		}
	}
	cout << b[m];
    return 0;
}

