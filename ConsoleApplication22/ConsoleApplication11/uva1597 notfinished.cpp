// ConsoleApplication11.cpp : 定义控制台应用程序的入口点。
//uva1597

#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
struct DID
{
	 int textnum;
	int linenum;
	DID(int a1=0, int a2=0)
	{
		this->textnum=a1;
		this->linenum = a2;
	}
};
int n;
string text[100][50][30];
string text2[100][50][30];
map<string, vector<DID>> link;
int tr = 1;


void sprint(vector <DID> y )
{
	
	for (int i = 0;i < y.size();i++)
	{
		DID x;
		x = y[i];
		printf("%s\n", text2[x.textnum][x.linenum]);
		if (tr)
		{
			tr = 0;
			continue;
		}
		printf("---------\n");
	}
	printf("==========\n");



}


vector<DID> reb(string a)
{
	vector<DID> b =  * new vector<DID>[10];
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < 50;j++)
		{
			for (int k = 0;k < 30;k++)
				if (a.compare(text[i][j][k]) == 0)
				{	
					b.push_back( DID(i, j));
				}
		}
	}
	return b;
}

int main()
{
	cin >> n;
	link.clear();
	memset(text, 0, sizeof(text));
	for (int i = 0; i < n;i++)
	{
		int count = 0,word=0;
		string temp,temp2,buf;
		while (1)
		{
			//cin>>temp
			getline(cin,temp);
			//string temp;getline(cin, temp);
			if (temp[0]== '*')
			{
				break;
			}
			for (int j=0;j < temp.length();j++)
			{
				temp2[j] = isalpha(temp[j]) ? tolower(temp[j]) : ' ';
			}
			stringstream ss(temp);
			stringstream ss2(temp2);
			while (ss >> buf)
			{
			//text[i][count][word++]=*new string(buf);
				//memcpy(text[i][count][word++], buf, sizeof(text[i][count][word++]));
				text[i][count][word++].assign(buf);
			}
			word = 0;
			while (ss2 >> buf)
			{
				text[i][count][word++].assign(buf);
			}
			count++;
		}
	}
	int q;
	cin >> q;
	for (int i = 0;i < q;i++)
	{
		string q0,q1,q2[2],q3="";
		int count =0;
		getline(cin, q0);
		//query.push_back(q0);
		stringstream ss(q0);
		while (ss >> q1)
		{
			if (islower(q1[0]))
			{
				q2[count++] = *new string(q1);
				if(link.count(q1)==0)
				link[q1]= reb(q1);
			}

			else
				q3 = *new string(q1);
			
		}
		vector<DID> y = link[q2[0]];vector<DID> y1 = link[q2[1]];int tr = 1;	vector<DID> tar=*new vector<DID>[10]();
		int check = 1;
		if (!q3.empty())
		{
			if (q3.compare("AND") == 0)
			{
				for (int i = 0;i < y.size();i++)
				{
					int j;
					for (j = 0;j < y1.size();j++)
					{
						if (y[i].textnum == y1[j].textnum)
						{
							if (check)
							{
								check = 0;
								tar.push_back(y[i]);
							}
							tar.push_back(y1[j]);
						}
					}

				}
				sprint(tar);
			}
			else if (q3.compare("OR") == 0)
			{
				for (int i = 0;i < y.size();i++)
				{
					tar.push_back(y[i]);

				}
				for (int i = 0;i < y1.size();i++)
				{
					int j;
					for (j = 0;j < y.size();j++)
					{
						if (y[i].textnum == y1[j].textnum && y[i].linenum == y1[j].linenum)
						{
							break;
						}
					}
					if(j == y.size())
						tar.push_back(y1[i]);

				}
				sprint(tar);
			}
			else if (q3.compare("NOT") == 0)
			{
				
				
 				for (int i = 0;i < n;i++)
				{
					int j;
					for ( j = 0;j <y.size();j++)
					{
						if (i == y[j].textnum)
							break;
					}
					if (j == y.size())
					{
						int count2 = 0;
						while (1)
						{
							if (!isalpha(text2[i][count2][0][0]))
								break;
							printf("%s\n",text2[i][count2++]);
						}
					}
					if (tr)
					{
						tr = 0;
						continue;
					}
					printf("---------\n");
				}
				printf("==========\n");
				
			}
		}
		else {
			vector <DID> y = link[q2[0]];
			sprint(y);
		}
	}
	
    return 0;
}

