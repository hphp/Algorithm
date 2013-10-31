#include <stdio.h>
#include <string.h>
#define S 210
#define M 34

char s[S];
int mins;

int fg(char * s,int m)
{
	int size = m;
	int ans = 0;
	for(int i=0;i<size;i++)
	{
/*		if(s[i] == '-')
			ans += ('-'-'A');//%(mins+44);
		else*/
			ans += (s[i]-'A');//%(mins+44));
//		ans  %= (mins+44); 
	}
	return ans%(mins+44);
}

int n,m;
char dic[M][S];
int fgrec[M],ss[M];

int exist[S];

int main()
{
//	printf("%d\n",'a'-'A');
	int n;
//	while(scanf("%d",&n)!=EOF)
	int tt = 0;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		mins = S;
		for(int i=0;i<n;i++)
		{
			scanf("%s",dic[i]);
			ss[i] = strlen(dic[i]);
			if(ss[i] < mins)
				mins = ss[i];
		}
		for(int i=0;i<S;i++)
			exist[i] = 0;
		for(int i=0;i<n;i++)
		{
			int st = ss[i] - m;
			fgrec[i] = fg(dic[i]+st,m);
			exist[fgrec[i]] = 1;
		}
		scanf("%s",s);
		int size = strlen(s);
		int st = 0;
		int cnt = 0;
		while(st < size)
		{
			if(st + m > size)
				break;
			int cur = fg(s+st,m);
		//	printf("%d\n",cur);
			int flag = 0;
			if(exist[cur] == 1)
				flag = 1;
			st = st + m ;
			if(flag == 1)
			{
				cnt ++;
				st ++;
				continue;
			}
			st += cur%3;
//			printf("%d\n",fg(s,mins));
		}
//		if(tt)printf("\n");
		printf("Scenario #%d\n%d\n\n",++tt,cnt);
	}
	return 0;
}
