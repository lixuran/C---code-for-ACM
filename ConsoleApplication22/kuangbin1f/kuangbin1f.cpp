// kuangbin1f.cpp: 定义控制台应用程序的入口点。
//POJ - 3126  

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
int first, last;
int sum;
int isprim[10000];
int vi[10000];
struct N{

	int nums[4];
	int step;
	N(int prime, int step) {
		nums[0] = prime / 1000;
		nums[1] = prime / 100%10;
		nums[2] = prime / 10 %10;
		nums[3] = prime % 10;
		this->step = step;
	}
};
int getnum(int *n) {
	return n[0] * 1000 + n[1] * 100 + n[2] * 10 + n[3];
}

void search()
{
	queue<N> primes;
	primes.push(N(first, 0));
	while (!primes.empty())
	{
		N prime= primes.front();
		primes.pop();
		vi[getnum(prime.nums)] = 1;
		if (getnum(prime.nums) == last)
		{
			sum = prime.step;
			break;
		}
		prime.step++;
		for (int k = 0; k < 4; k++) {
			int cc = prime.nums[k];
			for (int i = 0; i < 10; i++) {
				prime.nums[k] = i;
				int newnum = getnum(prime.nums);
				if (vi[newnum] == 0 && isprim[newnum]) {
					primes.push(prime);
				}
			}
			prime.nums[k] = cc;
		}

	}

}
void is_prim() {
	for (int i = 1000; i <= 9999; i++) {
		bool r = true;
		for (int j = 2; j < sqrt((double)i) + 1; j++) {
			if (i%j == 0) { r = false; break; }
		}
		if (r == true) { isprim[i] = true; }
	}
}

int main()
{
	int m;
	cin >> m;
	is_prim();
	while (m--)
	{
		sum = 0;
		memset(vi, 0, sizeof(vi));
		cin >> first >> last;
		search();
		cout << sum << "\n";
	}
    return 0;
}

