//kuangbin6j
//poj3026

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
int a[maxn], b[maxn];
struct Edge
{
	int u, v, w;
}edge[maxm];
int tol;
int aliens=0;
int Map[maxn][maxn];
int vis[maxn][maxn];
int moves[4][2] = { { 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 } };

struct Node {
	int x, y;
	int step;
	Node(int xx, int yy, int stepp) : x(), y(), step() {};
	Node() {};
}nodes[maxm];
void addedge(int u, int v, int w)
{
	edge[tol].u = u;
	edge[tol].v = v;
	edge[tol++].w = w;
}
void bfs(int index) // use bfs to add edge 
{
	queue <Node> que;
	while (!que.empty())que.pop();
	que.push(nodes[index]);
	vis[nodes[index].x][nodes[index].y] = 1;
		while (!que.empty())
		{
			int i;
			Node cur = que.front();
			que.pop();
			if (vis[cur.x][cur.y]) continue;
			vis[cur.x][cur.y] = 1;
			if (Map[cur.x][cur.y] > 0) addedge(index, Map[cur.x][cur.y], cur.step);
			For1(i, 0, 4) {
				int x1 = cur.x + moves[i][0], y1 = cur.y + moves[i][1];
				if (Map[x1][y1] >= 0) que.push(Node(x1, y1, cur.step + 1));
			}
		}

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
	//if (n <= m) return 0;
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
		}
		if (cnt == n - 1) break;
	}
	//if (cnt<n - 1) return 0;
	return ans;
}
int main()
{
	//input;
	int num;
	cin >> num;
	int i, n, m, x, y, z, ans, t, j, k;
	char s[60],c;
	while (num--)
	{
		cin >> m >> n;
		while (scanf("%c", &c),c != '\n')
		{
			
		}
	
		cnt = ans = tol = 0;
		Fill(Map, -1);
		Fill(F, -1);
		For2(i, 1, n)
		{
			
			For1(j, 0, m)
			{
				scanf("%c", &c);
				if (c == ' ') { Map[i][j] = 0; }
				else if (c == 'S' || c == 'A') {
					Map[i][j] = ++aliens;
					nodes[aliens] = Node(i, j, 0);
				}
			}
		}
		For2(i, 1, aliens)
			
		{
			memset(vis, 0, sizeof(vis));
			bfs(i);
			//addedge(i, j, sqrt((a[i] - a[j])*(a[i] - a[j]) + (b[i] - b[j]) *(b[i] - b[j])));
			//addedge(j,i,Map[i][j]);
		}
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
		ans = Kruskal(aliens);
		cout << ans << endl;
	}
	return 0;
}
