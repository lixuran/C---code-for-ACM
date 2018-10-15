// summer5.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <iostream>
using namespace std;
long long   Merge(int a[], int s, int m, int e, int tmp[])
{//������a�ľֲ�a[s,m]��a[m+1,e]�ϲ���tmp,����֤tmp����Ȼ���ٿ�����a[s,m]
 //�鲢����ʱ�临�Ӷȣ�O��e-m+1),��O��n)
	long long  count = 0;
	int pb = 0;
	int p1 = s, p2 = m + 1;
	while (p1 <= m && p2 <= e) {
		if (a[p1] > a[p2])
		{
			tmp[pb++] = a[p1++];
			count+=e-p2+1;
		}
		else
		{
			tmp[pb++] = a[p2++];
			
		}
	}
	while (p1 <= m)
		tmp[pb++] = a[p1++];
	while (p2 <= e)
	{
		tmp[pb++] = a[p2++];
	}
	for (int i = 0;i < e - s + 1; ++i)
		a[s + i] = tmp[i];
	return count;
}
long long  MergeSort(int a[], int s, int e, int tmp[])
{
	long long sum=0;
	if (s < e) {
		int m = s + (e - s) / 2;
		sum+=MergeSort(a, s, m, tmp);
		sum+=MergeSort(a, m + 1, e, tmp);
		sum+=Merge(a, s, m, e, tmp);
	}
	return sum;
}
int a[100010];
int b[100010];
int main()
{
	
	int size;cin >> size;
	for (int i = 0;i < size;i++)
	{
		cin >> a[i];
	}
	cout<<MergeSort(a, 0, size - 1, b);
	cout << endl;
	return 0;
}
