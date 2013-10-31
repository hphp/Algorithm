#include <stdio.h>

int n,ans[21];
int vstv[21],vstp[21];
int rec[21];
int first ;
void dfs(int cp,int cnt)
{
	if(cnt == n+1)
	{
		ans[n]++;
		rec[n] = 1;
		for(int i=1;i<=n;i++)
			printf("%d ",rec[i]);
			printf("good \n");
		return;	
	}
	for(int k=1;k<=n;k++)
	{
		if(vstv[k]==0)
		{
			vstv[k] =1;
			rec[cp] = k;
			dfs(k,cnt+1);
			vstv[k] = 0;
		}
	}
}

int main()
{
	for(int i=2;i<4;i++)
	{
		n = i;
	//	for(int k=1;k<=i;k++)
		{
		for(int j=0;j<=i;j++)
			vstp[j] = vstv[j] = 0;
			dfs(1,1);
		}
		printf("forget\n");
		printf("%d,",ans[i]);
	}
	while(1);
}
/*
*/
