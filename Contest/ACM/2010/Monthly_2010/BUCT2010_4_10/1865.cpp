#include <stdio.h>
#define N 101000
#define L 26
#include <string.h>

char s[N];
int map[L];//0 fuyin 1 yuanyin
int rec[L];
int owel[5]={0,4,8,14,20};
int wel[21];
int curo,curw;
int size;

int deal(int f)
{
	int flag = f;
	for(int i=0;i<L;i++)
	{
		map[i] = -1;
		rec[i] = -1;
	}
	int i;
	for(i=0;i<size;i++)
	{
		if(s[i] == ' ')
			continue;
		int sign = map[s[i]-'A'];
		printf("%c %d %d\n",s[i],sign,flag);
		if(sign > -1)
		{
			if(sign != flag)
				break;
		}
		else
		{
			if(flag == 1)
			{
				if(curo < 5)
				{
					map[s[i]-'A'] = 1;
					rec[s[i]-'A'] = curo;
					curo++;
				}
				else break;
			}
			else
			{
				if(curw < 21)
				{
					map[s[i]-'A'] = 0;
					rec[s[i]-'A'] = curw;
					curw++;
				}
				else break;
			}
		}
		flag = 1-flag;
	}
	return i;
}

struct Node
{
	int f;
	int s;
}node[L];

int find(int cur)
{
	if(node[cur].f == cur)
		return cur;
	node[cur].f = find(node[cur].f);
	return node[cur].f;
}

int unionft(int f,int t)
{
	int ff = find(f);
	int tf = find(t);
	if(ff != tf)
	{
		node[ff].f = tf;
		node[tf].s += node[ff].s;
	}
	return 1;
}

int main()
{
	int cnt =0;
	for(int i=0;i<L;i++)
	{
		int j=0;
		for(;j<5;j++)
			if(i==owel[j]) 
				break;
		if(j==5)
		{
			wel[cnt++]=i;
		}
	}
	while(gets(s)!=NULL)
	{
		size = strlen(s);
		rrec = 0;
		for(int i=0;i<L;i++)
		{
			node[i].f = i;
			node[i].s = 1;
		}
		int sign  = 1;
		for(int i=0;i<size;i++)
		{
			if(sign == 0)break;
			if(s[i]==' ')
			{
				for(int j=2;j<rrec;j+=2)
				{
					sign = unionft(ss[j]-'A',ss[0]-'A');
				}
				if(sign)
				{
					for(int j=3;j<rrec;j+=2)
					{
						sign = unionft(ss[j]-'A',ss[1]-'A');
						if(sign == 0)
							break;
					}
				}
				rrec =0;
				if(sign==0)break;
				continue;
			}
			ss[rrec++] = s[i];
		}
		if(sign == 0)
		{
			printf("impossible");
			continue;
		}
		int fi = -1;
		int fj = -1;
		for(int i=0;i<L;i++)
		{
			for(int j=i+1;j<L;j++)
			{
				fi = find(i);
				fj = find(j);
				if(fi!=fj)
				{
					break;	
				}
			}
		}
		if(node[fi].s > node[fj].s)
		{
			int tmp = fi;
			fi = fj;
			fj = tmp;
		}
		if(node[fi].s <= node[fj].s)
		{
			if(node[fi].s <= 5)
			{
				for(int i=0;i<L;i++)
					if(find(i) == fi)
					{
						rec[i] = owel[curo++];
					}
				if(node[fj].s <= 21)
				{
					for(int i=0;i<L;i++)
						if(find(i) == fj)
						{
							rec[i] = owel[curo++];
						}
				}
				else
				{
					printf("impossible\n");
					continue;
				}
			}
			else 
			{
				printf("impossible\n");
					continue;
			}
		}
		for(int i=0;i<size;i++)
		{
			if(s[i]==' ')
				printf("\n");
			else printf("%c",rec[s[i]-'A']+'A');
		}
		printf("\n");
	}	
	return 0;
}
