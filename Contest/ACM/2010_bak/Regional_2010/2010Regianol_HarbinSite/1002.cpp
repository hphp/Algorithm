#include <stdio.h>
#define N 1039
int flag;
int ans[N];
int fans[N];
int n,m;
void dfs(int lls,int rs,int sp,int ep,int ans[N])
{
	if(flag == 1)
		return;
	if(sp == ep +1)
	{
		if(lls != rs)
			return;
		flag = 1;
		for(int i=1;i<=n;i++)
			fans[i] = ans[i];
		return;	
	}
	if(sp > ep)
	{
		flag = 1;
		for(int i=1;i<=n;i++)
			fans[i] = ans[i];
		return;
	}
	for(int i=0;i<10;i++)
	{
		int s = 0;
		int e = 9;
		if(sp == ep)
			s = e = i;
		for(int j=s;j<=e;j++)
		{
			int sk = 0 ; 
			int ek = 9;
			if(sp == ep)
				sk = ek = rs;
			for(int k=sk;k<=ek;k++)
			{
				if((i*m+k)/10 == lls)
					if((i*m+k)%10 == j)
						if((j*m+rs)%10 == i)
						{
							ans[sp] = i;
							ans[ep] = j;
							dfs(k,(j*m+rs)/10,sp+1,ep-1,ans);
						}
			}	
		}
	}
}


int main()
{
	freopen("in2.in","r",stdin);
	freopen("outmy2.out","w",stdout);
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n == 1 && m == 1)
		{
			printf("1\n");
			continue;
		}
		flag = 0;
		if(n == 1)
		{
			printf("No solution\n");
			continue;
		}
		for(int i=1;i<10;i++)
		{
			for(int j=1;j<10;j++)
			{
				for(int k=0;k<10;k++)
				{
					if((i*m+k)%10 == j)
					if((i*m+k)/10 == 0)
					if((j*m)%10 == i)
					{
						ans[1] = i;
						ans[n] = j;
						dfs(k,(j*m)/10,2,n-1,ans);
					}
				}
			}
		}
		if(flag)
			for(int i=1;i<=n;i++)
				printf("%d",fans[i]);
		else printf("No solution");
		printf("\n");
	}
	return 0;
}
