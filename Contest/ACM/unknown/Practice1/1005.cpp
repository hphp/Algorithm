//09-10-04----21:11---
#include <stdio.h>
#include <algorithm>
#define N 100100
#define lowbit(a) (a&(a^(a-1)))

int m,n;
struct Inf
{
	int sign;int v;
	int mapv;
}inf[N];
int sum[N],rec[N],cnt,map[N],mapcnt;

int find(int cur)
{
	int s = 1;
	int e = mapcnt-1;
	while(s<=e)
	{
		int mid = (s+e)/2;
		if(map[mid] == cur)
			return mid;
		else if(map[mid] < cur)
			s = mid+1;
		else e = mid-1;
	}
}

void insert(int cur,int add)
{
	for(int i=cur;i<mapcnt; i+=lowbit(i))
	{
		sum[i]+= add;
	}
}

int query(int cur)
{
	int ans = 0;
	while(cur)
	{
		ans += sum[cur];
		cur -= lowbit(cur);
	}
	return ans;
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		cnt =0;
		for(int i=0;i<n;i++)	
		{
			int a ;
			scanf("%d",&a);
			inf[i].sign = a;
			if(a==0)
			{
				int b;
				scanf("%d",&b);
//				another[cnt] = b;
				rec[cnt++]=b;
				inf[i].v = b;
			}
		}
		std::sort(rec,rec+cnt);
		mapcnt = 1;
		for(int i=0;i<cnt;i++)
		{
			if((i==0)||rec[i]!=rec[i-1])	
			{
				sum[mapcnt] = 0;
		//		printf("%d %d\n",mapcnt,rec[i]);
				map[mapcnt++]=rec[i];
			}
		}
		int count = 0;
		for(int i=0;i<n;i++)
		{
			int flag = 0;
			if(inf[i].sign==0)	
			{
				int id = find(inf[i].v);
				count++;
	//			inf[i].mapv = id;
				insert(id,1);
/*				for(int j=1;j<mapcnt;j++)
				{
					printf("after change%d %d %d\n",inf[i].v,map[j],query(j));
				}
				printf("end\n");*/
			}
			else
			{
				if(count==0)
				{
					printf("No Element!\n");
					continue;
				}
				int s = 1;
				int e = mapcnt-1;
				int trec = 0;
				int mid;
				int stdard = (count+1)/2;
				int part = query(s);
				if(part==stdard)
				{
					printf("%d\n",map[s]);
					//printf("hi:%d\n",map[s]);
					insert(s,-1);
					count--;
					continue;
				}
				while(s+1<e)
				{
					mid = (s+e)/2;
					int part1 = query(mid);
					//printf("%d %d %d\n",s,e,part1);
					trec = part1;
					if(part1>=stdard)
					{
						//int part2 = query(mid-1);
						e = mid;
						/*if(part2>stdard)
						{
							e = mid;	
						}
						else
						{
							flag =1;
							printf("%d %d\n",mid,inf[mid].v);
							break;
						}*/
					}
					else if(part1<stdard)
					{
						s = mid;	
					}
				}
				if(s+1>=e)
				{
					//printf("rec:%d stdard%d\n",trec,stdard);
					int part = query(e);
					if(part >= stdard)
					{
				//		printf("hello %d %d\n",e,map[e]);
						printf("%d\n",map[e]);
						insert(e,-1);
					}
					//else printf("none -1\n");
				}
				/*else 
				{
					printf("mid:%d\n",map[mid]);
				}*/
		//		else printf("s+1<e-1\n");
				count--;
			}
		}
		printf("\n");
	}
	return 0;
}