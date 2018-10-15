// ConsoleApplication15.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <string>
#include <queue>
using namespace std;
#pragma warning( disable : 4996)
const char * dirs = "NESW";
const char * turns = "FLR";
int dir_id(char c) { return strchr(dirs, c) - dirs; }
int turn_id(char c) { return strchr(turns, c) - turns; }
int has[10][10][4][3];
const int dr[] = { -1,0,1,0 };
const int dc[] = { 0,1,0,-1 };
int r1, c1;
struct Node
{
	int r, c, dir;
	Node(int x, int y, int z) :r(x), c(y), dir(z) {}

};
Node walk(const Node& u, int turn)
{
	int dir = u.dir;
	if (turn == 1)dir = (dir + 3) % 4;
	if (turn == 2)dir = (dir + 1) % 4;
	return Node(u.r + dr[dir], u.c + dc[dir], dir);
}


void print_ans()
{

}
void solve()
{


}



int main()
{
	int sr, sc, gr, gc, r, c;
	char a[30];
	string s,s1;
	while (cin >> a, !strcmp(a, "END"))
	{
		cout << a << endl;
		memset(has, 0, sizeof(has));
	char sp;//startposition
	cin >> sr >> sc >> sp>>gr >> gc;
	Node n=Node(sr,sc,sp);
	r1 = walk(n,0).r;
	c1= walk(n, 0).c;
	while (getline(cin, s), s[0] != '0')
	{
		stringstream ss(s);
		ss >> r >> c;
		while (ss >> s1, s1[0] != '*')
		{
			for (int i = 1;s1[i] != '\0';i++)
			{
				has[r][c][s1[0]][s1[i]] = 1;
			}
		}
	}
	solve();
	print_ans();
	}
    return 0;
}

