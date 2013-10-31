#include <stdio.h>
#include <string.h>
#define M 1001
#define S 120
#define N 10100
#define MAX (1<<28)

int vl[M];
int mx[N][S];
int from[N][S];
int n,m,a,ss;
char s[100];

int main()
{
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		for(int i=0;i<M;i++)
			vl[i] = 0;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&ss,&a);
/*			int sum = 0;
			for(int j=0;j<strlen(s);j++)
			{
				sum *= 10;
				sum += s[j]-'0';
			}*/
			vl[ss] += a;
		}
		if(n < 3)
		{
			for(int i=0;i<n;i++)
				printf("0");
				printf("\n");
			continue;
		}
	/*	for(int i=0;i<1000;i++)
			if(vl[i])
				printf("%d %d\n",i,vl[i]);*/
		for(int i=0;i<=n;i++)
			for(int j=0;j<100;j++)
				mx[i][j] = -MAX;
		for(int i=0;i<100;i++)
			mx[2][i] = 0;
		for(int i=3;i<=n;i++)
		{
			for(int j=0;j<100;j++)
			{
				if(mx[i-1][j] == - MAX)
					continue;
				int g = j/10;	
				for(int k=0;k<10;k++)
				{
					int next = k*10+g;
					int cur = k*100 + j;
/*					int cur2 = next;
					int cur3 = k;*/
					int tmp = mx[i-1][j];
					if(tmp > -MAX)
//						tmp += vl[cur1] + vl[cur2] + vl[cur3] ;
						tmp += vl[cur];
					if(mx[i][next] < tmp)
					{
//						if(i == 3 && next == 56)
				//		printf("i:%d  next %d j:%d k:%d tmp %d mx:%d vl %d cur %d\n",i,next,j,k,tmp,mx[i-1][j],vl[cur],cur);
						mx[i][next]	= tmp;
						from[i][next] = j;
					}
				}
			}
		}
		int ans = -MAX ;
		int last = 0;
		for(int i=0;i<100;i++)
		{
			if(mx[n][i] > ans)
			{
				ans = mx[n][i];
				last = i;
			}
		}
	/*	int a,b;
		while(scanf("%d %d",&a,&b)&&a&&b)
			printf("%d\n",mx[a][b]);
		printf("%d %d\n",ans,last);*/
		int cc = n;
		while(cc > 2)
		{
			printf("%d",last/10);
			last = from[cc][last];
			cc --;
		}
		if(last/10 == 0)printf("0");
		printf("%d",last);
		printf("\n");
	}
}
/*

2 5
5 100
3 100

2 5
557 -10
799 -10

2 5
557 10
799 10
2 6
557 10
799 10


4 5
557 10
799 10
123 10
321 -20

4 6
557 10
799 10
123 10
321 -20

2 1
123 10
012 1

2 2
123 10
012 1

2 6
321 129
123 3


2 6
321 129
123 129

2 8
321 129
123 129


2 8
421 129
4 129
2 8
5 129 
4 129

*/
