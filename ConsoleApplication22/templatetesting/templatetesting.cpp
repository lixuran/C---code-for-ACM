// templatetesting.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#pragma warning( disable : 4996)

//#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;

//打印1~n的所有子集
//按照递增顺序就行构造子集 防止子集的重复 
void print_subset(int *A, int n, int cur) {
	for (int i = 0; i < cur; i++)printf("%d ", A[i]); printf("\n");
	int s = cur ? A[cur - 1] + 1 : 1;   ////确定当前元素的最小可能值
	for (int i = s; i <= n; i++) {
		A[cur] = i;
		print_subset(A, n, cur + 1);
	}
}
int main() {
	int n, a[maxn];
	scanf("%d", &n);
	print_subset(a, n, 0);
	return 0;
}
