#include <stdio.h>
#include <string.h>
#define N 110

char MAX[N];
char Lmn[N][N][N],Rmn[N][N][N];
int n,k;
char s[N];

int main()
{
	int tc;
	for(int i=0;i<N;i++)
		MAX[i] = 'Z';
	MAX[N-1] = '\0';
	scanf("%d",&tc);
	for(int tt = 1; tt <= tc; tt ++)
	{
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		char t[N] = "";
		char t2[N] = "";
		char tmp[N] = "";
		for(int i=0;i<=n;i++)
			for(int j=0;j<=k;j++)
			{
				strcpy(Lmn[i][j],MAX);
				strcpy(Rmn[i][j],MAX);
			}
		Lmn[0][0][0] = '\0';
		Rmn[0][0][0] = '\0';
		for(int i=1;i<=n;i++)
		{
			strcpy(Lmn[i][0],s+1);
			int tt2 = 1,ttr = i-1;
			while(tt2<=i)
				Rmn[i][0][ttr--] = s[tt2++];
			Lmn[i][0][i] = '\0';
			Rmn[i][0][i] = '\0';
		}
		if(k > n)k = n;
		for(int i = 1; i <= n ; i ++)
		{
			for(int j=1;j<=k&&j<=i;j++)
			{
				strcpy(Lmn[i][j],Lmn[i][j-1]);
				strcpy(Rmn[i][j],Rmn[i][j-1]);
				/*
				   for(int kk=i,ii=1;kk>0;kk--)
				   {
				   Lmn[i][j][ii] = s[kk];
				   Rmn[i][j][ii] = s[ii];
				   }*/
				bool flag = 0;
				int sign = 0;
				strcpy(tmp,s+1);
				for(int kk=i-1;kk>=0;kk--)
				{
					int stmp = 0;
					int atmp = 0;
					int flag = 0;
					while(atmp < kk)
					{
						if(flag == 1)
						{
							flag = 1;
							Rmn[i][j][atmp] = Rmn[kk][j][atmp];
						}
						else
						{
							if(Rmn[i][j][atmp] > Rmn[kk][j][atmp])
							{
								flag = 1;
								Rmn[i][j][atmp] = Rmn[kk][j][atmp];
							}
							else if(Rmn[i][j][atmp] < Rmn[kk][j][atmp])
							{
								break;
							}
						}
						atmp ++;
					}
					if(flag)
					{
						atmp = kk+1;
						while(stmp < i)
							Rmn[i][j][stmp ++] = s[atmp++];
						Rmn[i][j][stmp] = '\0';
					}
					stmp = 0;
					atmp = 0;
					while(stmp < i && atmp < kk)
						t[stmp++] = Lmn[kk][j][atmp++];
					atmp = kk+1;
					while(stmp < i)
						t[stmp ++] = s[atmp++];
					t[stmp] = '\0';
					if(strcmp(t,Lmn[i][j]) < 0)
						strcpy(Lmn[i][j],t);
					stmp = 0;
					atmp = i;
					while(stmp < i && atmp > kk)
						t[stmp++] = s[atmp--];
					atmp = 0;
					while(stmp < i && atmp < kk)
						t[stmp++] = Rmn[kk][j-1][atmp++];
					t[stmp] = '\0';
					if(strcmp(t,Lmn[i][j]) < 0)
						strcpy(Lmn[i][j],t);
					stmp = 0;
					atmp = 0;
					while(stmp < i && atmp < kk)
					{
						tmp[stmp] = Lmn[kk][j-1][atmp];
						stmp ++;
						atmp ++;
					}
					atmp = kk+1;
					while(stmp<i && atmp <= i)
					{
						tmp[stmp] = s[atmp];
						stmp++;
						atmp++;
					}
					tmp[stmp] = '\0';
					if(strcmp(tmp,Rmn[i][j]) < 0)
						strcpy(Rmn[i][j],tmp);
					t[i-kk] = s[kk]; 
					/*
					   int tmpo = kk;
					   int tmpn = 1;
					   while(tmpn >= 0)
					   {
					   if(Rmn[kk][j-1][tmpn] < s[tmpo])
					   {
					   if(flag)break;
					   strcpy(,Rmn[kk][j-1]+tmpn);
					   frm[]
					   break;
					   }
					   else if(Rmn[kk][j-1][tmpn] > s[tmpo])
					   break;
					   }
					   if(flag)break;*/
				}
				//				printf(" %d %d %s %s\n",i,j,Rmn[i][j],Lmn[i][j]);
			}
		}
		printf("Case %d: %s\n",tt,Lmn[n][k]);
	}
}
