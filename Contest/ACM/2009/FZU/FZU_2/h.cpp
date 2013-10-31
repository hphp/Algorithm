#include <stdio.h>
#define N 101000

int taller[N],h[N];
int n;

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1;i<=n;i++)	
			scanf("%d",&h[i]);
		h[n+1]=-1;
		taller[n]=0;
		for(int i=n-1;i>0;i--)
		{
			if(h[i]<h[i+1])	
			{
				taller[i]=i+1;
			}
			else
			{
				int index = i+1;
				while(index<=n&&index>0)	
				{
					if(h[i]<h[index])	
					{
						taller[i]=index;break;
					}
					index = taller[index];
				}
				if(index>n||index<=0)
					taller[i]=0;
			}
		}
		for(int i=1;i<=n;i++)
			printf("%d\n",taller[i]);
	}
	return 0;
}
