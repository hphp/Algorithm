#include <stdio.h>
#define N 11
#define STM (1<<N)
#define WIN(a,b) ((v[a]>v[b])?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

int mx,mn;
int n,askk;
bool exist[STM][N];
int bitn[STM];
/*
void finit()
{
	for(int i=0;i<STM;i++)
	{
		int cnt = 0;
		for(int j=0;j<n;j++)	
			if((1<<j)&i)
				cnt++;
		bitn[i] = cnt;
	}
}

void dfs(int curstm)
{
	if(bitn[curstm] == 1)
		for(int i=0;i<n;i++)
			if((1<<i)&curstm)
			{
				exist[curstm][i] = 1;
				return;
			}
	int cn = bitn[curstm]/2;
	for(int i=0;i<=curstm/2;i++)
	{
		if((i & curstm) == i && bitn[i] == cn)
		{
			int anstm = curstm-i;
			dfs(i);
			dfs(anstm);
			for(int k=0;k<n;k++)
				if(((1<<k)&i)&&exist[i][k])
					for(int kk=0;kk<n;kk++)
						if(((1<<kk)&anstm)&&exist[anstm][kk])
							exist[curstm][WIN(k,kk)] = 1;
		}
	}
	if(exist[curstm][askk])
	{
		mx = Max(mx,bitn[curstm]);
		mn = Min(mn,bitn[curstm]);
	}
}
	*/

int v[STM];

int main()
{
//	finit();
	while(scanf("%d%d",&n,&askk)!=EOF)
	{
		mn = n;
		mx = 0;
		int stm = 1<<n;
		for(int i=0;i<stm;i++)
			scanf("%d",&v[i]);
		int s = 0 , b = 0;
		for(int i=0;i<stm;i++)
			if(v[i] < v[askk])
				s++;
			else if(v[i] > v[askk])
				b++;
		if(b)
			mn = 0;
		else mn = n;
		if(s==0)
			mx = 0;
		else
		{
			int tmp = s+1;
			while(tmp>=2)	
			{
				tmp/=2;
				mx++;
			}
		}
		printf("%d %d\n",mn,mx);
	}
	return 0;
}
