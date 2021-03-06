// kuangbin8h.cpp: 定义控制台应用程序的入口点。
// hdu 4009 add fake root to vector graph using zhuliu algorithm
#define _CRT_SBCURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
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
#include <ctime>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
#define N 1010
#define M 1000010
const int INF = 0x3f3f3f3f;
const double eps = 1e-5;
const double PI = acos(-1);
#define fi first
#define se second
#define rep(i, lll, nnn) for(int i = (lll); i <= (nnn); i++)
int n, m,x,y,z;
struct Hold {
	int x, y, z;
	Hold(int xx, int yy, int zz) : x(xx), y(yy), z(zz) {};
	Hold() {};
}holds[N];
struct Edge {
	int u, v;
	ll w;
}edge[M];
int l, pos;
ll sum;
int pre[N], id[N], vis[N];
ll in[N];
ll zhuliu(int root)
{
	ll res = 0;
	int u, v;
	while (true) {
		//cout << "cnt " <<cnt<<endl;
		rep(i, 0, n - 1) in[i] = INF;
		rep(i, 0, l - 1) {
			u = edge[i].u, v = edge[i].v;
			if (u != v && edge[i].w < in[v]) {
				pre[v] = u; in[v] = edge[i].w;
				if (u == root) pos = i;
				///怎么想都想不明白，我觉得pos不需要循环更新，只要第一次就行了
				///但是可能出现缩点后产生平行边的情况
				///于是就可能会换pos，平行边可能被减去什么值之类的
				///循环的时候是扫所有的从root出去的边
				///经过不停的缩点循环pos是肯定会指向那个命中注定的i的
			}
		}
		rep(i, 0, n - 1)
			if (i != root && in[i] == INF)
				return -1;
		int tn = 0;
		memset(id, -1, sizeof id);
		memset(vis, -1, sizeof vis);
		in[root] = 0;
		rep(i, 0, n - 1) {
			res += in[i];
			v = i;
			while (vis[v] != i && id[v] == -1 && v != root) {
				vis[v] = i; v = pre[v];
			}
			if (v != root && id[v] == -1) {
				for (int u = pre[v]; u != v; u = pre[u])
					id[u] = tn;
				id[v] = tn++;
			}
		}
		if (tn == 0) break;
		rep(i, 0, n - 1) if (id[i] == -1) id[i] = tn++;
		for (int i = 0; i < l; i++) {
			v = edge[i].v;
			edge[i].u = id[edge[i].u];
			edge[i].v = id[edge[i].v];
			if (edge[i].u != edge[i].v)
				edge[i].w -= in[v];
			//            else
			//                swap(edge[i], edge[--l]);
		}
		n = tn;
		root = id[root];
	}
	//cout <<cnt <<endl;
	return res;
}
int main()
{/*
#ifndef ONLINE_JUDGE
	freopen("data.txt", "r", stdin);
	int TIMESTART = clock();
#endif*/
	while (scanf("%d%d%d%d", &n, &x,&y,&z),n||x||y||z) {
		l = 0;
		sum = 0;
		int a, b, c;
		rep(i, 1, n) {
			
			scanf("%d%d%d", &a, &b, &c);
			holds[i] = Hold(a, b, c);
			
		}
		rep(i, 1, n)
		{
			scanf("%d", &a);
			rep(j, 1, a)
			{
				scanf("%d", &b);
				int ha = holds[a].z, hb = holds[b].z;
				int big = max(ha, hb) == ha ? a : b, small = max(ha, hb) != ha ? a:b;
				edge[l].u = big;
				edge[l].v = small;
				edge[l++].w =  y * (abs(holds[a].x - holds[b].x) + abs(holds[a].y - holds[b].y));
				edge[l].u = small;
				edge[l].v = big;
				edge[l++].w = z + y * (abs(holds[a].x - holds[b].x) + abs(holds[a].y - holds[b].y));
			}
		}
		rep(i, 1,  n ) {///按顺序加边，保证v的顺序性
			edge[l].u = 0;
			edge[l].v = i ;
			edge[l++].w = holds[i].z*x;
		}
		ll ans = zhuliu(0);
		if (ans == -1 ) puts("impossible");
		else printf("%\n", ans );
		putchar('\n');
	}/*
#ifndef ONLINE_JUDGE
	int TIMEEND = clock();
	printf("\n%fs\n", 1.0 * (TIMEEND - TIMESTART) / 1000.0);
#endif*/
	return 0;
}
