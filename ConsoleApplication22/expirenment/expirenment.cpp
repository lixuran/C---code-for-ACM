// expirenment.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstring> 
#include <string> 
#include <algorithm>
using namespace std;
int main()
{
	char a[5];
	string b;
	cin >> a >> b;

	cout << strlen(a) << endl<< b.length()<<b.size()<<endl;
    return 0;
}

