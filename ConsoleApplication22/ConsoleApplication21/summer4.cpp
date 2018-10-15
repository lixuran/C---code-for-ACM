// ConsoleApplication21.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int a[100010];
priority_queue<int> pq;
int main()
{
	int n,i=0,j,k,l=0,r;
	cin >> n;

	while (i != n)
	{
		cin >> a[i++];
		pq.push(a[i-1]);
		/*
		j = i / 2;r = i;
		while (l<r)
		{
			if (a[j] < a[i])
			{
				r = j;
				j = (l + r) / 2;
			}
			else ()
			*/
		
	}
	cin >> k;i = 0;
	while (k--)
	{
		cout << pq.top() << endl;
		pq.pop();
	}
    return 0;
}

