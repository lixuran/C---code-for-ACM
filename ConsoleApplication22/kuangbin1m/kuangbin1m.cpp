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
int contents[3];
int volumn[3];
int vi[10100];
int totalstep=-1;
int from[6] = {0,0,1,1,2,2};
int to[6] = { 1,2,0,2,0,1 };

struct N {
	int step;
	int contents[3];


};
queue<N> states;
N pour(N node,int a, int b)
{
	N temp = node;
	int diff = min(temp.contents[a], volumn[b] - temp.contents[b]);
	//cout << diff << ' ';
	temp.contents[b] += diff;
	temp.contents[a] -= diff;;
	return temp;
}
bool checkequal(N cur)
{
	int counts = 0;
	int half = volumn[0] / 2;
	for (int i = 0; i < 3; i++)
	{
		if (cur.contents[i] == half)counts++;
	}
	if (counts == 2)return true;
	return false;
}
void bfs()
{
	while (!states.empty())
	{
		N cur = states.front();
		states.pop();
		//cout << cur.contents[0] * 100 + cur.contents[1]<<"\n";
		vi[cur.contents[0] * 100 + cur.contents[1]] = 1;
		cur.step++;
		if (checkequal(cur)) { totalstep = cur.step; break; }
		for (int i = 0; i < 6; i++)
		{
			if (cur.contents[from[i]])
			{
				N temp = pour(cur, from[i], to[i]);
				//cout << temp.contents[0] * 100 + temp.contents[1] << "\n";

				if (!vi[temp.contents[0] * 100 + temp.contents[1]])
					states.push(temp);
			}
		}
	}
	while (!states.empty()) { states.pop(); }


}
int main()
{

	while (cin >> volumn[0] >> volumn[1] >> volumn[2], volumn[0] != 0 || volumn[1] != 0 || volumn[2] != 0)
	{
		totalstep = -1;
		memset(contents, 0, sizeof(contents));
		contents[0] = volumn[0];
		memset(vi, 0, sizeof(vi));
		if (volumn[0] & 1) { cout << "NO\n"; continue; }
		N head;
		head.contents[0] = volumn[0];
		head.contents[1] = 0;
		head.contents[2] = 0;
		head.step = 0;
		states.push(head);
		bfs();
		if(totalstep!=-1)
		cout<<totalstep-1<<"\n";
		else
			cout<< "NO\n";
	}
    return 0;
}

