// ConsoleApplication12.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include  <sstream>
#include <string.h>
#pragma warning( disable : 4996)
using namespace std;
struct Bigint {
	static const int base = 100000000;
	static const int width = 8;
	vector <int > s;
	Bigint(long long num = 0) { *this = num; }
	Bigint operator = (long long num)
		
	{
		s.clear();
		do {
			s.push_back(num%base);
			num /= base;

		
		} while (num > 0);
			return *this;
	}
	Bigint operator + (const Bigint& b)const
	{
		Bigint c;
		c.s.clear();
		for (int i = 0, g = 0;;i++)
		{
			if (g == 0 && i >= s.size() && i >= b.s.size())break;
			int x = g;
			if (i < s.size())x += s[i];
			if (i < b.s.size())x += b.s[i];
			c.s.push_back(x%base);g = x / base;
		}
		return c;
	}
	/*
	Bigint operator = (const string & str) {
		s.clear();
		int x, len = (str.length() - 1) / width + 1;
		for (int i = 0; i < len;i++)
		{
			int end = (str.length() - 1) / width + 1;
			int start = max(0, end - width);
			sscanf(str.substr(start, end - start).c_str(), "%d", &x);
			s.push_back(x);
		}
		return *this;
	}
	*/
};
map<string, int> a;
void str(Bigint x,int j)
{
	string b=*new string();string s;
	for (int i = x.s.size()-1;x.s.size()-i<5 && i>=0;i--)
	{
		//printf("s[i] %d\n", x.s[i]);
		stringstream ss(x.s[i]);
		ss >> s;
		//printf("s %d\n", s.length());
		b.append(to_string( x.s[i]));
		
	}
	//printf("b %d\n", b.length());
	for (int i = 1;i < b.length();i++)
	{
		//cout<< "1 "<<b.substr(0, i)<<endl;
		//cout<<"2 "<< a.count(b.substr(0, i))<<endl;
		if (a.count(b.substr(0, i)) == 0)
			a[b.substr(0, i)] = j;
	}

}

int main()
{
	int n,count=1;
	Bigint x[10000],b;
	
	string c[40];
	x[0] = 1;
	x[1] = 1;
	a["1"] = 0;
	cin >> n;
	for (int i = 2;i <= 10000-1;i++)
	
	{

		x[i] = x[i - 1] + x[i - 2];
		//printf("3 %d\n", x[i].s[0]);
		str(x[i],i);
		
	}
	while (n--)
	{
		string i;
		cout << "input now" << endl;
		cin >> i;
		if (a.count(i) == 0)
			printf("-1\n");
		else
			printf("Case #%d: %d\n",count,a[i]);

	}
	//cout << x[n];
    return 0;
}

