// kuangbin4a.cpp: 定义控制台应用程序的入口点。
//poj 2253 currency exchange
//different branch have differentchange rate for just two type of curren
//and have charge. ask whether is possible to increase capital by exvhanging 

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
int n,m;
double v;
double count_m[MAX_N];
struct Edge { 
	int x, y;
	double ex,c;//exchange rate , charge

	Edge( int xx,int yy, double exx, double cc):x(xx),  y(yy), ex(exx), c(cc) {};
	Edge() {};
};
Edge G[MAX_N];
int bellman_fold()//solve using some balabala improved xiaomoxian method.
{
	for (int i = 0; i < n - 1; i++)//to check loop positive should not have this restriction error
	{
		for (int j = 0; j < m; j++)
		{
			if ((count_m[G[j].x] - G[j].c)*G[j].ex > count_m[G[j].y])
			{
				count_m[G[j].y] = (count_m[G[j].x] - G[j].c)*G[j].ex;
			}
		}
		if (count_m[0] > v)
			return 1;
	}
	return 0;


}
int main()
{

	int ss;


	cin >> n >> m >> ss >> v;
		memset(count_m, 0, sizeof(count_m));
		count_m[0] = v;
		int f, s;
			double r1,c1,r2,c2;//first second
		for (int i = 0; i < m; i++)
		{
			cin >>f>>s>>r1>>c1>>r2>>c2;
			G[i]=Edge(f,s, r1, c1);
			G[i+m]=Edge(s,f, r2, c2);
			cout << "aaa";
		}
		if(bellman_fold())
		cout << "YES";
		else cout << "NO";
	
	return 0;
}

