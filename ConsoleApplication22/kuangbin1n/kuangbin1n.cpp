// kuangbin1n.cpp: 定义控制台应用程序的入口点。
//HDU - 2612
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
#include <map>
using namespace std;
typedef pair<int, int> pos;
struct N
{
	pos position;
	int step;
};
map<pos, int> distances[2];
int m, n;
char road[210][210];
queue<pos> kfcs;
queue<N> positions;
int vi[210][210];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
void bfs(int index)
{
	while (!positions.empty())
	{
		N cur = positions.front();
		positions.pop();
		
		int x = cur.position.first, y = cur.position.second;
		//cout << x << ' ' << y << '\n';
		
		if (road[x][y] == '@')distances[index][cur.position]= cur.step;
		for (int i = 0; i < 4;i++)
		{
			int x1 =x + dx[i];
			int y1 = y + dy[i];
			if (!vi[x1][y1] && road[x1][y1] != '#'&&x1 < n&&x1 >= 0 && y1 < m&&y1 >= 0)
			{
				vi[x1][y1] = 1;
				positions.push({ make_pair(x1,y1),cur.step + 1 });
			}
		}
	}
	while (!positions.empty())positions.pop();


}
int main()
{
	pos Y, M;
	while (cin >> n >> m)
	{
		memset(road, ' ', sizeof(road));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> road[i][j];
				if (road[i][j] == '@')kfcs.push(make_pair(i, j));
				if (road[i][j] == 'Y') { Y.first = i; Y.second = j; }
				if (road[i][j] == 'M') { M.first = i; M.second = j; }
				
			}
		}
		memset(vi, 0, sizeof(vi));
		positions.push({ Y,0 });
		vi[Y.first][Y.second] = 1;
		bfs(0);

		memset(vi, 0, sizeof(vi));
		positions.push({ M,0 });
		vi[Y.first][Y.second] = 1;
		bfs(1);
		int minimum = 1000;
		map<pos, int>::iterator j = distances[1].begin();
		for (map<pos, int>::iterator i = distances[0].begin() ; i != distances[0].end(); i++, j++)
		{
			//cout << "steps:"<<i->second << ' ' << j->second << '\n';
			if (minimum > i->second+ j->second)
				minimum = i->second + j->second;
		}
		cout << minimum * 11 << '\n';
	}
    return 0;
}

