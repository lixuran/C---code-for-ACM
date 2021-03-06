	// kuangbin1g.cpp: 定义控制台应用程序的入口点。
//POJ - 3087

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
#pragma warning( disable : 4996)

string a,b,c;
string target;
int len;
set<string> s;
struct N {
	string str;
	int step;
	N(string str, int step) { this->step = step; this->str = str; }
};

queue<N> que;

string getstr(string a, string b) {
	string cnt = "";
	for (int i = 0; i < len; i++) {
		cnt.push_back(a[i]);
		cnt.push_back(b[i]);
	}
	
	return cnt;
}


int bfs() {
	int ans = -1;
	while (!que.empty()) {
		N cnt = que.front();
		que.pop();
		string cntstr = cnt.str;
		s.insert(cntstr);
		if (cntstr == target) { ans = cnt.step; break; }
		string a = cntstr.substr(0, len);
		string b = cntstr.substr(len, 2 * len);
		//string newa = getstr(a, b);
		//if (!s.count(newa)){
		//  s.insert(newa);
		//  que.push({ newa, cnt.step + 1 });
		//}
		string newb = getstr(b, a);
		if (!s.count(newb)) {
			s.insert(newb);
			que.push( N( newb, cnt.step + 1 ));
		}
	}
	while (!que.empty()) { que.pop(); }
	return ans;
}

int main() {
	int t;
	string a, b;
	scanf("%d", &t);
	for (int k = 1; k <= t; k++) {
		s.clear();
		scanf("%d", &len);
		cin >> a >> b >> target;
		N start = N(a + b, 0 );
		que.push(start);
		int ans = bfs();
		printf("%d %d\n", k, ans);
	}
	return 0;
}

