// ConsoleApplication7.cpp : 定义控制台应用程序的入口点。
//uva 1593

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include  <vector>
using namespace std;
vector <string > vs[1010];
int len[1010] = {0};
void print(string a,int max)
{
	//cout << a; why cant we do this?
	for (int i = 0;i < a.size();i++)
	{
		cout << a[i];
	}
	for (int i = 0; i < max - a.size() + 2;i++)
	{
		cout << ' ';
	}

}
int main()
{
	int count=0,col;
	string a;
	while (getline(cin,a))
	{
		col = 0;
		string c;
		stringstream b(a);
		while (b >> c)
		{
			int d = c.length();
			if (len[col] < d)
			{
				len[col] = d;
			}
			col++;
			vs[count].push_back(c);
		}
		count++;
	}
	for (int i = 0;i < count;i++)
	{
		int j = 0;
		for (; j<vs[i].size() - 1; j++)
			print(vs[i][j],len[j]);
		cout << vs[i][j] << endl;
	}
    return 0;
}

