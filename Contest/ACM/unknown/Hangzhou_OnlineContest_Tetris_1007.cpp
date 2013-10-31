#include <stdio.h>

char stds[8] = "IJLOSTZ";
int n,m;

struct B
{
	int w;
	int add[4];
	int dis[4];
};

struct A
{
	int cnt;
	struct B b[4];
};

struct A p[7];

int fans;
void init()
{
	//0
	p[0].cnt = 2;
	//00
	p[0].b[0].w = 4;
	p[0].b[0].add[0] = 1;
	p[0].b[0].add[1] = 1;
	p[0].b[0].add[2] = 1;
	p[0].b[0].add[3] = 1;
	p[0].b[0].dis[0] = 0;
	p[0].b[0].dis[1] = 0;
	p[0].b[0].dis[2] = 0;
	p[0].b[0].dis[3] = 0;
	//01
	p[0].b[1].w = 1;
	p[0].b[1].add[0] = 4;
	p[0].b[1].dis[0] = 0;


	//1
	p[1].cnt = 4;
	//10
	p[1].b[0].w = 3;
	p[1].b[0].add[0] = 2;
	p[1].b[0].add[1] = 1;
	p[1].b[0].add[2] = 1;
	p[1].b[0].dis[0] = 0;
	p[1].b[0].dis[1] = 0;
	p[1].b[0].dis[2] = 0;
	//11
	p[1].b[1].w = 2;
	p[1].b[1].add[0] = 3;
	p[1].b[1].add[1] = 1;
	p[1].b[1].dis[0] = 0;
	p[1].b[1].dis[1] = 2;
	//12
	p[1].b[2].w = 3;
	p[1].b[2].add[0] = 1;
	p[1].b[2].add[1] = 1;
	p[1].b[2].add[2] = 2;
	p[1].b[2].dis[0] = 0;
	p[1].b[2].dis[1] = 0;
	p[1].b[2].dis[2] = -1;
	//13
	p[1].b[3].w = 2;
	p[1].b[3].add[0] = 1;
	p[1].b[3].add[1] = 3;
	p[1].b[3].dis[0] = 0;
	p[1].b[3].dis[1] = 0;
	
	
	//2
	p[2].cnt = 4;
	//20
	p[2].b[0].w = 3;
	p[2].b[0].add[0] = 1;
	p[2].b[0].add[1] = 1;
	p[2].b[0].add[2] = 2;
	p[2].b[0].dis[0] = 0;
	p[2].b[0].dis[1] = 0;
	p[2].b[0].dis[2] = 0;
	//21
	p[2].b[1].w = 2;
	p[2].b[1].add[0] = 3;
	p[2].b[1].add[1] = 1;
	p[2].b[1].dis[0] = 0;
	p[2].b[1].dis[1] = 0;
	//22
	p[2].b[2].w = 3;
	p[2].b[2].add[0] = 2;
	p[2].b[2].add[1] = 1;
	p[2].b[2].add[2] = 1;
	p[2].b[2].dis[0] = 0;
	p[2].b[2].dis[1] = 1;
	p[2].b[2].dis[2] = 1;
	//23
	p[2].b[3].w = 2;
	p[2].b[3].add[0] = 1;
	p[2].b[3].add[1] = 3;
	p[2].b[3].dis[0] = 0;
	p[2].b[3].dis[1] = -2;
	
	//3
	p[3].cnt = 1;
	//30
	p[3].b[0].w = 2;
	p[3].b[0].add[0] = 2;
	p[3].b[0].add[1] = 2;
	p[3].b[0].dis[0] = 0;
	p[3].b[0].dis[1] = 0;
	
	
	//4
	p[4].cnt = 2;
	//40
	p[4].b[0].w = 3;
	p[4].b[0].add[0] = 1;
	p[4].b[0].add[1] = 2;
	p[4].b[0].add[2] = 1;
	p[4].b[0].dis[0] = 0;
	p[4].b[0].dis[1] = 0;
	p[4].b[0].dis[2] = 1;
	//41
	p[4].b[1].w = 2;
	p[4].b[1].add[0] = 2;
	p[4].b[1].add[1] = 2;
	p[4].b[1].dis[0] = 0;
	p[4].b[1].dis[1] = -1;
	
	
	//5
	p[5].cnt = 4;
	//50
	p[5].b[0].w = 3;
	p[5].b[0].add[0] = 1;
	p[5].b[0].add[1] = 2;
	p[5].b[0].add[2] = 1;
	p[5].b[0].dis[0] = 0;
	p[5].b[0].dis[1] = 0;
	p[5].b[0].dis[2] = 0;
	//51
	p[5].b[1].w = 2;
	p[5].b[1].add[0] = 3;
	p[5].b[1].add[1] = 1;
	p[5].b[1].dis[0] = 0;
	p[5].b[1].dis[1] = 1;
	//52
	p[5].b[2].w = 3;
	p[5].b[2].add[0] = 1;
	p[5].b[2].add[1] = 2;
	p[5].b[2].add[2] = 1;
	p[5].b[2].dis[0] = 0;
	p[5].b[2].dis[1] = -1;
	p[5].b[2].dis[2] = 0;
	//53
	p[5].b[3].w = 2;
	p[5].b[3].add[0] = 1;
	p[5].b[3].add[1] = 3;
	p[5].b[3].dis[0] = 0;
	p[5].b[3].dis[1] = -1;
	
	
	//6
	p[6].cnt = 2;
	//60
	p[6].b[0].w = 3;
	p[6].b[0].add[0] = 1;
	p[6].b[0].add[1] = 2;
	p[6].b[0].add[2] = 1;
	p[6].b[0].dis[0] = 0;
	p[6].b[0].dis[1] = -1;
	p[6].b[0].dis[2] = -1;
	//61
	p[6].b[1].w = 2;
	p[6].b[1].add[0] = 2;
	p[6].b[1].add[1] = 2;
	p[6].b[1].dis[0] = 0;
	p[6].b[1].dis[1] = 1;
}

int sum[8];


int name[12];
int h[23];
void ainit()
{
	for(int i=0;i<8;i++)
		sum[i] = 0;
	for(int i=0;i<23;i++)
		h[i] = 0;
	fans = 0;
}


//m : height , n : w;

void dfs(int cur)
{
	if(fans== 1)
	{
		return;	
	}
	if(cur == 10)
	{
		for(int j=0;j<n;j++)
			printf("%d ",h[j]);
			printf("\n");
		int j = 0;
		for(j=0;j<n;j++)
			if(h[j] != m)
				break;
		if(j == n)
			fans = 1;
		return;
	}
	int no = name[cur];
	for(int i=0;i<p[no].cnt;i++)	
	{
		//B curB = p[no].b[i];
/*
		if(cur == 2)
			printf("lim:%d\n",n-p[no].b[i].w);
			*/
		for(int stp = 0 ; stp <= n-p[no].b[i].w; stp ++)
		{
			int j = stp;
			int ff = 0;
			for(j = stp;j<stp+p[no].b[i].w; j++)
			{
				if((j > stp)&&((h[j]-h[stp])!=p[no].b[i].dis[j-stp]))
				{
					ff = 1;
				/*
					if(cur == 2)
						printf("hei %d %d %d\n",h[j],h[stp],p[no].b[i].dis[j-stp]);
						*/
					
					break;
				}
			}
			if(cur == 2)
			{
				printf("%d\n",no);
				for(int j=0;j<n;j++)
					printf("%d ",h[j]);
					printf("\n");
			}
			if(ff == 0)
			{
				for(j=stp;j<stp+p[no].b[i].w;j++)
				{
					h[j] += p[no].b[i].add[j-stp];
					if(h[j] > m)
					{
						ff = 1;
					}
				}
				if(ff == 0)
				{
					dfs(cur+1);
				
				}
				for(j=stp;j<stp+p[no].b[i].w;j++)
				{
					h[j] -= p[no].b[i].add[j-stp];
				}
			}
		}
	}
}

int main()
{
	init();
	char s[3];
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		ainit();
		for(int i=0;i<10;i++)
		{
			scanf("%s",s);
			int j=0;
			for(;j<10;j++)
			{
				if(s[0] == stds[j])
					break;
			}
			name[i] = j;
			sum[j] ++;
		}
		if(n == 40 || m == 40)
		{
			if(sum[0] == 10)
			{
				fans = 1;
	//			printf("Yes\n");
			}
			else
			{
				fans = 0;
			//	printf("No\n");
			}
		}
		else if( n == 2 && m == 20)
		{
			int i;
			for(i=4;i<7;i++)
				if(sum[i])
					break;
			if(i == 7)
			{
				dfs(0);
			}
			else 
				fans = 0;
		}
		else
		{
			printf("hello\n");
			dfs(0);
		}
		if(fans == 1)
			printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
