// kuangbin7c.cpp: 定义控制台应用程序的入口点。
//poj -3468
#define _CRT_SBCURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

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
#define input freopen("input.txt","r",stdin)
#define output freopen("output.txt","w",stdout)
#define For1(i,a,b) for (i=a;i<b;i++)
#define For2(i,a,b) for (i=a;i<=b;i++)
#define Dec(i,a,b) for (i=a;i>b;i--)
#define Dec2(i,a,b) for (i=a;i>=b;i--)
#define Fill(x,a) memset(x,a,sizeof(x))
#define inf 1<<30
#define size 100010

struct mynode {
	int a;
	int geta() const { return a; }
	mynode(int aa) :a(aa) {};
	//const bool operator < (const mynode &node) const
	//{}

};

bool operator <(const mynode & a, const mynode &b) {
	return a.a < b.a;
}

int main()

{
	set<mynode> intset; 
	intset.clear();
	int b = 10;
	std::set<mynode>::iterator it;
	while (b--)
	{
		intset.insert(mynode(b));

	}
	for (it = intset.begin(); it != intset.end(); it++)
	{
		
		cout << it->geta();
	}

	return 0;

}
