// kuangban2a.cpp: 定义控制台应用程序的入口点。
//
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

int flag_star;
int fac[10];

struct {
	int father;//initialise as -1 to mark as unvisited
	char dir;
	
}vis[362881];

struct node
{
	int state[10];
	int x;// position of x
};
int Hash(int a[])//求康拓展示

{
	int ans = 0;
	for (int i = 0; i < 9; i++)
	{
		int tmp = 0;

		for (int j = i + 1; j < 9; j++)

		{

			if (a[i] > a[j]) tmp++;

		}

		ans += tmp * fac[8 - i];

	}

	return ans;

}

void prin(int n)//输出方向

{

	if (n != flag_star)

	{

		prin(vis[n].father);

		printf("%c", vis[n].dir);

	}

}

int dir[5][2] = { { 1, 0 },{ -1, 0 },{ 0, 1 },{ 0, -1 } };

char str[5] = "durl";

void swap(int &x, int &y)

{

	int t = x;

	x = y;

	y = t;

}





int bfs()

{

	node star;

	for (int i = 0; i < 8; i++) star.a[i] = i + 1; star.a[8] = 0;

	star.x = 8;

	while (!que.empty()) que.pop();

	que.push(star);

	while (!que.empty())

	{

		node tmp = que.front(); que.pop();

		int flag = Hash(tmp.a);

		//        printf("flag=%d tmp.x=%d\n", flag, tmp.x);

		for (int i = 0; i < 4; i++)

		{

			int x = tmp.x / 3 + dir[i][0];

			int y = tmp.x % 3 + dir[i][1];

			if (0 <= x && x < 3 && 0 <= y && y < 3)

			{

				int t = tmp.x;

				swap(tmp.a[x * 3 + y], tmp.a[tmp.x]);

				tmp.x = x * 3 + y;

				int flag_ = Hash(tmp.a);

				if (vis[flag_].flag == -1)//没有访问过就可以移动(判重)

				{

					vis[flag_].flag = flag;

					vis[flag_].dir = str[i];

					que.push(tmp);

				}

				//还原

				tmp.x = t;

				swap(tmp.a[x * 3 + y], tmp.a[tmp.x]);

			}

		}

	}

	return 0;

}



int main(void)

{

	int i;

	char c[10];

	fac[1] = 1;

	for (i = 2; i < 10; i++)

		fac[i] = fac[i - 1] * i;

	for (i = 0; i < 362881; i++) vis[i].flag = -1;

	bfs();

	while (~scanf("%s", c))

	{

		node star;

		if (c[0] == 'x') { star.a[0] = 0; star.x = 0; }

		else star.a[0] = c[0] - '0';

		for (i = 1; i < 9; i++)

		{

			scanf("%s", c);

			if (c[0] == 'x') { star.a[i] = 0; star.x = i; }

			else star.a[i] = c[0] - '0';

		}

		flag_star = Hash(star.a);

		if (flag_star == 46233) { printf("\n"); continue; }

		if (vis[flag_star].flag == -1) printf("unsolvable");

		else prin(flag_star);

		printf("\n");

	}

	return 0;

}