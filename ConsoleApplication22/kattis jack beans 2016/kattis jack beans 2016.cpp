// kattis jack beans 2016.cpp: 定义控制台应用程序的入口点。
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
int B;
int req[20];
int T;
int pro[20][21]; 
int l[20];
int maximum =10000;
int status[20];
int temp = 0;
void dfs(int row) {
	
	if (row == T) maximum = temp < maximum ? temp : maximum;
	else {
		for (int i = 0; i < l[row]; i++)
		{
			int cur = pro[row][i];
			if (status[cur] || req[cur] == 0) { dfs(row + 1); continue; }
			status[cur] ++;
			temp += req[cur];
			cout << "row " << row << " i " << i <<" temp "<<temp<<" l[i] "<< l[i]<< endl;

			dfs(row + 1);
			temp -= req[cur];
			if (status[cur]>0)

			status[cur] --;

		}

	}


}
int main()
{
	
	memset(pro, 0, sizeof(pro));
	memset(req, 0, sizeof(req));
	memset(status, 0, sizeof(status));
	cin >> B;
	int sum = 0;

	for (int i = 1; i <= B; i++)
	{
		cin >> req[i];
		sum += req[i];
	}
	cin >> T;
	int next = 1, cur = 0;
	for (int i = 0; i < T; i++)
	{
		cin >> l[i];
		for (int j = 0; j < l[i];j++) {
			cin >> pro[i][j];
			
		}

	}
	
	dfs(0);
	if (maximum <=sum)
		cout << sum - maximum;
	else
		cout << sum;
    return 0;
}

