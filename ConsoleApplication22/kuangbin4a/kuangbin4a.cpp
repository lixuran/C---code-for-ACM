// kuangbin4a.cpp: 定义控制台应用程序的入口点。
//poj 2387

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
vector<pair<int, int>> graph[1010];
int dis[1010];
priority_queue<pair<int, int>> marks;
void bellford()
{
	marks.push(make_pair(0,1));
	dis[1] = 0;
	while (!marks.empty())
	{
		pair<int,int> cur = marks.top();
		marks.pop();
		if (cur.first > dis[cur.second])continue;
		for (int i = 0; i < graph[cur.second].size(); i++)
		{
			int end = graph[cur.second][i].first;
			if (dis[end] > dis[cur.second] + graph[cur.second][i].second)
			{
				dis[end] = dis[cur.second] + graph[cur.second][i].second;
				marks.push(make_pair(dis[end],end));

			}
		}
	}



}
int main()
{
	int t, n;
	cin >> t >> n;
	int s, e, l;//start end length
	memset(dis, INF, sizeof(dis));
	for (int i = 0; i < t; i++)
	{
		cin >> s >> e >> l;
		graph[s].push_back(make_pair(e, l));
		graph[e].push_back(make_pair(s, l));
	}
	bellford();
	cout << dis[n];
    return 0;
}

