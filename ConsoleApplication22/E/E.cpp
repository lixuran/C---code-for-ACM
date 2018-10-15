// E.cpp: 定义控制台应用程序的入口点。
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
#define INF 0x3f3f
vector<pair<int, int>> graph[1010];
int dis[1010];
priority_queue<pair<int, int>> marks;
struct node {
	int num;
	int x;
	int y;
	int z;
	node(int numm) : num(numm%1000) { x = numm / 100;
	y = numm / 10 % 10; z = numm % 10;
	};
	node() {};
}ram[1010],reg[11];
int main()
{
	int ins,index=0,ans=0;
	for (int i = 0; i < 10; i++) reg[i] = node(0);
	for (int j = 0; j < 1000; j++) ram[j] = node(0);
	while (cin >> ins) {
		ram[index++] = node(ins);
	}
	int cur = 0,flag=0;
	while (ram[cur].x != 1) {
		//cout <<cur<<"is: "<< ram[cur].num << "\n";
		ans++;
		switch (ram[cur].x) {
		case 2:
			//cout << ram[cur].z << "aaaa";
			reg[ram[cur].y] = node(ram[cur].z);
			//cout << reg[ram[cur].y].num << "\n";
			break;
		case 3:
			reg[ram[cur].y] = node(reg[ram[cur].y].num+ ram[cur].z);
			break;

		case 4:
			reg[ram[cur].y] = node(reg[ram[cur].y].num*ram[cur].z);
			break;


		case 5:
			reg[ram[cur].y] = node(reg[ram[cur].z].num);
			break;

		case 6:
			reg[ram[cur].y] = node(reg[ram[cur].y].num + reg[ram[cur].z].num);
			break;

		case 7:
			reg[ram[cur].y] = node(reg[ram[cur].y].num * reg[ram[cur].z].num);
			break;

		case 8:
			reg[ram[cur].y] = node(ram[ reg[ram[cur].z].num].num);
			break;


		case 9:
			ram[reg[ram[cur].z].num] = node(reg[ram[cur].y].num);
			break;

		case 0:
			if (reg[ram[cur].z].num != 0)
			{
				cur = reg[ram[cur].y].num;
				flag = 1;
			}
			break;

		}
		//cout << reg[ram[cur].y].num<<"\n";
		if(!flag)
		cur++;
		else flag = 0;

	}
	cout << ans + 1;
    return 0;
}

