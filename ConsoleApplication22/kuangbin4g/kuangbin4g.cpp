// kuangbin4n.cpp: 定义控制台应用程序的入口点。
//poi 1847
//

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
int n, a,b;
int dis[MAX_N];
int vis[MAX_N][MAX_N];
struct Node {
	int x, y;//count position
	
	Node(int xx, int yy) :x(xx), y(yy){};
	Node() {};
	bool operator <(const Node &r)const
	{
		return x>r.x;
	}
};
priority_queue<Node> que;
vector<int> G[MAX_N];
int diji()//solve using some balabala improved xiaomoxian method.
{
	while (!que.empty()) que.pop();
	que.push(Node(0, a));
	while (!que.empty())
	{
		Node cur = que.top();
		que.pop();
		cout << cur.y << " " << cur.x << "\n";
		if (vis[cur.y][cur.x])continue;
		if (cur.y == b) return cur.x;
		vis[cur.y][cur.x] = 1;
		for (int i = 0; i < G[cur.y].size(); i++)
		{
			int next = G[cur.y][i];
			cout << next << " ";
			int cost = dis[cur.y] + (i ? 1 : 0);
			if (!vis[next][cost] && dis[next] > cost)
			{
				dis[next] = cost;
				que.push(Node(dis[next], next));
			}
		}
		cout << "\n";
	}

	return dis[b];


}
int main()
{

	cin >> n >> a >> b ;
	memset(dis, INF, sizeof(dis));

	memset(vis, 0, sizeof(vis));
	dis[a] = 0;
	int s,stop;
	for (int i = 1; i <= n; i++)
	{
		cin >> s;
		while (s--)
		{
			cin >> stop;
			G[i].push_back(stop) ;
		}
	}
	int ans = diji();
	if (ans == INF)
		cout << -1;
	else cout << ans;	
	return 0;
}


