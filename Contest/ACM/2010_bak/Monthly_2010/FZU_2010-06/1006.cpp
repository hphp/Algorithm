#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 10010
#define S 51
#define M 1001000
#define L 26

struct Node
{
	Node * branch[L];
	Node * shift;
	int isleaf;
	Node()
	{
		for(int i=0;i<L;i++)
			branch[i] = NULL;
		shift = NULL;
		isleaf = 0;
	}
}*root,*queue[N*S];
int tt;
int n;
char ori[M];

void insert(char * s)
{
	int size = strlen(s);
	Node * tmp = root;
	for(int i = 0 ;i < size; i ++)
	{
		int index = s[i]-'a';
		if(tmp->branch[index] == NULL)
		{
			tmp->branch[index] = new Node();
		}
		tmp = tmp->branch[index];
	}
	tmp->isleaf ++;
}

void build(Node * root)
{
	int s = 0;
	int f = 1;
	queue[s] = root;
	while(s<f)
	{
		Node * tmp = queue[s];
		for(int i = 0;i<L;i++)
		{
			if(tmp->branch[i] != NULL)
			{
				Node * cur = tmp->shift;
				while(cur != NULL)
				{
					if(cur->branch[i] != NULL)
						break;
					cur = cur->shift;	
				}
				if(cur == NULL)
					tmp->branch[i]->shift = root;
				else tmp->branch[i]->shift = cur->branch[i];
				queue[f++] = tmp->branch[i];
			}
		}
		s++;
	}
}

int AC_automation(char * ori,Node * root)
{
	int cnt = 0;
	int size = strlen(ori);
	Node * tmp = root;
	for(int i = 0 ; i < size ; i++)
	{
		int index = ori[i]-'a';
		while(tmp != NULL && tmp->branch[index] == NULL)
		{
			tmp = tmp->shift;
		}
		if(tmp == NULL)
		{
			tmp = root;
		}
		else if(tmp->branch[index] != NULL)
		{
			tmp=tmp->branch[index];
		}
//		if(tmp->isleaf == 1)
		{
			Node * tt = tmp;
			while(tt != root && tt->isleaf != -1)
			{
//				if(tt->isleaf == 1)
				{
					cnt += tt->isleaf;	
					tt->isleaf = -1;
				}
				tt = tt->shift;
			}	
		}
	}
	return cnt;
}

void freeing(Node * cur)
{
	for(int i=0;i<L;i++)
		if(cur->branch[i] != NULL)
			freeing(cur->branch[i]);
	free(cur);
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		root = new Node();
		char s[S];
		for(int i = 0 ; i < n ; i ++)
		{
			scanf("%s",s);
			insert(s);
		}
		build(root);
		scanf("%s",ori);
		int ans = AC_automation(ori,root);
		printf("%d\n",ans);
		Node * tmp = root;
		freeing(tmp);
	}	
	return 0;
}
