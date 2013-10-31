#include <stdio.h>
#define N 11
#define STM (1<<11)

int ones[N];

void booling()
{
	for(int i=0;i<STM;i++)
	{
		int cnt = 0 ;
		for(int j=0;j<N;j++)
			if(i & (1<<j))
			{
				cnt ++;	
			}
		ones[i] = cnt;
	}
}

void connect()
{
	for	
}

int main()
{
	booling();
	while(scanf("%d %d %d",&n,&m,&k)!=EOF)
	{
		if(!(n||m||k))break;
		for(int i=0;i<m;i++)
			scanf("%s",s[i]);
		connect();
	}
}
