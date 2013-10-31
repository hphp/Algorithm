#include <stdio.h>
#define N 100100
int rec[N][2],mx[N][2];
int one[N];
int n,l;
char s[N];

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%d%d",&n,&l);
		scanf("%s",s);
		one[0] = 0;
		for(int i=1;i<=n;i++)
			one[i] = one[i-1] + s[i-1]-'0';
		mx[1][0] = one[1] , mx[1][1] = 1;
		rec[1][0] = 1;
		for(int i=2;i<l;i++)
		{
			int c = i-1;
			mx[i][0] = one[i]-one[c];
			mx[i][1] = l;
			rec[i][1] = i;
			rec[i][0] = c+1;
			while(c>0)
			{
				if(mx[i][0]*mx[c-1][1] <= mx[i][1]*mx[c-1][0])
				{
					mx[i][0] += mx[c-1][0];
					rec[i][0] = rec[c-1][0];
				}
				c = rec[c-1][0]-1;
			}
		}
		for(int i=1;i<l;i++)
			printf("%d ",rec[i][0]);
		printf("\n");
		for(int i=l;i<=n;i++)
		{
			int c = i-l;
			mx[i][0] = one[i]-one[c];
			mx[i][1] = l;
			rec[i][1] = i;
			rec[i][0] = c+1;
			while(c>0)
			{
				if(mx[i][0]*mx[c-1][1] <= mx[i][1]*mx[c-1][0])
				{
					mx[i][0] += mx[c-1][0];
					rec[i][0] = rec[c-1][0];
				}
				c = rec[c-1][0]-1;
			}
		}
		int s = 1,e = l;
		for(int i=l;i<=n;i++)
		{
			if(mx[e][0]*mx[i][1] == mx[e][1]*mx[i][0])
			{
				if(rec[i][0] < s)
					e = i , s = rec[i][0];
			}
			if(mx[e][0]*mx[i][1] < mx[e][1]*mx[i][0])
			{
				e = i;
				s = rec[i][0];
			}
		}
		printf("%d %d\n",s,e);
	}
	return 0;
}
