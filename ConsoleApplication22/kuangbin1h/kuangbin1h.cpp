// kuangbin1m.cpp: 定义控制台应用程序的入口点。
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

int volumn[2];
int vi[110][110];
int contents[2];
int totalstep = -1;
int A, B, C;
struct N {
	int step;
	int* contents;
	N(int s, int c[]) { step = s; contents = c; }
};
N* acts[110][110]; // here step is act
queue<N> states;
N pour(N node, int a, int b)
{
	N temp = node;
	int diff = min(temp.contents[a], volumn[b] - temp.contents[b]);
	//cout << diff << ' ';
	temp.contents[b] += diff;
	temp.contents[a] -= diff;;
	return temp;
}
N fill(N node, int a)
{
	N temp = node;
	temp.contents[a] = volumn[a];
	return temp;
}
	N drop(N node, int a)
	{
		N temp = node;
		temp.contents[a] = 0;
		return temp;
	}
void bfs()
{
	while (!states.empty())
	{
		N cur = states.front();
		states.pop();
		//cout << cur.contents[0] * 100 + cur.contents[1]<<"\n";
		vi[cur.contents[0]][cur.contents[1]] = 1;
		
		if (cur.contents[0]==C || cur.contents[1] == C) { totalstep = cur.step; break; }
		cur.step++;
				N temp = pour(cur, 0, 1);
				//cout << temp.contents[0] * 100 + temp.contents[1] << "\n";
				if (!vi[temp.contents[0]][temp.contents[1]])
				{
					*acts[temp.contents[0]][temp.contents[1]] = N(0, temp.contents);
					states.push(temp);
				}
				temp = pour(cur, 1, 0);
				//cout << temp.contents[0] * 100 + temp.contents[1] << "\n";
				if (!vi[temp.contents[0]][temp.contents[1]])
				{
					*acts[temp.contents[0]][temp.contents[1]] = N(1, temp.contents);
					states.push(temp);
				}
				temp = drop(cur, 0);
				if (!vi[temp.contents[0]][temp.contents[1]])
				{
					*acts[temp.contents[0]][temp.contents[1]] = N(2, temp.contents);
					states.push(temp);
				}
				temp = drop(cur, 1);
				if (!vi[temp.contents[0]][temp.contents[1]])
				{
					*acts[temp.contents[0]][temp.contents[1]] = N(3, temp.contents);
					states.push(temp);
				}
				temp = fill(cur, 0);
				if (!vi[temp.contents[0]][temp.contents[1]])
				{
					*acts[temp.contents[0]][temp.contents[1]] = N(4, temp.contents);
					states.push(temp);
				}
				temp = fill(cur, 1);
				if (!vi[temp.contents[0]][temp.contents[1]])
				{
					*acts[temp.contents[0]][temp.contents[1]] = N(5, temp.contents);
					states.push(temp);
				}
		
	}
	while (!states.empty()) { states.pop(); }

	
}
int main()
{

	cin >>volumn[0]>>volumn[1]>>C;
	contents[0] = 0;
	contents[1] = 0;
		totalstep = -1;
		memset(vi, 0, sizeof(vi));
		memset(acts,-1,sizeof(acts));
		N head=N(0,contents);
		states.push(head);
		bfs();
		if (totalstep != -1)
		{
			cout << totalstep  << "\n";
		
		
		
		
		
		}
		else
			cout << "impossible";
	
	return 0;
}

