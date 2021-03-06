// B.cpp: 定义控制台应用程序的入口点。
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
int a[1010];
priority_queue<pair<int, int>> from;
vector<string> outs;
priority_queue<pair<int, int>> to;
int main()
{
	pair<int, int>min1=make_pair(100,0), min2 = make_pair(100, 0);
	int n,count=0;
	while (!from.empty())from.pop();
	while (!to.empty())to.pop();
	cin >> n;
	for (int i = 0;i< n;i++)
	{
		cin >> a[i];
		if (a[i] < min1.first)
		{
			min2 = min1;
			min1 = make_pair(a[i], i);
			
		}
		else if(a[i]<min2.first){
			min2 = make_pair(a[i], i);
		}
		from.push(make_pair(a[i], i));
	}
	if (n == 1) {
		cout << a[0] << "\n" << 1;
		return 0;
	}
	if (n == 2)
	{
		cout << max(a[0],a[1]) << "\n" << "1 2";
		return 0;
	}
	while (!from.empty())
	{
		if (from.size() <= 2)
		{
			count += from.top().first;
			break;
		}
		outs.push_back(min1.second + " " + min2.second);
		count += min2.first + min1.first;
		outs.push_back(min1.second+"");
		pair<int, int> fi = from.top();
		from.pop();
		pair<int, int> se= from.top();
		from.pop();
		count += fi.first;
		outs.push_back(fi.second + " " + se.second);
		count += min2.first;
		outs.push_back(min2.second + "" );

	}
	cout << count << "\n";
	for (int i = 0; i < outs.size(); i++)
	{
		cout << outs[i] << "\n";
	}
    return 0;
}

