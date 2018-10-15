	// ConsoleApplication19.cpp : 定义控制台应用程序的入口点。
	//

	#include "stdafx.h"
	#include <algorithm>
	#include <iostream>
	using namespace std;
	int a[100010];
	int n, m;
	int main()
	{
		int i,sum=0,min=0,max=10000,mid,j;
		cin>>n>>m;
		//memset(b, 0, sizeof(b));
		for ( i = 1;i <= n;i++)
		{
			cin >> a[i];
		}
		while (min <= max)
		{
			if (min == max && min == mid)
			{
				break;
			}
			mid = min + (max - min) / 2;
			//cout <<min<<' '<< mid<<' '<<max << endl;
			sum = 0;j = m;
			for ( i = 1;i <= n;i++)
			{
			
				if (sum + a[i] > mid)
				{
					j--;
					sum = a[i];
					//cout << j<<" sum " << sum << endl;
					if (sum > mid)
					{

						min = mid + 1;
						break;
					}
				}
				else
				{
					sum += a[i];
				

				}
				if (j == 0 )
				{
					min = mid + 1;
					break;
				}
			}
			if (i == n+1)
			{
				max = mid ;
			}
		}

		cout<<mid;
		return 0;
	}

