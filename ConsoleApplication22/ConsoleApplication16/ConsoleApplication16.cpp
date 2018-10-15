// ConsoleApplication16.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <algorithm>
#pragma warning( disable : 4996)
const int maxn = 100005;
int a[maxn];
int comp(const void*a, const void *b)

{
	return *(int *)a - *(int*)b;
}

int main()
{
	int n, c,l=0,r=1000000000,cur=0,next=0,mid=500000000;
	
	scanf("%d%d", &n, &c);
	for (int i = 0;i < n;i++)
	{
		scanf("%d", &a[i]);
	}
	qsort(a,n,sizeof(int),comp);
	//for (int i = 0;i < n;i++)
	//	printf("%d ", a[i]);
	while (mid>0 && r>l)
	{
		int i;
		cur = next = 0;
		//printf("1 %d ", r);
		for (i = 1;i < c;i++)
		{
			//printf("11 %d ",r);
			while (a[next]-a[cur]<mid && next<n)
			{
				//printf("3 %d %d\n", a[next] - a[cur], next);
				next++;
			}
			if (next >= n)
			{
				r = mid-1;
				
				
				mid = l + (r - l) / 2;
				if ((r - l) ==1)mid++;
				//printf("1 %d %d %d\n", mid,l,r);
				break;
			}
			cur = next;
		}
		if (i == c)
		{
			
			l = mid;
			mid = mid + (r - mid) / 2;
			if ((r - l) == 1)mid++;
			//printf("2 %d %d %d\n", mid, l, r);
		}
	}
	printf("%d", mid);
    return 0;
}

