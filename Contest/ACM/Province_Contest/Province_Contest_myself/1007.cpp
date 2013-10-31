#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

#define N 11
#define M 11
#define P 11
#define S 21

struct People
{
	char s[S];
	int city;
	int country;
	People *next;
}person[N*M*P];
struct Belong
{
	People * start;
	People * end;
}becity[N];
Belong betry[N][M];
People *head,*end;
int tt;
int cityn,ctryn[N],sump;

void init(void)
{
	head=end=NULL;
	for(int i=0;i<N;i++)
	{
		becity[i].start=becity[i].end=NULL;
		for(int j=0;j<M;j++)
			betry[i][j].start=betry[i][j].end=NULL;
	}
	printf("Scenario #%d\n",tt++);
}

bool cmp(People a,People b)
{
	if(strcmp(a.s,b.s)<0)
		return 1;
		return 0;
}

int find(char s[])
{
	int l=0;
	int r=sump;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(strcmp(person[mid].s,s)==0)
			return mid;
		else if(strcmp(person[mid].s,s)<0)
			l=mid+1;
		else r=mid-1;
	}
	return -1;
}

int main()
{
	tt=1;
	int a,b;
	char s[S];
	while(scanf("%d",&cityn)!=EOF)
	{
		sump=0;
		init();
		for(int i=0;i<cityn;i++)
		{
			scanf("%d",&ctryn[i]);
			for(int j=0;j<ctryn[i];j++)
			{
				scanf("%d",&a);
				for(int k=0;k<a;k++)
				{
					scanf("%s",person[sump].s);
					person[sump].city=i;
					person[sump].country=j;
					person[sump].next=NULL;
					sump++;
				}
			}
		}
		sort(person,person+sump,cmp);
/*		for(int i=0;i<sump;i++)
			printf("%s\n",person[i].s);*/
		scanf("%d",&a);
		for(int i=0;i<a;i++)
		{
			scanf("%s",s);
		//	printf("hei end:%s\n",end->s);
			if(strcmp(s,"in")==0)
			{
				scanf("%s",s);
				int id=find(s);
	//			printf("%d\n",id);
//				system("pause");
				int cid=person[id].city;
				int trid=person[id].country;
				if(head==NULL)
				{
					end=head=&person[id];
					betry[cid][trid].start=head;
					betry[cid][trid].end=head;
					becity[cid].start=head;
					becity[cid].end=head;
				}
				else
				{
					if(betry[cid][trid].start==NULL)
					{
						if(becity[cid].start==NULL)
						{
							betry[cid][trid].start=&person[id];
							betry[cid][trid].end=&person[id];
							becity[cid].start=&person[id];
							becity[cid].end=&person[id];
							(end->next)=&person[id];
							end=&person[id];
						}
						else
						{
							betry[cid][trid].start=&person[id];
							betry[cid][trid].end=&person[id];
							person[id].next=(becity[cid].end)->next;
							(becity[cid].end)->next=&person[id];
							end->next=&person[id];
							if(end==becity[cid].end)
								end=&person[id];
							becity[cid].end=&person[id];
						}
					}
					else
					{
						person[id].next=(betry[cid][trid].end)->next;
						(betry[cid][trid].end)->next=&person[id];
						end->next=&person[id];
						if(end==betry[cid][trid].end)
							end=&person[id];
						betry[cid][trid].end=&person[id];
						becity[cid].end=&person[id];
					}
				}
			}
			else 
			{
				scanf("%d",&b);
				People *tmp=head;
				int cnt=0;
				while(tmp!=NULL&&cnt<b)
				{
					printf("%s\n",tmp->s);
					if(tmp==betry[tmp->city][tmp->country].start)
					{
						People *next=tmp->next;
						if(next!=NULL)
						{
							if(next->city==tmp->city)
							{
								if(next->country==tmp->country)
									betry[tmp->city][tmp->country].start=next;
								else becity[tmp->city].start=next;
							}
							else 
							{
								betry[next->city][next->country].start=NULL;
								becity[next->city].start=NULL;
							}
						}
					}
					if(tmp==betry[tmp->city][tmp->country].end)
					{
						betry[tmp->city][tmp->country].start=NULL;
						betry[tmp->city][tmp->country].end=NULL;
					}
					if(tmp==becity[tmp->city].end)
					{
						becity[tmp->city].start=NULL;
						becity[tmp->city].end=NULL;						
					}
					tmp=tmp->next;
					cnt++;
				}
				head=tmp;
			}
		}
		printf("\n");
	}
	return 0;
}
