// kuangbin1d.cpp: 定义控制台应用程序的入口点。
//POJ - 3279

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
#define inf 300;

int solution[16][16] = { 0 };
int temp[16][16] = { 0 };//storing the current flips solution
int flip[16][16];//storing the map after curtain flips
int m, n;
void printsolution()
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << solution[i][j]<<' ';
		}
		cout << "\n";
	}


}
int getflip()
{
	/*
	for (int i = 0; i < m; i++)
				{
					for (int j = 0; j < n; j++)
					{
						cout << flip[i][j] << ' ';
					}
					cout << "\n";
				}
	cout << "\n";*/
	int curcount = 0;
	for (int i = 1; i<m; i++)

		for (int j = 0; j<n; j++)

		{

			if (flip[i - 1][ j])//（i-1，j）是黑色，就要翻转

			{
				//can separate as a function
				flip[i - 1][j] = 0;
				flip[i ][j] = !flip[i][j];
				if (j>0)	flip[i][j - 1] = !flip[i][j - 1];
				if (j<n - 1)	flip[i][j + 1] = !flip[i][j + 1];
				if (i<m-1)	flip[i+1 ][j] = !flip[i+1][j];
				
			temp[i][j] = 1;
			curcount++;
			}

		}

	return curcount;


}
int main()
{
	int count = inf;
	int ori[16][16];
	cin >> m >> n;
	
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				cin >> ori[i][j];
		//permutation of first line
		for (int i=0;i<1<<n;i++)
		{
			int curbest=0;
			memset(temp, 0, sizeof(temp));
			memcpy(flip, ori, sizeof(ori));

			for (int j = 0; j<n; j++)

			{
				//add to total count here!
				temp[0][j] = i >> j & 1;//在i的状态下，第一行的j是否翻转
				curbest += temp[0][j];
				if (temp[0][j])
				{
					flip[0][j] = !flip[0][j];
					if (j > 0)	flip[0][j - 1] = !flip[0][j - 1];
					if (j < n - 1)	flip[0][j + 1] = !flip[0][j + 1];
					flip[1][j] = !flip[1][j];
				}
			}
			curbest += getflip();
			if (curbest < count)
			{
				count = curbest;
				memcpy(solution , temp,sizeof(temp));
				
			}
		}


		if (count == 300)
			cout << "IMPOSSIBLE";
		else printsolution();
    return 0;
}

