// kuangbin5h.cpp: 定义控制台应用程序的入口点。
//poi 1733
//give list of  sub sequence of a sequence and oddity
//check whether it contains error

#define _CRT_SBCURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS


#include <cstdio>

#include <iostream>

#include <cstring>

#include <algorithm>

#include <cmath>

using namespace std;

const int N = 200005;

int f[N], odd[N];

int n, m;



int getf(int v)

{

	if (f[v] == v) return v;

	int t = f[v];

	f[v] = getf(f[v]);

	odd[v] =(odd[v]+ odd[t])&1;

	return f[v];

}



void merg(int x, int y, int u, int v, int w)

{

	if (x > y)

	{

		f[y] = x;

		odd[y] = (2+odd[u] - odd[v] - w)&1;

	}

	else

	{

		f[x] = y;

		odd[x] = (2+w + odd[v] - odd[u])&1;

	}

}

void init()
{
	for (int i = 0; i <= n; ++i)
	{
		f[i] = i;
		odd[i] = 0;
	}
}

int main()

{
	scanf("%d%d", &n, &m);
	
		init();
		int u, v,b;
		string s;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%s", &u, &v, &s);
			if (s.compare("even") == 0)
				b = 0;
			else
				b = 1;
			
			int x = getf(u);
			int y = getf(v);
			cout << x << y << "\n";
			if (x == y  && abs(odd[x]-odd[y])!=b  )
			{
				cout << i+1;
				break;
			}
			else if (x != y)
				merg(x, y, u, v, b);

		}
		
	return 0;
}
