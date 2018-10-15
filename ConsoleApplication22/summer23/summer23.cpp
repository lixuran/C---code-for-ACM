#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;
int N, M;
int minArea = 1 << 30; //���ű����
int area = 0; //���ڴ�еĵ���ı����
int minV[30]; // minV[n]��ʾn�㵰�����ٵ����
int minA[30]; // minA[n]��ʾn�㵰������ٲ�����
void Dfs(int v, int n, int r, int h);
int MaxVforNRH(int n, int r, int h);
int main()
{
	
	minV[0] = 0;
	minA[0] = 0;
	for (int i = 1; i <= 25; ++i) {
		minV[i] = minV[i - 1] + i * i * i; //��i��뾶����i,�߶�����i
		minA[i] = minA[i - 1] + 2 * i * i;
	}
	while (cin >> N >> M)
	{//M�㵰�⣬���N
		if (minV[M] > N)
			cout << 0 << endl;

		else {
			int maxH = (N - minV[M - 1]) / (M*M) + 1;//�ײ����߶�
													 //��ײ���������� (N-minV[M-1]),�Ұ뾶����M
			int maxR = sqrt(double(N - minV[M - 1]) / M) + 1;//�ײ�߶�����M
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
//Ҫ��n��ȥ�����v,��ײ�뾶���ܳ���r,�߶Ȳ��ܳ���h
//�����С��������� minArea
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
	if (minV[n] > v) //��֦3
		return;
	if (area + minA[n] >= minArea) //��֦1
		return;
	if (h < n || r < n) //��֦2
		return;
	if (MaxVforNRH(n, r, h) < v) //��֦4
								 //�����֦��ǿ��û�еĻ���5�붼��ʱ���еĻ���10ms����
		return;
	//for( int rr = n; rr <= r; ++ rr ) { ����д���ȴӴ�С��5��
	for (int rr = r; rr >= n; --rr) {
		if (n == M) //�����
			area = rr * rr;
		for (int hh = h; hh >= n; --hh) {
			area += 2 * rr * hh;
			Dfs(v - rr*rr*hh, n - 1, rr - 1, hh - 1);
			area -= 2 * rr * hh;
		}
	}
}
int MaxVforNRH(int n, int r, int h)
{ //����n�㵰�⣬�ײ����뾶r����߸߶�h������£��ܴճ�����������
	int v = 0;
	for (int i = 0; i < n; ++i)
		v += (r - i) *(r - i) * (h - i);
	return v;
}