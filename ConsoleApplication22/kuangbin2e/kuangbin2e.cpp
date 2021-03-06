// kuangbin2e.cpp: 定义控制台应用程序的入口点。
//HDU 1560
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
char words[10][6];
int sizes[10];
int total=0;
int cnt = 100;
int n;
struct N
{
	int cnt;
	int match;
	int h;
	int index[10] ;
	bool operator < (const N &a) const {
		return h>a.h;
	}

};
priority_queue<N> seq;
char alpha[4] = { 'A','C','G','T' };
void astar()
{
	N head;
	head.cnt = 0;
	head.match = 0;
	head.h = (total - head.match) + head.cnt;//this is not a good way to go
	for (int i = 0; i < 10; i++)head.index[i] = 0;
	while (!seq.empty())seq.pop();
	seq.push(head);
	while (!seq.empty())
	{
		N cur = seq.top();
		seq.pop();
		//cout << cur.match << '\n';
		if (cur.match == total)
		{
			cnt = cur.cnt;
			return;
		}
		

		for (int i = 0; i < 4; i++)
		{
			N temp = cur;
			temp.cnt = cur.cnt + 1;
			int change = 0;
			for (int j = 0; j < n; j++)
			{
				if (words[j][temp.index[j]] == alpha[i])
				{
					
					temp.index[j]++;
					temp.match++;
					change = 1;
					//cout << temp.match << ' ';
					
				}
			}
			if (change == 1)
			{
				temp.h = (total - temp.match) / 6 + temp.cnt;
				seq.push(temp);
			}
		}

	}

}
int main()
{
	int t;
	cin >> t;
	
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		memset(sizes,0,sizeof(sizes));
		memset(words, ' ', sizeof(words));
		for (int j = 0; j < n; j++)
		{
			cin >> words[j];
			sizes[j] = strlen(words[j]);
			total += sizes[j];
			//cout << sizes[j];
		}

		astar();
		cout << cnt << "\n";
	}
    return 0;
}

