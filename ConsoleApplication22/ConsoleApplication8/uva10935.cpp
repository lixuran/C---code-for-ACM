// ConsoleApplication8.cpp : 定义控制台应用程序的入口点。
//uva 10935

#include "stdafx.h"
#include <queue>
#include <iostream>

using namespace std;
int main()
{
	int n,j,x=0;
	while (cin >> n)
	{
		if (n == 0)
			break;
		queue<int> card;
		for (int i = 1; i <= n;i++)
		{
			card.push(i);
		}
		if (x)
		{
			x = 1;
			cout << endl;
		}
		cout << "Discarded cards :";
		while (card.size() != 1)
		{
			int y=card.front();
			card.pop();
			cout << " " << y;

			j = card.front();
			card.pop();
			card.push(j);
		}
		cout <<endl<< "Remaining card: " << card.front();
	}
    return 0;
}

