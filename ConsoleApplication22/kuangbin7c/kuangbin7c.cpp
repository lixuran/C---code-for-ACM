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

long long values[size];
struct node
{
	int l, r,  add;//sum存的是当前根节点下所有枝叶的和
	int color;
	long long sum;
}tree[size << 2];
void pushup(int n)
{
	tree[n].sum = tree[n << 1].sum + tree[n << 1 | 1].sum;
}
void build(int l, int r, int root)
{
	tree[root].l = l;
	tree[root].r = r;
	//tree[root].add = 0;
	if (l == r)
	{
		//scanf("%lld", &tree[root].sum);
		tree[root].color = -1;
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, root * 2);
	build(mid + 1, r, root * 2 + 1);
	pushup(root);
	/*tree[root].l = l;
	tree[root].r = r;
	tree[root].add = 0;
	if (l == r)
	{
		scanf("%lld", &tree[root].sum);
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, root * 2);
	build(mid + 1, r, root * 2 + 1);
	pushup(root);*/
}
void pushdown(int n, int m)//下放
{
	
		/*tree[n << 1].add += tree[n].add;
		tree[n << 1 | 1].add += tree[n].add;
		tree[n << 1].sum += tree[n].add*(m - (m / 2));
		tree[n * 2 + 1].sum += tree[n].add*(m / 2);
		tree[n].add = 0;*/
	tree[n << 1].add += tree[n].add;
	tree[n << 1|1].add += tree[n].add;
	tree[n].add = 0;
	tree[n << 1].sum += tree[n << 1].add * (m - m / 2);
	tree[n << 1 | 1].sum += tree[n << 1 | 1].add * (m / 2);
}
void updata(int l, int r, int v, int root)
{
	/*if (tree[root].l == l && tree[root].r == r)
	{
		tree[root].add += v;
		tree[root].sum += v * (r - l + 1);
		return;
	}
	pushdown(root, tree[root].r - tree[root].l + 1);
	int mid = (tree[root].l + tree[root].r) / 2;
	if (r <= mid)
		updata(l, r, v, root * 2);
	else if (l>mid)updata(l, r, v, root * 2 + 1);
	else
	{
		updata(l, mid, v, root * 2);
		updata(mid + 1, r, v, root * 2 + 1);
	}
	pushup(root);*/

	if (tree[root].l == l && tree[root].r == r)
	{
		tree[root].add += v;
		tree[root].sum += v * (r - l + 1);
		return;
	}
	pushdown(root, tree[root].r - tree[root].l + 1);
	int mid = (tree[root].l + tree[root].r) >> 1;
	if (r <= mid) { updata(l, r, v, root * 2); }
	else if (l > mid) updata(l, r, v, root*2+1);
	else {
		updata(l, mid, v, root << 1);
		updata( mid+1,r, v, root << 1|1);

	}
	pushup(root);
}
long long query(int l, int r, int root)
{
	////if (l > r)return 0;
	//if (tree[root].l == l && tree[root].r == r)
	//{
	//	return tree[root].sum;
	//}
	//pushdown(root,tree[root].r-tree[root].l+1);
	//int mid = (tree[root].l + tree[root].r) >> 1;
	//if (r <= mid) return query(l, r, root<<1);
	//else if (l > mid) return query(l, r, root<<1|1);
	//else return query(l, mid, root << 1) + query(mid + 1, r, root << 1 | 1);

	if (tree[root].l == l && tree[root].r == r)
	{
		return tree[root].sum;
	}
	pushdown(root,tree[root].r-tree[root].l+1);
	int mid = (tree[root].l + tree[root].r) >> 1;
	if (r <= mid) return query(l, r, root << 1);
	else if (l > mid) return query(l, r, root << 1 | 1);
	else {
		return query(l, mid, root << 1) + query(mid + 1, r, root << 1 | 1);
	}
}
int main()
{
	int i, j, t, m, n, x, y, z, ca = 1;
	char c[10];
	while (~scanf("%d", &n)) {


		build(1, n, 1);
		for (i = 1; i <= m; i++)
		{
			/*while (scanf("%c", &c), c != '\n')
			{

			}*/
			scanf("%s", c);
			if (c[0] == 'Q') {
				scanf("%d%d", &x, &y);
				cout << query(x, y, 1) << endl;
			}
			else
			{
				scanf("%d%d%d", &x, &y, &z);
				updata(x, y, z, 1);
			}
		}
	}
		
	
	return 0;
}
