#include<iostream>
#include<algorithm>
using namespace std;
#define N 200110

typedef __int64 Int;
Int p[N],w[N],a[N],sum[N],b[N];
int n,k;
Int SUM(int i,int j)
{
	return sum[j]-sum[i-1];
}
int test()
{
	int i=1;
	while(a[i]<=0&&i<=n)
		i=i+1;
	return i;
}
void MLN_Point()
{
	for(int i=n;i>=1;i--)
	{
		p[i]=i;w[i]=a[i];
		while(p[i]<n&&w[i]<=0)
		{
			w[i]+=w[p[i]+1];
			p[i]=p[p[i]+1];	
		}	
	}
}

Int mxmx;
int lm,rm;
int flag = 0;
int m;

void Mslu()//计算长度不超过k的最大子段和 
{
	printf("%d\n",n);
	int mi=1,mj=1;
	Int ms=a[1];
	int i=test();
	if(i<n)
	{
		MLN_Point();
		int j=i;
		while(i<=n)
		{
			while(a[i]<=0&&i<=n) i++;
			j=max(i,j);
			while(j<n&&p[j+1]<i+k&&w[j+1]>0) j=p[j+1];
			if(SUM(i,j)==ms)
			{
				if(mi > i)
				{
					mi = i;
					mj = j;
				}
				else if(mi == i)
				{
					if(mj > j)	
						mj = j;
				}
			}
			if(SUM(i,j)>ms)
				mi=i,mj=j,ms=SUM(i,j);
			i++;
		}
	}
	if(mj > m)
		mj -= m;
	if(ms > mxmx)
	{
		mxmx = ms;
		lm = mi;
		rm = mj;	
	}
	flag = 1;
//	printf("ans = %d   i = %d   j = %d\n",ms,mi,mj);
}
int main()
{
	while(scanf("%d%d",&n,&k)!=EOF)
	{		
		sum[0]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%I64d",&a[i]);
			b[i] = a[i];
			sum[i]=sum[i-1]+a[i];
		}
		m = n;
		for(int i=n+1;i<=2*n;i++)
		{
			a[i] = a[i-n];
			sum[i] = sum[i-1]+a[i];
		}
		n*=2;
	/*	for(int i=1;i<=n;i++)
			printf("%I64d ",a[i]);
			printf("\n");*/
		mxmx = a[1];
		lm = 1;rm = 1;
		flag = 0;
		Mslu();
		printf("%I64d %d %d\n",mxmx,lm,rm);
/*		int cnt = 1;
		sum[0] = 0;
		for(int i=k;i<=n;i++)
		{
			a[cnt] = b[i];
			sum[cnt] = sum[cnt-1]+a[cnt];
			cnt ++;
		}
		for(int i=1;i<k;i++)
		{
			a[cnt] = b[i];
			sum[cnt] = sum[cnt-1]+a[cnt];
			cnt++;
		}
		Mslu();
		printf("%I64d %d %d\n",mxmx,lm,rm);*/
	}
}
