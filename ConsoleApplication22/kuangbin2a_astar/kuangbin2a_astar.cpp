// kuangbin2a_astar.cpp: 定义控制台应用程序的入口点。
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
#pragma warning( disable : 4996)

struct node     //状态
{
    int a[10];
    int f, h, g;
    int x;      //x在的位置

//    bool operator<(const node n1)const{     //优先队列第一关键字为h,第二关键字为g
//        return h!=n1.h?h>n1.h:g>n1.g;
//   }

    friend bool operator < (node a, node b)
    {
		return a.f > b.f;
    }
};
priority_queue<node> que;
int fac[10];
//46233

struct

{

    int father;

    char dir;

}vis[362881];

 

int get_h(int a[])

{

    int h = 0;

    for(int i = 0; i < 8; i++)

    {

        if(a[i])

            h += fabs((a[i]-1)/3 - i/3) + fabs((a[i]-1)%3 - i%3);

    }

    return h;

}

 

int Hash(int a[])

{

    int ans = 0;

    for(int i = 0; i < 9; i++)

    {

        int tmp = 0;

        for(int j = i+1; j < 9; j++)

        {

            if(a[i] > a[j]) tmp++;

        }

        ans += tmp*fac[8-i];

    }

    return ans+1;

}

 

void prin(int n)

{

//    printf("n=%d\n", n);

    if(vis[n].father!=-1)

    {

        prin(vis[n].father);

        printf("%c", vis[n].dir);

    }

}

 

void SWAP(int &x, int &y)

{

    int t = x;

    x = y;

    y = t;

}

 

int dir[4][2] = { {1, 0}, {-1, 0}, {0, -1}, {0, 1} };

char dd[] = "dulr";

 

bool is(int a[])

{

    int ans = 0;

    for(int i = 0; i < 9; i++)

    {

        if(a[i])

        for(int j = i+1; j < 9; j++)

        {

            if(a[i] > a[j] && a[j])

                ans++;

        }

    }

    return !(ans&1);

}

 

void debug(int a[])

{

    for(int i = 0; i < 3; i++)

    {

        for(int j = 0; j < 3; j++)

        {

            printf("%d ", a[i*3+j]);

        }

        printf("\n");

    }

    printf("\n");

}

 

int bfs(node star)

{

    while(!que.empty()) que.pop();

    que.push( star );

    star.h = get_h( star.a );    star.g = 0;

    star.f = star.g + star.h;

    vis[ Hash( star.a ) ].father = -1;

    while(!que.empty())

    {

        node tmp = que.top();

        que.pop();

        int father = Hash(tmp.a);

 

//        printf("father=%d\n", father); debug(tmp.a);

 

        for(int i = 0; i < 4; i++)

        {

            int x = dir[i][0] + tmp.x/3;

            int y = dir[i][1] + tmp.x%3;

            if(0 <= x && x < 3 && 0 <= y && y < 3)

            {

                node s = tmp;

                s.x = x*3+y;

                SWAP( s.a[ tmp.x ], s.a[ s.x ] );

                s.g++;

                s.h = get_h( s.a );

                s.f = s.h + s.g;

                int son = Hash(s.a);

//                printf("tmp.x =%d s.x=%d\n", tmp.x, s.x);

//                printf("son=%d\n", son); debug(s.a);

                if(son == 46234)

                {

                    vis[ son ].father = father;

                    vis[ son ].dir = dd[i];

                    prin(46234);printf("\n");

                    return 0;

                }

                if(!vis[ son ].father && is(s.a))

                {

                    vis[ son ].father = father;

                    vis[ son ].dir = dd[i];

                    que.push( s );

                }

            }

        }

    }

    return 1;

}

 

 

int main(void)

{

    int i;

    fac[1] = 1;

    for(i = 2; i < 10; i++) fac[i] = fac[i-1]*i;

    node star;

    char in[2];

//    freopen("ou.txt", "w", stdout);

    while(~scanf("%s", in))

    {

        memset(vis, 0, sizeof(vis));

        if(in[0] == 'x')

        {

            star.a[0] = 0;

            star.x = 0;

        }

        else star.a[0] = in[0] - '0';

        for(i = 1; i < 9; i++)

        {

            scanf("%s", in);

            if(in[0] == 'x')

            {

                star.a[i] = 0;

                star.x = i;

            }

            else star.a[i] = in[0] - '0';

        }

        if(!is(star.a))

        {

            printf("unsolvable\n");continue;

        }

        if(Hash(star.a) == 46234) {printf("\n"); continue;}

        if(bfs(star))

        {

            printf("unsolvable\n");

        }

    }

    return 0;

}