// day11.cpp: 定义控制台应用程序的入口点。
//
#define _CRT_SBCURE_NO_DEPRECATE
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

const int maxn = 110;
const int INF = 0x3f3f3f3f;
char chess[10][10];
bool orow [10];
bool ocol[10];
int n, k;
int dfs(int row,int k)
{
	int num = 0;
	if (k)
	{
		if (row == n)
			return 0;
		num += dfs(row + 1, k);
		for(int i=0;i<n;i++)
			if (chess[row][i] != '.' && !ocol[i])
			{
				ocol[i] = true;
				num += dfs(row + 1, k - 1);
				ocol[i] = false;
			}

		return num;
	}
	else

	
	return 1;
}
int main()
{
	
	while (cin >> n >> k, n != -1 && k != -1)
	{
		memset(chess, ' ', sizeof(chess));
		memset(orow, false, sizeof(orow));
		memset(ocol, false, sizeof(ocol));

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> chess[i][j];
		cout << dfs(0,k) << "\n";


	}
    return 0;
}

