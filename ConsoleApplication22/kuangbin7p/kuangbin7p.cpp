// kuangbin7c.cpp: 定义控制台应用程序的入口点。
//poj -3468
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
#define size 100010


#define LL long long

#define inf 1<<30

#define N 210

struct node

{

	int l, r;

	int c;//c用来记录重叠情况

	double cnt, lf, rf;

	//cnt用来计算y的长度，rf,lf分别是对应的左右真实的浮点数端点

}tree[N << 2];

struct Line

{

	double x, y1, y2;

	int f;

}line[N];

//把一段段平行于y轴的线段表示成数组 ，

//x是线段的x坐标，y1,y2线段对应的下端点和上端点的坐标

//一个矩形 ，左边的那条边f为1，右边的为-1，

//用来记录重叠情况，可以根据这个来计算，nod节点中的c

double y[N];//记录y坐标的数组

bool cmp(Line a, Line b)

{

	return a.x<b.x;

}

void build(int l, int r, int rt)

{

	tree[rt].l = l; tree[rt].r = r;

	tree[rt].cnt = tree[rt].c = 0;

	tree[rt].lf = y[l]; tree[rt].rf = y[r];

	if (l + 1 == r) return;

	int mid = (l + r) >> 1;

	build(l, mid, rt << 1);

	build(mid, r, rt << 1 | 1);

}

void calen(int rt)

{

	if (tree[rt].c>0)

	{

		tree[rt].cnt = tree[rt].rf - tree[rt].lf;

		return;

	}

	if (tree[rt].l + 1 == tree[rt].r) tree[rt].cnt = 0;

	else tree[rt].cnt = tree[rt << 1].cnt + tree[rt << 1 | 1].cnt;

}

void updata(int rt, Line e)

{

	if (e.y1 == tree[rt].lf&&tree[rt].rf == e.y2)

	{

		tree[rt].c += e.f;

		calen(rt);

		return;

	}

	if (e.y2 <= tree[rt << 1].rf) updata(rt << 1, e);

	else if (e.y1 >= tree[rt << 1 | 1].lf) updata(rt << 1 | 1, e);

	else

	{

		Line tmp = e;

		tmp.y2 = tree[rt << 1].rf;

		updata(rt << 1, tmp);

		tmp = e;

		tmp.y1 = tree[rt << 1 | 1].lf;

		updata(rt << 1 | 1, tmp);

	}

	calen(rt);

}

int main()

{

	int i, n, j, t, ca = 1;

	double x1, x2, y1, y2;

	while (scanf("%d", &n), n)

	{

		t = 1;

		for (i = 1; i <= n; i++)

		{

			scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);

			line[t].x = x1; line[t].y1 = y1; line[t].y2 = y2; line[t].f = 1;

			y[t] = y1; t++;

			line[t].x = x2; line[t].y1 = y1; line[t].y2 = y2; line[t].f = -1;

			y[t] = y2; t++;

		}

		sort(line + 1, line + t, cmp);

		sort(y + 1, y + t);

		build(1, t - 1, 1);

		updata(1, line[1]);

		double ans = 0;

		for (i = 2; i<t; i++)

		{

			ans += tree[1].cnt*(line[i].x - line[i - 1].x);

			updata(1, line[i]);

		}

		printf("Test case #%d\nTotal explored area: %.2f\n\n", ca++, ans);

	}

	return 0;

}
