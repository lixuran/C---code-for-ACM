// kaungbin1c.cpp: 定义控制台应用程序的入口点。
//

// day11.cpp: 定义控制台应用程序的入口点。
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
typedef pair<int, int> pa;
int visited[100010] = {0};
int n, k,num=0;
queue<pa> po;
int main()
{

	cin >> n >> k;
	po.push(make_pair(n, 0));
	while (!po.empty())
	{
		pa fi = po.front();
		po.pop();
		if (fi.first == k)
		{
		
			cout << fi.second;
			break;
		}
		//check for index here!s
		if (fi.first * 2 <= 100000 && !visited[2 * fi.first])
		{
			visited[2 * fi.first] = 1;
			po.push(make_pair(2 * fi.first, fi.second + 1));
		}
		if ( fi.first<100000 && !visited[fi.first + 1])
		{
			visited[ fi.first+1] = 1;
			po.push(make_pair(fi.first + 1, fi.second + 1));
		}
		if ( fi.first>0 && !visited[fi.first - 1])
		{
			visited[ fi.first-1] = 1;
			po.push(make_pair(fi.first - 1, fi.second + 1));
		
		}
		}
    return 0;
}

