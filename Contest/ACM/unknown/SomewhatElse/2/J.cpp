#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define N 500010
#define M 94

int num[M];
int rec[M];
int stdd[M];
char s[N],ori[N];
int ans[N];

bool cmp(int a, int b)
{
	return a > b;	
}

int main()
{
	while(scanf("%s%s",s,ori)!=EOF)
	{
		int m = strlen(ori);
		for(int i=0;i<M;i++)
			stdd[i] = num[i] = 0;
		for(int i=0;i<m;i++)
			stdd[ori[i]-33]++;
		sort(stdd,stdd+M,cmp);
		int n = strlen(s);
		for(int i=0;i<m;i++)
		{
			num[s[i]-33]++;
		}
		for(int i=0;i<M;i++)
			rec[i] = num[i];
		sort(rec,rec+M,cmp);
		int diff = M;
		for(int i=0;i<M;i++)
			if(stdd[i] == 0)
				{ diff = i ; break;}
		int cnt = 0;
		int i=0;
		for(;i<M;i++)
			if(stdd[i]!=rec[i])break;
		if(i == M)
			ans[cnt++] = 0;
		int curd = M;
		for(int i=0;i<M;i++)
			if(rec[i] == 0){curd = i; break;}
		for(int i=m;i<n;i++)
		{
			if(s[i-m] == s[i])
			{
				if((cnt > 0) && (ans[cnt-1] == i-m))
					ans[cnt++] = i-m+1;
				continue;
			}
/*			for(int ii=0;ii<M;ii++)
				if(num[ii])
					printf("hello %d %d\n",ii,num[ii]);*/
//			printf("%d %d %d\n",i,curd,diff);
/*			for(int k=0;k<M;k++)
			{
				if(!(stdd[k]||rec[k]))break;
				printf("%d %d\n",stdd[k],rec[k]);
			}
				printf("\n%d hhh",i-m+1);*/
			if((num[s[i-m]-33]) == (num[s[i]-33]+1))
			{
				;
			}
			else
			{
				int j=0;
//				printf("%d %c %d %d\n",i,s[i-m],num[s[i-m]-33],rec[2]);
				for(j=M-1;j>-1;j--) 
					if(num[s[i-m]-33] == rec[j])
						break;
//				printf("google %d\n",j);
				int rec1 = j;
				for(j=0;j<M;j++)
					if(num[s[i]-33] == rec[j])
						break;
				rec[rec1]--;
				rec[j]++;
			}
			num[s[i-m]-33]--;
			if(num[s[i-m]-33]);
			else curd--;
			if(num[s[i]-33]==0)
				curd++;
			num[s[i]-33]++;
//			printf("%d %d %d\n",i,curd,diff);
			for(int k=0;k<M;k++)
			{
				if(!(stdd[k]||rec[k]))break;
//				printf("dddddd%d %d\n",stdd[k],rec[k]);
			}
//			printf("\n%d hhh\n",i-m+1);
/*			if(curd != diff)
				continue;
			if(s[i-m] == s[i])
			{
				ans[cnt++] = i-m+1;
//				printf("hei %d\n",ans[cnt-1]);
				continue;	
			}*/

/*			for(int j=0;j<M;j++)
				rec[j] = num[j];
			*/
//			sort(rec,rec+M,cmp);
			int j = 0;
			for(;j<diff;j++)
			{
				if(stdd[j]!=rec[j])
					break;
			}
			if(j == diff)
			{
				ans[cnt++] = i-m+1;
	//			printf("hei %d %d\n",i,ans[cnt-1]);
			}
		}
		if(cnt)
		{
			printf("Yes\n");
			for(int i=0;i<cnt;i++)
			{
				if(i)
					printf(" ");
					printf("%d",ans[i]);
			}
		}
		else printf("No");
		printf("\n");
	}
	return 0;
}
