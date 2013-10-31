#include <stdio.h>
#include <string.h>
#define N 100010
#define MAX 100000000000LL 

int backup[N];

struct Member
{
	long long int rate;
	int belong;
}member[N];
struct Company
{
	int sign;//zero p -1 go with others 1 exists;
	long long int lowest_rate;
	int blong;
//	int *belong1 ;
//	int ** belong;
}company[N];
int n,k,m;

void init(void)
{
	for(int i=0;i<n;i++)
	{
		company[i].sign=0;
	company[i].lowest_rate=MAX;
	company[i].blong=i;
//company[i].belong =NULL;
//company[i].belong1=NULL;
	}
	printf("%d\n",company[0].lowest_rate);
}

int find(int x)
{
	if(company[x].blong!=x)
		return find(company[x].blong);
	else return x;
}

int main()
{
	for(int i=0;i<N;i++)
		backup[i]=i;
	while(scanf("%d%d%d",&n,&k,&m)!=EOF)
	{
		init();
		for(int i=1;i<=k;i++)
		{
			scanf("%lld%d",&member[i].rate,&member[i].belong);
			int cid=member[i].belong;
	//		backup[cid]=cid;
//			company[cid].belong1=backup+cid;
//			company[cid].belong = &company[cid].belong1;
			company[cid].sign=1;
			if(company[cid].lowest_rate>member[i].rate)
				company[cid].lowest_rate=member[i].rate;
		}
		int cid,trate;
		char s[19];
		for(int i=0;i<m;i++)
		{
			scanf("%s",s);
			if(strcmp(s,"GT")==0)
			{
				scanf("%d",&cid);
				switch(company[cid].sign)
				{
					case 0:printf("Company %d is empty.\n",cid);break;
					case 1:printf("Lowest rate: %lld.\n",company[cid].lowest_rate);break;
					case -1:
					{
						int temp = find(cid);
						printf("Company %d is a part of Company %d.\n",cid,temp);break;
					}
				}
			}
			else if(strcmp(s,"AP")==0)
			{
				scanf("%d%d",&trate,&cid);
				if(company[cid].sign!=-1)
				{
					if(company[cid].sign==0)
					{
						company[cid].sign=1;
						company[cid].blong = cid;
					//	company[cid].belong1 =&backup[cid];
					//	company[cid].belong = &company[cid].belong1;
					}
					printf("Accept\n");
					company[cid].sign=1;
					if(company[cid].lowest_rate>trate)//????
						company[cid].lowest_rate=trate;
				}
				else printf("Reject\n");
			}
			else
			{
				int a1,a2;
				scanf("%d%d",&a1,&a2);
				if(company[a1].sign!=-1)
				{
					if(company[a2].sign!=-1)
					{
						printf("Accept\n");
						company[a2].sign=-1;
						if(company[a1].sign==0)
						{
//							backup[a1]=a1;
							company[a1].sign=1;
							company[a1].blong=a1;
					//		company[a1].belong1=backup+a1;
					//		company[a1].belong = &company[a1].belong1;
						}
						if(company[a1].lowest_rate>company[a2].lowest_rate)
							company[a1].lowest_rate=company[a2].lowest_rate;
						company[a2].blong = company[a1].blong;
				//		printf("%d %d\n",company[a2].belong,company[a1].belong);
					}
					else printf("Reject\n");
				}
				else printf("Reject\n");
			}
		}
	}
	return 0;
}
