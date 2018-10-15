// summer24.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int n, s[70], check[70] = {0},j;

bool dfs(int r, int l)
{
	
	cout << r << ' ' << l << endl;
	if (r == 0 && l == 0)
		return true;
	if (!l)
		return  dfs(r, j);
	for (int i = 0;i < n;i++)
	{
		if (!check[i] && s[i] <= l)
		{
			check[i] = 1;
			if (dfs(r - 1, l - s[i]))
				return  true;
			check[i] = 0;
		}
	}
	//check2[r][l] = -1;
	return  false;




}
int main()
{
	
	while (cin >> n)
	{
		if (!n)
			break;
		int sum = 0, max = 0;
		for (int i = 0;i < n;i++)
		{
			cin >> s[i];
			if (s[i] > max)
				max = s[i];
			sum += s[i];
			check[i] = 0;
		}
		for ( j = max+1;j <= sum / 2;j++)
		{
			if (sum%j)
			{
				cout << j << ' ';
				continue;
			}
			if (dfs(n, j))
				cout << j << endl;

		}
	}
    return 0;
}

