#include <stdio.h>
#include <string.h>
#define N 31
#define S 42

char dic[N][S],s[300];
int size,minlen,ssize[N]; 
int lastm[N],n,m;

int cal(char a[],int start,int to)
{
	if(start>=0&&start<=to)
	{
		int sum=0;
		for(int i=start;i<=to;i++)
			sum+=a[i]-'A';
		return (sum%(minlen+44));
	}
	if(to>=size)
		return -2;
	return -1;
}

int main()
{
	int tt=1;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		minlen=300;
		for(int i=0;i<n;i++)
		{
			scanf("%s",dic[i]);
			ssize[i]=strlen(dic[i]);
			if(minlen>ssize[i])
				minlen=ssize[i];
		}
		for(int i=0;i<n;i++)
		{
			lastm[i]=cal(dic[i],ssize[i]-m,ssize[i]-1);
		//	printf("%d ",lastm[i]);
		}
	//	printf("%d\n",minlen);
		scanf("%s",s);
		size=strlen(s);
		int count=0;
		int cur=0;
		while(cur<size)
		{
			if(cur+m-1>=size)
				break;
			int fg=cal(s,cur,cur+m-1);
//			printf("%d %d\n",cur,fg);
			int i=0;
			for(;i<n;i++)
				if(fg==lastm[i])
					break;
			if(i<n)
			{
				count++;
				cur=cur+m+1;
			}
			else
				cur=cur+m+fg%3;
		}
		printf("Scenario #%d\n%d\n\n",tt++,count);
	}
	return 0;
}
