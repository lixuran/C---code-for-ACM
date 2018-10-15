// summer11.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int a[105] = {0};
int dp[105][70][70];
int states[70];
int check(int s1, int s2)
{
	//cout << 1;
	while (s1 != 0 && s2 != 0)
	{
		if (s1 & 1 && s2 & 1)
			return 0;
		s1 /=2;
		s2 /=2;
		//cout << 1;
	}
	return 1;
}
int Num(int s1)
{
	int num = 0,i=s1;
	//cout << s1<<endl;
	while (i!=0)
	{
		num += i &1;
		i /=2;
		//cout << i << ' ';
	}
	return num;
}
int s=0,ch=0,m;
void dfs(int x,int y)
{
	int i;
	if (x > m)
	{
		states[ch++] = s;
		return;
	}
	
	if (y == 0)
	{
		s <<= 1;
		dfs(x + 1, 0);
		s /= 2;
		s = 2 * s + 1;

		dfs(x + 1,1);
		s /= 2;
	}
	if (y != 0)
	{
		s *=2;

		dfs(x + 1, (y+1)%3);
		s /= 2;
	}
	//cout << 1;
	

}
int main()
{
	char c;string s;
	int  n,i1=0;
	cin >> n >> m;
	while (i1 != n)
	{
		
		cin >> s;
		stringstream  ss(s);
		while (ss >> c)
		{

			if (c == 'P')
				a[i1]=a[i1]*2;
			else if (c == 'H')
				a[i1] = a[i1]*2+1;
		}
		i1++;
		//cout << a[i1-1]<<endl;
	}
	dfs(1,0);
	int num[70];
	for (int i = 0;i < ch;i++)
	{
		num[i] = Num(states[i]);
		//cout << num[i]<< ' ';
		//cout <<' '<<states[i] << endl;
	}
	//dp[0][j][0] = Num(j) dp[1][i][j] = max{ dp[0][j][0] } +Num(i)
	for (int j = 0;j < ch;j++)
	{
		if (check(a[0], states[j]))
			dp[0][j][0] = num[j];
		else
			dp[0][j][0] = 0;
	}
	for (int j = 0;j < ch;j++)
	{
		for (int k = 0;k < ch;k++)
		{
			if (check(states[j], states[k]) && check(a[1], states[j]))
			{
				dp[1][j][k] = dp[0][k][0] + num[j];
				
				//cout<<check(a[1], states[j])<< ' '<<a[1]<<' '<<states[j]<<endl ;
			}
			else
			{
				dp[1][j][k] = 0;
			}
			//cout << 1 << ' ' << j << ' ' << k << ' ' << dp[1][j][k] << endl;

		}
	}
	//cout << endl << 1;
	for (int i = 2;i < n;i++)
	{
		for (int j = 0;j < ch;j++)
		{
			for (int k = 0;k < ch;k++)
			{
				if (check(states[j], states[k]) && check(a[i], states[j]))
				{
					//cout << check(a[i], states[j]) << ' ' << a[i] << ' ' << states[j] << endl;
					int max = 0;
					for (int m = 0;m < ch;m++)
					{
						if (dp[i - 1][k][m]>max && check(states[j], states[m]))
							max = dp[i - 1][k][m];
						dp[i][j][k] = max + num[j];
					}
				}
				else
				{
					dp[i][j][k] = 0;
				}
			}
		}
	}
	//cout << endl<<1;
	int max = 0;
	for (int j = 0;j < ch;j++)
	{
		for (int k = 0;k < ch;k++)
		{
			if (dp[n-1][j][k]>max)
				max = dp[n-1][j][k];
		}
	}
	cout << max << endl;
    return 0;
}

