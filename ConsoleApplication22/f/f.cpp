// f.cpp: 定义控制台应用程序的入口点。
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

int main()
{
	string a, b;
	int x, y,flag=0;
	cin >> a >> b;
	for (int i = 0; i < a.length(); i++) {
		for (int j = 0; j < b.length(); j++)
		{
			if (a[i] == b[j])
			{
				x = i; y = j;
				flag = 1;
				break;
			}
		}
		if (flag) break;
	
	}
	//cout << x << y << "\n";
	for (int i = 0; i < b.length(); i++) {
		for (int j = 0; j < a.length(); j++)
		{
			if (x == j)
				cout << b[i];
			else if (y == i)
				cout << a[j];
			else cout << '.';

		}
		cout << "\n";


	}
    return 0;
}

