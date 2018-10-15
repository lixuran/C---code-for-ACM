#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;
int N, M;
int minArea = 1 << 30; //最优表面积
int area = 0; //正在搭建中的蛋糕的表面积
int minV[30]; // minV[n]表示n层蛋糕最少的体积
int minA[30]; // minA[n]表示n层蛋糕的最少侧表面积
void Dfs(int v, int n, int r, int h);
int MaxVforNRH(int n, int r, int h);
int main()
{
	
	minV[0] = 0;
	minA[0] = 0;
	for (int i = 1; i <= 25; ++i) {
		minV[i] = minV[i - 1] + i * i * i; //第i层半径至少i,高度至少i
		minA[i] = minA[i - 1] + 2 * i * i;
	}
	while (cin >> N >> M)
	{//M层蛋糕，体积N
		if (minV[M] > N)
			cout << 0 << endl;

		else {
			int maxH = (N - minV[M - 1]) / (M*M) + 1;//底层最大高度
													 //最底层体积不超过 (N-minV[M-1]),且半径至少M
			int maxR = sqrt(double(N - minV[M - 1]) / M) + 1;//底层高度至少M
			area = 0;
			minArea = 1 << 30;
			//cout << maxH << ' ' << maxR << endl;
			Dfs(N, M, maxR, maxH);
			if (minArea == 1 << 30)
				cout << 0 << endl;
			else
				cout << minArea << endl;
		}
	}
}

void Dfs(int v, int n, int r, int h)
//要用n层去凑体积v,最底层半径不能超过r,高度不能超过h
//求出最小表面积放入 minArea
{
	if (n == 0) {
		if (v) return;
		else {
			if (area<minArea)
			{
				minArea =  area;
				//cout << minArea << ' ';
				return;
			}
		}
	}
	if (v <= 0)
		return;
	if (minV[n] > v) //剪枝3
		return;
	if (area + minA[n] >= minArea) //剪枝1
		return;
	if (h < n || r < n) //剪枝2
		return;
	if (MaxVforNRH(n, r, h) < v) //剪枝4
								 //这个剪枝最强！没有的话，5秒都超时，有的话，10ms过！
		return;
	//for( int rr = n; rr <= r; ++ rr ) { 这种写法比从大到小慢5倍
	for (int rr = r; rr >= n; --rr) {
		if (n == M) //底面积
			area = rr * rr;
		for (int hh = h; hh >= n; --hh) {
			area += 2 * rr * hh;
			Dfs(v - rr*rr*hh, n - 1, rr - 1, hh - 1);
			area -= 2 * rr * hh;
		}
	}
}
int MaxVforNRH(int n, int r, int h)
{ //求在n层蛋糕，底层最大半径r，最高高度h的情况下，能凑出来的最大体积
	int v = 0;
	for (int i = 0; i < n; ++i)
		v += (r - i) *(r - i) * (h - i);
	return v;
}