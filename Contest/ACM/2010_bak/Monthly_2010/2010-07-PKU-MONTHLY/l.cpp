#include <stdio.h>
//#include<stdlib.h>
//#include <sort>
#include <algorithm>
#define N 1100
#define abss(a) ((a)<0?(-(a)):(a))

struct Rec
{
	int p[3];
}rp[N],p[N];
int n;

bool nott(Rec a , Rec b)
{
	int cnt =0;
	for(int i=0;i<3;i++)
	{
		if(a.p[i]!=b.p[i])
		{
			if(abss(a.p[i] - b.p[i]) != 1)
				return 1;
			cnt ++;
		}
	}
//	printf("%d\n",cnt);
	if(cnt > 1)
		return 1;
	return 0;
}

int mv[6][3] = {
				{0,0,1},
				{0,0,-1},
				{0,1,0},
				{0,-1,0},
				{1,0,0},
				{-1,0,0}
			};

bool find(int pp[3],int n)
{
	for(int i=0;i<n;i++)
	{int j=0;
		for(;j<3;j++)
		if(pp[j] != rp[i].p[j])
			break;
		if(j == 3)
			return 1;
	}
	return 0;
}

int main()
{
	int tc;
	scanf("%d",&tc);
	int tt = 1;
	while(tc--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d,%d,%d",&rp[i].p[0],&rp[i].p[1],&rp[i].p[2]);
//			for(int j=0;j<3;j++)
//				printf("%d ",rp[i].p[j]);
//			p[i] = rp[i];
		}
//		std::sort(p,p+n,cmp);
		int sum = 0;
		int i=0;
		for(;i<n;i++)
		{
			if(i > 0)
			{
				int flag = 0;
			for(int kk=0;kk<i;kk++)
				if(nott(rp[i],rp[kk])==0)
					flag ++;
			for(int kk=0;kk<i;kk++)
			{
				int jj=0;
				for(;jj<3;jj++)
				if(rp[i].p[jj] != rp[kk].p[jj])
					break;
				if(jj == 3)
				{
					flag = 0;
					break;
				}
			}
			if(flag < 1)break;
			}
			for(int j=0;j<6;j++)
			{
				int pp[3];
				pp[0] = rp[i].p[0] + mv[j][0];
				pp[1] = rp[i].p[1] + mv[j][1];
				pp[2] = rp[i].p[2] + mv[j][2];
				if(find(pp,i))
					sum -= 2;
			}
			sum += 6;
		}
		printf("%d ",tt++);
		if(i < n)
			printf("NO %d\n",i+1);
		else
		printf("%d\n",sum);
	}
}
