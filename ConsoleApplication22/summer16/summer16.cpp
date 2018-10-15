// summer16.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;
vector<int> s[4];
int b[24] = { 0,1,0,1,2,2,2,2,2,2,2,0,1,3,3,3,3,3,3,3,0,1,0,1 };
char c[8] = { 'A','F','B','E','H','C','G','D' };
int re[100] = {-1};
char ans[100];
int l=0,check=1;
int h(int a[]);
void  dfs(int t)
{
	//cout << l<<' '<<t;
	int d1[8] = { s[2][2],s[2][3],s[2][4],s[0][3],s[1][3],s[3][2],s[3][3],s[3][4] }, e;
	e = h(d1);
	//cout << ' ' << e << endl;
	if (t == l && !e)
	{
		int j;check = 0;int cc = 0;
		for (j = 0;j < l;j++)
		{
			if ( ans[j] > c[re[j]])
			{
				cc = 1;
				break;
			}
			if (ans[j] < c[re[j]])
			{
				break;
			}
		}
		if (cc)
		{
			for (j = 0;j < l;j++)
			{
				ans[j] = c[re[j]];
			}
		}
		//cout << endl<<t<<endl;
	}
	
	else if(t+e<=l)
	{
		for (int i = 0;i < 4;i++)
		{
			int x1 = s[i].front(), c = ((i / 2 + 1) * 2) % 4;
			s[i].erase(s[i].begin());
			s[i].push_back(x1);
			s[c][2 + (i % 2) * 2] = s[i][2];
			s[c + 1][2 + (i % 2) * 2] = s[i][4];
			re[t] = i * 2;
			dfs(t + 1);
			re[t] = -1;
			int y2 = s[i].back();
			s[i].pop_back();
			s[i].insert(s[i].begin(), y2);
			s[c][2 + (i % 2) * 2] = s[i][2];
			s[c + 1][2 + (i % 2) * 2] = s[i][4];

			int y1 = s[i].back();
			s[i].pop_back();
			s[i].insert(s[i].begin(), y1);
			s[c][2 + (i % 2) * 2] = s[i][2];
			s[c + 1][2 + (i % 2) * 2] = s[i][4];
			re[t] = i * 2+1;
			dfs(t + 1);
			re[t] = -1;
			int x2 = s[i].front();
			s[i].erase(s[i].begin());
			s[i].push_back(x2);
			s[c][2 + (i % 2) * 2] = s[i][2];
			s[c + 1][2 + (i % 2) * 2] = s[i][4];
		}
	}
}
int h(int a[])
{
	/*
	cout << endl;
	for (int i = 0;i < 8;i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	*/
	int d[4] = {0}, max = 0;
	for (int i = 0;i < 8;i++)
	{
		d[a[i]]++;
	}
	for (int i = 1;i < 4;i++)
	{
		if (max < d[i])
		{
			max = d[i];
		}
	}
	return 8-max;
}
int main()
{
	int a;
	while (cin >> a)
	{
		check = 1;l = 0;//reset
		for (int i = 0;i < 4;i++)
			s[i].clear();
		for (int i = 0;i < 100;i++)
		{
			re[i] = -1;
			ans[i] = 'Z';
		}
		if (a == 0)
			break;
		s[0].push_back(a);
		for (int i = 1;i < 24;i++)
		{
			cin >> a;
			if (i == 6) { s[0].push_back(a); }
			if (i == 8) { s[1].push_back(a); }
			if (i == 15) { s[0].push_back(a); }
			if (i == 17) { s[1].push_back(a);}
			
			s[b[i]].push_back(a);
		}
		/*
		for (int ii = 0;ii < 4;ii++)
		{

			for (int i = 0;i < 8;i++)
			{
				cout << s[ii][i];
			}
			cout << endl;
		}*/
		int d[8] = { s[2][2],s[2][3],s[2][4],s[0][3],s[1][3],s[3][2],s[3][3],s[3][4] },out=1;
		//cout << s[0][3];
		if (!h( d ))
		{
			cout <<  "No moves needed"<<endl;
			check = 0;
			out = 0;
		}
		while (check)
		{
			l++;
			//if (l == 3)break;
			dfs(0);
		}
		if (out)
		{
			for (int i = 0;i < 100;i++)
				if (ans[i] != 'Z')
					cout << ans[i];
				else
				{
					break;
				}
			cout  << endl << l << endl;
		}

	}
	
    return 0;
}

