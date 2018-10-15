// summer182.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int a, b, c,d,e,count=0;
	cin >> a >> b >> c;
	while (a != c && b != c)
	{
		if (b < a)
		{
			d = b;
			b = a;
			a = d;
		}
		count++;
		while (b > a)
		{
			count
		}

	}
    return 0;
}

