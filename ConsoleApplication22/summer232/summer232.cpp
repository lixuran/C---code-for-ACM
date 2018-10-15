// summer232.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;
int mina[21] = { 0 }, minv[21] = {0},minarea=0,area=0,m,n;
void  dfs(int v, int l, int r, int h)
{
	//cout << 1;
	
	int maxv=0;
	if (v < 0)
		return;
	if (l == 0)
	{
		if (v)
			return;
		if (minarea > area || minarea == 0)
		{
			minarea = area;
			//cout << minarea<<' ';
		}
		
		return;
	}

	if (area + mina[l] >=  minarea && minarea !=0)
		return;
	if (l >= r || l >= h)
		return;
	if (v < minv[l])
		return;
	for (int i = 1;i <= l;i++)
		maxv += (r - i)*(h - i)*(r-i);
	if (maxv < v)
		return;
	//cout << 2;
	//cout << maxv<<' '<<v << ' ' << l<<' '<<r<<' '<<h << endl;
	for (int i = r;i >= l;i--)
	{
		if (l == m) //底面积
			area = i * i;

		for (int j = h;j>= l;j--)
		{
			area += 2 * i*j;
			//cout << 3;
			dfs(v - i*j*i, l - 1, i-1, j-1);
			area -= 2 * i*j;
		}
	}
	return ;	
}

int main()
{
	int mr,mh,sum=0;
	for (int i = 1;i < 21;i++)
	{
		mina[i] = i*i*2 + mina[i - 1];
		minv[i] = i*i*i+minv[i-1];
		//cout << mina[i] << endl << minv[i] << endl;
	}
	
		while (cin >> n >> m)
		{
			minarea = 0, area = 0;
			if (minv[m] > n)
				cout << 0 << endl;
			else
			{
				mr = sqrt((n - minv[m - 1]) / m) + 1;
				mh = (n - minv[m - 1]) / (m*m) + 1;
				//cout << mr << ' ' << mh << endl;
				 dfs(n, m, mr, mh);
			}
			cout << minarea<<endl;
		}
		
    return 0;
}

