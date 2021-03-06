// kuangbin5l.cpp: 定义控制台应用程序的入口点。
//zoj 3261
//star connection destoryed ask for help from powerful
//neighbour	


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

const int N = 200005;
int f[N];
int n, power[N];
vector<int > G[N];
int getf(int v)
{
	if (f[v] == v) return v;
	f[v] = getf(f[v]);
	return f[v];
}
void rebuild()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < G[i].size(); j++)
		{
			if (G[i][j] != -1 && !samef(i,G[i][j]))
			{
				merg(i, G[i][j]);
			}
		}
	}

}
bool samef(int a,int b) {

	return getf(a) == getf(b);
}
void merg(int x, int y)

{
	int xx = getf(x), yy = getf(y);
	if (power[xx] > power[yy] || (power[xx]==power[yy] && xx<yy))
	{
		f[yy] = xx;
	}

	else
	{
		f[xx] = yy;
	}
}

void init(int n)
{
	for (int i = 0; i <= n ; ++i)
	{
		f[i] = i;
	}
}

int main()

{
	while (~scanf("%d", &n)) {
		bool flag = false;
		for (int i = 0; i < n; i++) {
			cin >> power[i];
		}
		init(n);
		int m;
		cin >> m;
		int u, v;
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
		}
		int q,t1,t2;
		string s;
		cin >> q;
		while (q--) {
			cin >> s;
			if (s == "query") {
				cin >> t1;
				if (flag)
					rebuild();
				if (getf(t1) != t1)//root should be strongest
					cout <<power[ getf(t1)] << endl;
				else
					cout << -1 << endl;
			}
			else {
				flag = true;	
				cin >> t1 >> t2;
				for (int i = 0; i < G[t1].size(); i++)
				{
					if (G[t1][i] == t2)G[t1][i] = -1;
				}
				for (int i = 0; i < G[t2].size(); i++)
				{
					if (G[t2][i] == t1)G[t2][i] = -1;
				}
			}
		
		}
			/*
			int x = getf(u);
			int y = getf(v);
			cout << x << y << "\n";
			if (x == y)
			{
				cout << "found" << endl;
				break;
			}
			else {
				merg(u, v + num);
				merg(u + num, v);
			}
		}
		if (i == inter) cout << "not found" << endl;*/
	}

	return 0;
}

/*
#include<iostream>

#include<cstring>

#include<math.h>

#include<stdlib.h>

#include<cstring>

#include<cstdio>

#include<utility>

#include<algorithm>

#include<map>

using namespace std;

typedef long long ll;

const int Max = 10005;

const int mod = 1e9+7;

const int Hash = 10000;

int pre[Max];

int power[Max];//每个节点的强度

pair<int ,int> edge[20005];//记录输入的边

struct st

{

    char ope[10];

    int first, second;

} ask[50005]; //记录询问

int ans[50005];//答案

map<int, bool> IsDestroy;//将被毁掉的边映射为true

int Find(int x)

{

    int t = x;

    while(x != pre[x])

        x = pre[x];

    while(t != pre[t])//路径压缩

    {

        int temp = pre[t];

        pre[t] = x;

        t =temp;

    }

    return x;

}

void Union(int a, int b)

{

    int ra = Find(a);

    int rb = Find(b);

    if(power[ra]>power[rb])

        pre[rb] = ra;

    else if(power[rb]>power[ra])

        pre[ra] = rb;

    else if(ra < rb)

        pre[rb] = ra;

    else

        pre[ra] = rb;

}

void init( )

{

    for(int i=0; i<Max; i++)

        pre[i] = i;

}

int T,n,m;

int main( )

{

    //freopen("input.txt","r",stdin);

    bool flag = false;

    while(scanf("%d", &n)!=EOF)

    {

        init();

        for(int i=0; i<n; i++)

            scanf("%d", power+i);

        scanf("%d", &m);

        int a, b;

        for(int i=0; i<m; i++)

        {

            scanf("%d%d",&a, &b);

            if(a>b)

                swap(a, b);

            edge[i].first = a;

            edge[i].second = b;

        }

        scanf("%d", &T);

        IsDestroy.clear();

        for(int i=0; i<T; i++)

        {

            scanf("%s", ask[i].ope);

            if(ask[i].ope[0]=='q')

                scanf("%d", &ask[i].first);

            else

            {

                scanf("%d%d",&a, &b);

                if(a > b)

                    swap(a, b);

                ask[i].first = a;

                ask[i].second = b;

                IsDestroy[a*Hash+b] = true;//标记ab边被摧毁

            }

        }

        for(int i=0; i<m; i++)

            if(!IsDestroy[edge[i].first*Hash+edge[i].second])

                Union(edge[i].first, edge[i].second);

        int cnt = 0;

        for(int i=T-1; i>-1; i--)

        {

            a = ask[i].first;

            b = ask[i].second;

            int root = Find(a);

            if(ask[i].ope[0]=='q')

            {

                if(power[root] > power[a])

                    ans[cnt++] = root;

                else

                    ans[cnt++] = -1;

            }

            else

                Union(a, b);

        }

        if(flag)

            printf("\n");

        else

            flag = true;

        for(int i=cnt-1; i>-1; i--)

            printf("%d\n", ans[i]);

    }

    return 0;

}
*/