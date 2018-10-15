// ConsoleApplication14.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <string>
#include <queue>
#pragma warning( disable : 4996)

using namespace std;

struct Node
{
	int v;
	int  c;
	Node *l, *r;
	Node() :c(0), l(NULL), r(NULL) {}
};
const int maxn = 1000;

int check = 1;
Node *root=new Node();
void myprint()
{
	queue<Node*> q;
	if (check)
	{
		q.push(root);
		while (!q.empty())
		{
			Node *temp= q.front();
			q.pop();
			printf("%d ",temp->v);
			if(temp->l!=NULL)
			q.push(temp->l);
			if (temp->r != NULL)
				q.push(temp->r);
		}
		printf("\n");
	}
	else
		printf("not complete\n");
}
void add(int val, char* c)
{
	int i = 0;
	
	Node * cur=root;
	while (c[i]!=')')
	{
		
		printf("%c",c[i]);

		if (c[i] == 'L')
		{
			if (cur->l != NULL)
				cur = cur->l;
			else
			{
				Node* temp = new Node();
				cur->l = temp;
			}
		}
		if (c[i] == 'R')
		{
			if (cur->r != NULL)
				cur = cur->r;
			else
			{
				Node* temp = new Node();
				cur->r = temp;
			}
		}
		++i;

	}
	cur->c++;
	cur->v = val;
	printf("3 %d\n", cur->c  );
	printf("3 %d\n", cur->v);
}
void remove(Node* u)
{
	if (u == NULL) return;
	remove(u->l);
	remove(u->r);
	delete u;
}
int main()
{
	//string s;
	queue<Node*> q1;
	char s[maxn];
	while (scanf("%s", s) == 1)
	{
		printf("1 %s\n", s);
		if (!strcmp(s, "()"))
		{

			
				q1.push(root);
				while (!q1.empty())
				{
					Node *temp = q1.front();
					q1.pop();
					
					if (temp->c != 1)
					{
						printf("xy %d\n", temp->c);
						printf("xy %d\n", temp->v);
						check = 0;
						break;
					}
					if (temp->l != NULL)
						q1.push(temp->l);
					if (temp->r != NULL)
						q1.push(temp->r);
				}
			myprint();
			check = 1;
			remove(root);
			root = new Node();
			printf("2 \n");
		}
		int v;
		sscanf(&s[1], "%d", &v);
		add(v,strchr(s,',')+1);
		//printf("2 %s\n", s);
	}
	printf("3 %s\n", s);
	//printf("3 \n");
    return 0;
}

