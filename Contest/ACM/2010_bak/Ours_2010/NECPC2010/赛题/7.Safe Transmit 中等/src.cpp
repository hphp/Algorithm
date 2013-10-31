#include <stdio.h>

int g[1005][1005];
int ans[1005][1005];
bool flag[1005];
int que[1005];
int num;
int n,m;

bool input()
{
	int i,j;
	int a,b;
	char c;
	
	if(scanf("%d %d", &n, &m)!=EOF)
	{
		for(i=1; i<=n; ++i)
		{
			for(j=1; j<=n; ++j)
			{
				ans[i][j] = g[i][j] = 4;
			}
		}
		for(i=1; i<=m; ++i)
		{
			scanf("%d %d %c", &a, &b, &c);
			if(g[a][b] > c - 'A' + 1)
				g[a][b] = g[b][a] = c - 'A' + 1;
		}
		return true;
	}
	return false;
}

void find(int now, int t)
{
	int i;
	
	que[num++] = now;
	flag[now] = true;
	
	for(i=1; i<=n; ++i)
	{
		if(flag[i] == false)
		{
			if(g[now][i] <= t)
			{
				find(i, t);
			}
		}
	}
}

void slove(int t)
{
	
	int i,j,k;
	for(i=1; i<=n; ++i)
	{
		flag [i] = false;
	}
	for(k=1; k<=n; ++k)
	{
		if(flag[k] == false)
		{
			num = 0;
			
			find(k, t);
			for(i=0;i<num; ++i)
			{
				for(j=i+1; j<num; ++j)
				{
					if(ans[que[i]][que[j]] == 4)
						ans[que[i]][que[j]] = ans[que[j]][que[i]] = t;
				}
			}
		}
	}
}

void print()
{
	int i,a,b;
	
	scanf("%d", &m);
	for(i=0; i<m; ++i)
	{
		scanf("%d %d", &a, &b);
		printf("%c\n", ans[a][b] +'A' -1);
	}
}

int main()
{
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
	int i = 0;
	while(input())
	{
		if(i!=0)
		{
			printf("\n");
		}
		slove(1);
		slove(2);
		slove(3);
		print();
		i++;
	}
}
