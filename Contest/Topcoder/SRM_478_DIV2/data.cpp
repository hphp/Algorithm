#include <stdio.h>

int main()
{
	int n,l,r;
	while(scanf("%d",&n)!=EOF)
	{
		printf("%d\n",n);
		scanf("%d%d",&l,&r);
		int s = l;
		for(int i=0;i<n;i++)
		{
			if(s > r)
				s = l;
			printf("%d ",s);
			s++;
		}
		for(int i=0;i<n;i++)
		{
			if(s > r)
				s = l;
			printf("%d ",s);
			s++;
		}
	}
}
