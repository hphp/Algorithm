#include <stdio.h>
#include <iostream>
#include <map>
#include <string>

#define N 1001000
#define LEN	60

using namespace std;

struct Node
{
	string name;
	struct Node *pre, *next;
};

map<string, struct Node*> hash;
struct Node *head, buf[N];
int n, buf_cnt;

void add(struct Node* node)
{
	if (head == NULL)
		head = node;
	else
	{
		head->pre = node;
		node->next = head;
		head = node;
	}
}

void del(struct Node *node)
{
	if (node->pre == NULL)
	{
		head = head->next;
		if (head)
			head->pre = NULL;
	}
	else
	{
		struct Node *pt = node->pre;
		struct Node *nt = node->next;
		pt->next = nt;
		if (nt)
			nt->pre = pt;	
	}
}

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		hash.clear();
		buf_cnt = 0;
		head = 0;
		
		for (int i = 0; i < n; i++)
		{
			char type[LEN], name[LEN];
			scanf("%s", type);
			if (type[0] != 's')
				scanf("%s", name);
			struct Node *cur;
			switch (type[0])
			{
				case 'n':
					cur = &buf[buf_cnt++];
					cur->name = name;
					cur->pre = NULL;
					cur->next = NULL;
					add(cur);
					hash[name] = cur;
					break;
				case 'r':
					cur = hash[name];
					if (cur == NULL)
					{
						cur = &buf[buf_cnt++];
						cur->name = name;
						cur->pre = NULL;
						cur->next = NULL;
						add(cur);
						hash[name] = cur;
					}
					else
					{
						del(cur);
						cur->pre = NULL;
						cur->next = NULL;
						add(cur);
					}
					break;
				case 't':
					cur = hash[name];
					hash[name] = NULL;
					if (cur)
						del(cur);
					break;
				case 's':
					int left = 100;
					cur = head;
					while (cur && left)
					{
						cout << cur->name << endl;
						left--;
						cur = cur->next;
					}
					cout << "###" << endl;
					break;
			}
		}
		
		cout << endl;
	}
	
	return 0;
}

