// kuangbin5j.cpp: 定义控制台应用程序的入口点。
//poj 2492


#define _CRT_SBCURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

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

const int N = 200005;
int f[N] ;
int n, num,inter;

int getf(int v)
{
	if (f[v] == v) return v;
	f[v] = getf(f[v]);
	return f[v];
}

void merg(int x, int y)

{
	int xx = getf(x), yy = getf(y);
	if (xx > yy)
	{
		f[yy] = xx;
	}

	else
	{
		f[xx] = yy;
	}
}

void init()
{
	for (int i = 0; i <= num*2; ++i)
	{
		f[i] = i;
	}
}

int main()

{
	scanf("%d", &n);
	while (n--) {
		cin >> num >> inter;
		init();
		int u, v;
		int i = 0;
		for (; i < inter; i++)
		{
			scanf("%d%d", &u, &v);
			int x = getf(u);
			int y = getf(v);
			cout << x << y << "\n";
			if (x == y )
			{
				cout << "found"<<endl;
				break;
			}
			else {
				merg( u, v+num);
				merg(u+num, v);
			}
		}
		if (i == inter) cout << "not found" << endl;
	}
	return 0;
}
