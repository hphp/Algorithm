#include <stdio.h>
//#include <algorithm>
//using namespace std;
#define N 51
#define M 1019
#define HI 610

int counting[HI];
int count[HI];
int lowest[N];
struct Eny
{
	int start;
	int hi;
	int abs;
}eny[M];
int n,m,maxmax;

int Max(int a,int b)
{
	return a>b?a:b;
}

void arrange(int a[],int num)
{
	for(int i=0;i<num;i++)
		for(int j=0;j<num-i-2;j++)
		{
			if(a[j]>a[j+1])	
			{
				int temp = a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
}

void dealing(void)
{
	maxmax=0;
	for(int i=1;i<=HI;i++)
	{
		for(int j=0;j<m;j++)
			if(eny[j].start==i)
				counting[eny[j].hi]++;
		for(int j=0;j<n;j++)
		{
			int flag=0;
			for(int k=lowest[j];k<0;k++)
			{
				if(count[-k])	
				{
					flag=1;
					count[-k]--;
					maxmax++;
				}
			}
			if(flag==0)
			for(int k=Max(lowest[j],0);k<HI;k++)
				if(counting[k])
				{
					counting[k]--;
					maxmax++;
					break;
				}
		}
		for(int j=-HI+1;j<0;j++)
		{
			count[-j]=count[-j+1];
		}
		for(int j=0;j<HI-1;j++)
			counting[j]=counting[j+1];
	}
}

int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=0;i<n;i++)
			scanf("%d",&lowest[i]);
		arrange(lowest,n);
		/*for(int i=0;i<n;i++)
			printf("%d ",lowest[i]);
			printf("\n");*/
		for(int i=0;i<HI;i++)
			count[i]=counting[i]=0;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&eny[i].start,&eny[i].hi);
			eny[i].abs = eny[i].start-1+eny[i].hi;
/*			if(eny[i].start==1)
			counting[eny[i].abs]++;*/
		}
		dealing();
		printf("%d\n",maxmax);
	}
	return 0;
}
