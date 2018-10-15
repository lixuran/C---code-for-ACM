// kuangbin4n.cpp: 定义控制台应用程序的入口点。
//poi 1456	
//super market item value and time out
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
const int N = 200010;
int father[N];
int sum[N];  ///记录当前结点到根结点的距离
struct Node {
	int value;
	int time;
	Node(int valuee, int timee) : value(valuee), time(timee) {};
	Node() {};
	bool operator < (const Node & c) const {// what does this means {
		return value > c.value;//this is wrong think about the same 
	}
};
priority_queue<Node> que;
int F(int x) {//find father
	if (x != father[x]) {
		int t = father[x];
		father[x] = F(father[x]);
		//sum[x] += sum[t];
	}
	return father[x];
}
void merge(int a, int b)
{
	int fa=F(a), fb=F(b);
	father[fa] = fb;
}
int sf(int a, int b) //check father
{
	return F(a) == F(b);
}
int main()

{
	int n;
	while (scanf("%d", &n) != EOF) {
		Node q;
		int checked[N];
		memset(checked, -1, sizeof(checked));
		while (!que.empty()) que.pop();
		for (int i = 0; i <= n; i++) {
			father[i] = i;
			//sum[i] = 0;
		}
		for (int i = 0; i < n; i++)
		{
			cin >> q.value >> q.time;
			que.push(q);
			if (checked[q.time] == -1)
			{
				checked[q.time] = i;
			}
			else
			{
				merge(checked[q.time], i);
			}
		}
		//find sum sum is longlong by greedy
	}
	return 0;
}






#include <cstdio>

#include <iostream>

#include <cstring>

#include <algorithm>

#include <cmath>

using namespace std;

const int maxn = 10005;

int a[10005];

struct node

{

	int sco, ded;

};

int cmp(node x, node y)

{

	if (x.sco == y.sco)

		return x.ded < y.ded;

	return x.sco > y.sco;

}
/*
int main()

{

	int t, n;

	while (~scanf("%d", &n))

	{

		long long sum = 0;

		node f[maxn];

		for (int i = 0; i < n; ++i)

		{

			scanf("%d", &f[i].sco);

			scanf("%d", &f[i].ded);

			sum += f[i].sco;

		}

		sort(f, f + n, cmp);

		long long ans = 0;

		memset(a, 0, sizeof(a));

		for (int i = 0; i < n; ++i)

		{

			int tem;

			for (tem = f[i].ded; tem > 0; --tem)

			{

				if (a[tem] == 0)

				{

					a[tem] = 1;

					break;

				}

			}

			if (tem == 0)

				ans += f[i].sco;

		}

		cout << sum - ans << endl;



	}

	return 0;

}
*/