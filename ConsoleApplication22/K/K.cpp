// K.cpp: 定义控制台应用程序的入口点。
//

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

int main()
{
	double k;
	double b, w, r, c;
	int k1 = 4, b1 = 40, w1 = 30, r1 = 10, c1 = 100;
	
	while (cin >> k, k != 0)
	{
		cin >> b >> w >> r >> c;
		
		int k1 = 4, b1 = b, w1 = w, r1 = r, c1 = c;
		
		double degree1=1, temp = 1;
		for (int i=0; i <= b1; i++)
		{
		for (int j=0; j <= b1-i; i++)
		{
		for (int k=0; k <= b1-i-j; k++)
		{
		temp = 1 * (double)w1 / (w1 + i)* (double)r1 / (r1 + j)* (double)r1 / (r1 + k)* (double)r1 / (r1 + b1 - i - j - k);
		if (temp < degree1)
		degree1 = temp;
		}
		}
		}
		cout << degree1 << "\n";
		double x=0, x0=0;
		if (b >= k * (c - r) - w + r)
		{
			x = c - r;
			x0 = c - w;
		}
		else if (w > r) {
			 x = (b + w - r) / k;
			 x0 = r + x - w;
			if (x + r > c) {
				x = c - r;
				x0 = b - x * (k - 1);
				if (x0 + w > c)
					x0 = c - w;
			}
			else if (x0 < 0)
			{
				x0 = 0;
				x = b / (k - 1);
			}
			
		}
		else {
			double dif = r - w;
			x0 = min(dif, b);
			cout << "x0is: " << x0<<"\n";
			b = b - min(dif, b);
			x = b / k;
			x0 += x;
			if (x + r > c) {
				x = c - r;
				x0 = c - w;
			}
			//w += min(dif, b);
		}
		double degree = 1;
		printf("%d %.2f",(int)k, x0);
		degree = degree * w / (w + x0);
		for (int i = 0; i < k - 1; i++)
		{
			degree = degree * r / (r + x);
			printf(" %.2f", x);
		}
		cout << degree;
	}
    return 0;
}

