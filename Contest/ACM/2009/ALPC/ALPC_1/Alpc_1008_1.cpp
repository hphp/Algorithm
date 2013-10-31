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
	int * belong;
}company[N];
int n,k,m;

void init(void)
{
	for(int i=0;i<n;i++)
	{
		company[i].sign=0;
	company[i].lowest_rate=MAX;
company[i].belong =NULL;
	}
	printf("%d\n",company[0].lowest_rate);
}

int main()
{
	while(scanf("%d%d%d",&n,&k,&m)!=EOF)
	{
		init();
		for(int i=1;i<=k;i++)
		{
			scanf("%lld%d",&member[i].rate,&member[i].belong);
			int cid=member[i].belong;
			backup[cid]=cid;
			company[cid].belong=&backup[cid];
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
						int temp = * company[cid].belong;
						printf("Company %d is a part of Company %d.\n",cid,temp);break;
					}
				}
			}
			else if(strcmp(s,"AP")==0)
			{
				scanf("%d%d",&trate,&cid);
				if(company[cid].sign!=-1)
				{
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
							backup[a1]=a1;
							company[a1].belong=&backup[a1];
						}
						company[a2].belong = company[a1].belong;
					}
					else printf("Reject\n");
				}
				else printf("Reject\n");
			}
		}
	}
	return 0;
}

