// kuangbin4a.cpp: 定义控制台应用程序的入口点。
//poj 2253

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
#define INF 0x3f3f
#define MAX_N 210
int n;
double G[MAX_N][MAX_N];
struct Point { double x, y; }P[MAX_N];
void Floyd()
{
	for (int k = 0; k < n; k++) {

		for (int i = 0; i < n - 1; i++) {

			for (int j = i + 1; j < n; j++) {

				if (G[i][k] < G[i][j] && G[k][j] < G[i][j]) {

					G[j][i] = G[i][j] = max(G[i][k], G[k][j]);

				}

			}

		}

	}



}
int main()
{
	
	while (cin >> n, n != 0)
	{
		memset(G, INF, sizeof(G));
		int f,s;//first second
		for (int i = 0; i < n; i++)
		{
			cin >> P[i].x>>P[i].y;
		
		}
		for (int i = 0; i < n - 1; i++) {

			for (int j = i + 1; j < n; j++) {

				double x = P[i].x - P[j].x;

				double y = P[i].y - P[j].y;

				double cost = sqrt(x*x + y * y);

				G[i][j] = G[j][i] = cost;

			}

		}
		Floyd();
		cout << G[0][1];
	}
	return 0;
}

