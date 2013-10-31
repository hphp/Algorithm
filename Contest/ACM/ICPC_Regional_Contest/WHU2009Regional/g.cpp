#include <stdio.h>
#include <algorithm>
#define N 310
#define V1 510
#define V2 58

struct Stuff
{
	int c,v,flag;
}stuff[N];
int n;
int mx[V1][V2],rec[V1][V2];
int can[V2];
int v1,v2;

bool cmp(Stuff a,Stuff b)
{
	if(a.flag<b.flag)
		return 1;
	else if(a.flag>b.flag)
		return 0;
	else
	{
		if(a.c<b.c)
			return 1;
		else if(a.c>b.c)
			return 0;
		else if(a.v<b.v)
			return 0;
		else return 1;
	}
}

int main()
{
	int tt = 1;
	while(scanf("%d %d %d",&v1,&v2,&n)!=EOF)
	{
		if(!(v1||v1||n))break;
		for(int i=0;i<n;i++)	
		{
			scanf("%d %d %d",&stuff[i].c,&stuff[i].v,&stuff[i].flag);
		}
		std::sort(stuff,stuff+n,cmp);
/*		for(int i=0;i<n;i++)
			printf("%d ",stuff[i].v);
			printf("\n");*/
		int board = n;
		for(int i=0;i<n;i++)
		{
			if(stuff[i].flag==1)
			{
				board = i;break;
			}
		}
		int nvl = 0;
		int nc = 0;
		int tm = 0;
		for(int i=board;i<n;i++)
		{
			nc += stuff[i].c;
			nvl += stuff[i].v;
			if(stuff[i].c>tm)
				tm = stuff[i].c;
		}
		int mxmx =0;
		if(nc-tm>v1+v2)
			mxmx = -1;
		else
		{
			int i = 0;
			if(nc>v1+v2)
				i = board;

			for(;i<n;i++)
			{
				for(int k=0;k<=v2;k++)
					can[k] =0;
					can[0] =1;
				int flag =0;
				for(int j=board;j<n;j++)
				{
					if(j!=i)
					{
					for(int k=v2-stuff[j].c;k>=0;k--)
						if(can[k])
						{
							can[k+stuff[j].c]=1;
						}
					}
					else flag =1;
				}

				int okk = 0;

				for(int j=0;j<=v2;j++)
				{
					if(can[j])
					{
						int tv1 = nc-j;
						if(flag==1)
						{
							tv1 -= stuff[i].c;
						}
						int ii = v1-tv1;
						int jj = v2-j;
						if(ii>=0)
						{
							okk = 1;
							break;
						}
					}	
				}

				if (!okk)
					continue;

				int j=0;
				for(int k=0;k<=v1;k++)
					for(int m=0;m<=v2;m++)
					{mx[k][m] = rec[k][m] = 0;}

				int ttt = 0;
				bool flagging[V1*V2]  = {0};
				int exist[V1*V2];
				int cnt;
				exist[0] = 0;
				cnt =1;
				for(j=0;j<board;j++)
				{
					if(i == j)continue;
					if(stuff[j].c>v1)continue;
					for(int kk=cnt-1;kk>=0;kk--)
					{
						int k = exist[kk]/51;
						int m = exist[kk]%51;
							if(k+stuff[j].c<=v1&&mx[k][m]+stuff[j].v>mx[k+stuff[j].c][m])
							{
								if(flagging[(k+stuff[j].c)*51+m]==0)
								{
									flagging[(k+stuff[j].c)*51+m] = 1;
									mx[k+stuff[j].c][m] = mx[k][m]+stuff[j].v;
									exist[cnt++] =(k+stuff[j].c)*51+m ;
								}
							}
						if(m+stuff[j].c<=v2&&rec[k][m]+stuff[j].v>mx[k][m+stuff[j].c])
						{
							if(flagging[k*51+m+stuff[j].c]==0)	
							{
								flagging[k*51+m+stuff[j].c]	=1;
								exist[cnt++] = k*51+m+stuff[j].c;
								mx[k][m+stuff[j].c] = rec[k][m]+stuff[j].v;
							}
						}
					}
					std::sort(exist,exist+cnt);
					for(int kk=0;kk<cnt;kk++)
					{
						int k = exist[kk]/51;
						int m = exist[kk]%51;
						rec[k][m] = mx[k][m];
					}
					/*int k = v1;
					if (k > ttt)
						k  = ttt;
					for(;k>=0;k--)
					{
						int m = v2;
						if (m > ttt)
							m = ttt;
						for(;m>=0;m--)
						{
							if(k+stuff[j].c<=v1&&mx[k][m]+stuff[j].v>mx[k+stuff[j].c][m])
							{
								mx[k+stuff[j].c][m] = mx[k][m]+stuff[j].v;
							}
							if(m+stuff[j].c<=v2&&rec[k][m]+stuff[j].v>mx[k][m+stuff[j].c])
							{
								mx[k][m+stuff[j].c]= rec[k][m]+stuff[j].v;
							}
						}
					}

					ttt += stuff[j].c;

					for(int k=0;k<=ttt&&k<=v1;k++)
						for(int m=0;m<=ttt&&m<=v2;m++)
							rec[k][m] = mx[k][m];*/
				}
				int tnvl = nvl;
				if(flag==1)
					tnvl -= stuff[i].v;
				for(int j=0;j<=v2;j++)
				{
					if(can[j])
					{
					int tv1 = nc-j;
					if(flag==1)
					{
						tv1 -= stuff[i].c;
					}
					int ii = v1-tv1;
					int jj = v2-j;
					if(ii<0)
						continue;
					if(tnvl + stuff[i].v + mx[ii][jj]>mxmx)
						mxmx = tnvl + stuff[i].v + mx[ii][jj];
					}
				}
			}
		}
		if(mxmx == 0)
			mxmx = -1;
		printf("Case %d: %d\n\n",tt++,mxmx);
	}
	return 0;
}

