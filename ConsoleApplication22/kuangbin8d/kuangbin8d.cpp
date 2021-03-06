// kuangbin8d.cpp: 定义控制台应用程序的入口点。
//
#include <cstdio>
#include <cstring>
#include <utility>
#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
#define N 110
#define M 20010
const int INF = 0x3f3f3f3f;
const double eps = 1e-5;
const double PI = acos(-1);
#define fi first
#define se second
#define rep(i, lll, nnn) for(int i = (lll); i <= (nnn); i++)
int t, n, m, u, v, w;
int g[N][N], maxe[N][N], lowc[N], pre[N];
bool vis[N];
int Prim()
{
	fill(lowc, lowc + n + 1, 0);
	fill(vis, vis + n + 1, false);
	memset(maxe, 0, sizeof maxe);
	rep(i, 2, n) lowc[i] = g[1][i], pre[i] = 1;
	vis[1] = true;
	int ans = 0;
	rep(i, 2, n) {
		int minc = INF, p = -1;
		rep(j, 1, n) if (!vis[j] && minc > lowc[j]) {
			minc = lowc[j]; p = j;
		}
		if (p == -1) return -1;
		ans += minc;
		vis[p] = true;
		rep(j, 1, n) {
			if (vis[j] && j != p)
				maxe[j][p] = maxe[p][j] = max(maxe[pre[p]][j], lowc[p]);
			if (!vis[j] && lowc[j] > g[p][j]) {
				lowc[j] = g[p][j];
				pre[j] = p;
			}
		}
	}
	return ans;
	//int g[N][N], maxe[N][N], lowc[N], pre[N];
	/*int ans = 0;
	memset(maxe,0,sizeof(maxe));
	fill(lowc+1,lowc+N+1,INF);
	memset(pre, -1, sizeof(pre));
	memset(vis, false, sizeof(vis));
	rep(i, 2, n) 
		if (g[1][i] < INF) { pre[i] = 1; lowc[i] = g[1][i]; }
	vis[1] = true;
	rep(i, 2, n)
	{
		int minlow = INF, p = -1;
		rep(j, 1, n)
		{
			if (!vis[j] && lowc[j] < minlow) 
			{
				minlow = lowc[j];
				p = j;
			}
		}
		if (p == -1) return -1;
		ans += minlow;
		vis[p] = true;
		rep(i, 1, n)
		{
			if (vis[i] )if(i!=p) { maxe[p][i]=maxe[i][p] = max(maxe[i][pre[p]], minlow); }
			else {
				if (lowc[i] > g[p][i]) { lowc[i] = p; pre[i] = p; }
			}
		}
*/
	//}
	//return ans;
}
int main()
{/*
#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
#endif
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		rep(i, 1, n) rep(j, 1, n)
			g[i][j] = (i == j) ? 0 : INF;
		rep(i, 1, m) {
			scanf("%d%d%d", &u, &v, &w);
			g[u][v] = g[v][u] = w;
		}
		int len = Prim();
		int ans = INF;
		rep(i, 1, n) rep(j, i + 1, n) {
			if (i != pre[j] && j != pre[i] && g[i][j] < INF) {
				ans = min(ans, len + g[i][j] - maxe[i][j]);
			}
		}
		printf("%d %d\n", len, ans);
	}
	return 0;*/
	cin >> t;
	while (t--) {
		cin >> n >> m;
		memset(g, INF, sizeof(g));
		for (int i = 0; i < m; i++)
		{
			cin >> u >> v >> w;
			g[u][v] = w; g[v][u] = w;
		}
		int ans = Prim();
		int sec = INF;
		if (ans != -1)
		{
			rep(i, 1, n )
			{
				rep(j, i + 1, n)
				{
					if (i != pre[j] && j != pre[i] && g[i][j] < INF)
					{
						sec = min(sec, ans + g[i][j] - maxe[i][j]);
					}
				}
			}
			if (sec == ans || sec ==INF)
				cout << "not second " << endl;
			else
				cout << sec << endl;
		}
		else
		{
			cout << "no way" << endl;
		}
	}
}
//#include <cstdio>
//#include <cstring>
//#include <utility>
//#include <iostream>
//#include <map>
//#include <queue>
//#include <algorithm>
//#include <cmath>
//#include <string>
//#include <vector>
//using namespace std;
//typedef pair<int, int> P;
//typedef long long ll;
//#define N 110
//#define M 20010
//const int INF = 0x3f3f3f3f;
//const double eps = 1e-5;
//const double PI = acos(-1);
//#define fi first
//#define se second
//#define rep(i, lll, nnn) for(int i = (lll); i <= (nnn); i++)
//int t, n, m, u, v, w;
//int g[N][N], maxe[N][N], lowc[N], pre[N];
//bool vis[N];
//int g2[N][N];
//int Prim()
//{
//	fill(lowc, lowc + n + 1, 0);
//	fill(vis, vis + n + 1, false);
//	memset(maxe, 0, sizeof maxe);
//	rep(i, 2, n) lowc[i] = g[1][i], pre[i] = 1;
//	vis[1] = true;
//	int ans = 0;
//	rep(i, 2, n) {
//		int minc = INF, p = -1;
//		rep(j, 1, n) if (!vis[j] && minc > lowc[j]) {
//			minc = lowc[j]; p = j;
//		}
//		if (p == -1) return -1;
//		ans += minc;
//		vis[p] = true;
//		rep(j, 1, n) {
//			if (vis[j] && j != p)
//				maxe[j][p] = maxe[p][j] = max(maxe[pre[p]][j], lowc[p]);
//			if (!vis[j] && lowc[j] > g[p][j]) {
//				lowc[j] = g[p][j];
//				pre[j] = p;
//			}
//		}
//	}
//	return ans;
//}
//int main()
//{
//#ifndef ONLINE_JUDGE
//	freopen("data.txt", "r", stdin);
//#endif
//	scanf("%d", &t);
//	rep(Case, 1, t) {
//		printf("Case #%d : ", Case);
//		scanf("%d%d", &n, &m);
//		rep(i, 1, n) rep(j, 1, n)
//			g2[i][j] = g[i][j] = (i == j) ? 0 : INF;
//		rep(i, 1, m) {
//			scanf("%d%d%d", &u, &v, &w);
//			if (g[u][v] == INF) g[u][v] = g[v][u] = w;
//			else if (w < g[u][v]) {
//				g2[u][v] = g2[v][u] = g[u][v];
//				g[u][v] = g[v][u] = w;
//			}
//			else if (w < g2[u][v]) {
//				g2[u][v] = g2[v][u] = w;
//			}
//		}
//		int len = Prim();
//		if (len == -1) {
//			puts("No way");
//			continue;
//		}
//		int ans = INF;
//		rep(i, 1, n) rep(j, i + 1, n) {
//			if (i != pre[j] && j != pre[i] && g[i][j] < INF) {
//				ans = min(ans, len + g[i][j] - maxe[i][j]);
//			}
//			else if (g2[i][j] < INF) {
//				ans = min(ans, len + g2[i][j] - maxe[i][j]);
//			}
//		}
//		//cout << len <<' ' <<ans <<endl;
//		if (ans == INF) puts("No second way");
//		else {
//			printf("%d\n", ans);
//		}
//	}
//	return 0;
//}
