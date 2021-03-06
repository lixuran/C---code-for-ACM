// kuangbin6k.cpp: 定义控制台应用程序的入口点。
//poj 1679

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
#define input freopen("input.txt","r",stdin)
#define output freopen("output.txt","w",stdout)
#define For1(i,a,b) for (i=a;i<b;i++)
#define For2(i,a,b) for (i=a;i<=b;i++)
#define Dec(i,a,b) for (i=a;i>b;i--)
#define Dec2(i,a,b) for (i=a;i>=b;i--)
#define Fill(x,a) memset(x,a,sizeof(x))
#define inf 1<<30
const int maxn = 1000;
const int maxm = 500000;
int F[maxn];
int cnt;
int  a[maxn], b[maxn],c[maxn];
struct Edge
{
	int u, v, w;
}edge[maxm];
int used[maxm];
int tol;
int Map[maxn][maxn];
vector<int> se;//selected edges;
void addedge(int u, int v, double w)
{
	edge[tol].u = u;
	edge[tol].v = v;
	edge[tol++].w = w;
}
bool cmp(Edge a, Edge b)
{
	return a.w<b.w;
}
int find(int x)
{
	if (F[x] == -1) return x;
	return F[x] = find(F[x]);
}
int Kruskal(int n)
{
	se.clear();
	sort(edge, edge + tol, cmp);
	int ans = 0;
	int u, v;
	double w;
	for (int i = 0; i<tol; i++)
	{
		u = edge[i].u;
		v = edge[i].v;
		w = edge[i].w;
		int t1 = find(u);
		int t2 = find(v);
		if (t1 != t2)
		{
			ans += w;
			F[t1] = t2;
			cnt++;
			used[i] = 1;
			se.push_back(i);
		}
		if (cnt == n - 1) break;
	}
	if (cnt<n - 1) return 0;
	return ans;
}
bool checkUNI(int ans,int n) {
	int i,j;
	For2(i, 1, n - 1) {
		For1(j, 0, tol)
		{
			if (!used[j] && edge[j].w == edge[i].w && istree(i, j))
				return false;
		}
	}
	return true;
}
bool istree(int i, int j)
{



}
int main()
{
	//input;
	int num;
	cin >> num;
	int i, n, m, x, y, z, ans, t, j, k;
	while (num--)
	{
		cin >> n >> m;
		cnt = ans = tol = 0;
		Fill(Map, 0);
		Fill(F, -1);
		Fill(used, 0);
		For2(i, 1, m) {
			cin >> a[i] >> b[i] >> c[i];
			addedge(a[i], b[i], c[i]);
		}
		//}
		//For2(i, 1, n - 1)
		//	For2(j, i + 1, n)
		//{
		//	addedge(i, j, sqrt((a[i] - a[j])*(a[i] - a[j]) + (b[i] - b[j]) *(b[i] - b[j])));
		//	//addedge(j,i,Map[i][j]);
		//}
		//cin >> m;
		//For2(i, 1, m)
		//{
		//	scanf("%d%d", &x, &y);
		//	int u = find(x);
		//	int v = find(y);
		//	if (u != v)
		//	{
		//		F[u] = v;
		//		cnt++;
		//	}
		//	//F[x]=y;
		//}
		ans = Kruskal(n);
		if(checkUNI(ans,n))
		cout << ans << endl;
		else cout << "Not Unique!" << endl;
	}
	return 0;
}
