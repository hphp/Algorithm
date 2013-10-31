#include <stdio.h>
#include <stdlib.h>
#include <map>
#define MAX 10000000000LL
#define abss(a) ((a)>0 ? (a):(-(a)))
using namespace std;
typedef long long Int;
map<Int,int> exist;
map<Int,int> ee;
#define N 900001
Int ans[N] = {0};
int des[20] = {0},ori[20];
int cnt;
Int a,b;
bool test(int [],int);
bool testNum(Int num)
{
	int rr[20];
	int cc = 0;
	while(num)
	{
		rr[cc++] =	num%10;
		num/=10;
	}
	int dess[20];
	int ccc = 1;
	while(cc)
		dess[ccc ++] = rr[--cc];
	if(test(dess,ccc-1))
		return 1;
	return 0;
}

bool test(int dess[],int size)
{
	int des[20];
	for(int i=0;i<20;i++)
		des[i] = dess[i];
	int temp[20];
	while(size > 1)
	{
		for(int i=1;i<size;i++)
			temp[i] = abss(des[i]-des[i+1]);
		size--;
		for(int i=1;i<=size;i++)
			des[i] = temp[i];
	}
	if((size == 1) &&(des[1] == 7))
		return 1;
	return 0;
}
void dfs(int so,int ori[],int des[],int po,int pd)
{
	if(so > 9)
		return;
	if(po > so)
	{
		Int sum = 0;
		for(int i=1;i<pd;i++)
		{
			sum*=10,sum+=des[i];
		}
		if(sum > 1000000000LL)return;
		/*	if(!test(des,pd-1))
			{
			for(int i=1;i<pd;i++)
			printf("%d",des[i]);
			printf("hei %lld\n",sum);
			int c;
			scanf("%d",&c);
			}*/
//		if(testNum(sum))
		if(des[1])
		{
			if(!exist[sum])
			{
				exist[sum] = 1;
				//	printf("%lldLL,",sum);
				ans[cnt] = sum;
				cnt ++;
			}
		}
		int cc = 1;
		{
			for(int j=0;j+pd<10;j++)
			{
				if(ee[j*MAX+sum])continue;
				ee[j*MAX+sum] = 1;
				for(int i=9;i>0;i--)
				{
					int rori[20],rdes[20];
					for(int k=0;k<20;k++)
						rori[k] = ori[k], rdes[k] = des[k];
					for(int k=1;k<=j;k++)
						ori[k] = 0;
					for(int k=j+1;k<20;k++)
						ori[k] = rdes[k-j];
					des[1] = i;
					dfs(j+pd-1,ori,des,1,2);
					for(int k=0;k<20;k++)
						ori[k] = rori[k], des[k] = rdes[k];
				}
			}
		}
		return;
	}
	else
	{
		for(int i=9;i>=0;i--)
		{
			if(abss(i-des[pd-1]) == ori[po])
			{
				int rori[20],rdes[20];
				for(int k=0;k<20;k++)
					rori[k] = ori[k], rdes[k] = des[k];
				des[pd] = i;
				dfs(so,ori,des,po+1,pd+1);
				for(int k=0;k<20;k++)
					ori[k] = rori[k], des[k] = rdes[k];
			}
		}
	}
}

int main()
{
	ori[1] = 7;
	for(int j=0;j<9;j++)
	{
		if(ee[j*MAX+7])continue;
		ee[j*MAX+7] = 1;
		for(int i=9;i>0;i--)
		{
			int rori[20],rdes[20];
			for(int k=0;k<20;k++)
				rori[k] = ori[k], rdes[k] = des[k];
			for(int k=1;k<=j;k++)
				ori[k] = 0;
			ori[j+1] = 7;
			des[1] = i;
			dfs(j+1,ori,des,1,2);
			for(int k=0;k<20;k++)
				ori[k] = rori[k], des[k] = rdes[k];
		}
	}
	ans[cnt++] = 7;
//	printf("%d\n",cnt);
/*		for(Int i=100000000;i<500000000;i++)
		if((!exist[i])&&(testNum(i)))
		printf("%lld,",i);
		printf("woderful");*/
	while(scanf("%lld%lld",&a,&b)!=EOF)
	{
		int xcnt =0;
		for(int i=0;i<cnt;i++)
			if(ans[i])
				if((ans[i]>=a)&&(ans[i]<=b))
				{
					//printf("%lld ",ans[i]);
					xcnt++;
				}
		printf("%d\n",xcnt);
	}
	return 0;
}
