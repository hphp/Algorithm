#include <stdio.h>
#define N 110
int rec[N];
char s[N];
int main()
{
	int tc;
	scanf("%d",&tc);
	int ttt = 1;
	while(tc--)
	{
		scanf("%s",s);
		int hour = (s[0]-'0')*10 + (s[1]-'0');
		int minu = (s[3]-'0')*10 + (s[4]-'0');
		int sec = (s[6]-'0')*10 + (s[7]-'0');
		int cnt = 5;
	//	printf("%d %d %d\n",hour,minu,sec);
		for(int i=0;i<18;i++)
			rec[i] = 0;
		int t = hour;
		while(t)
		{
			rec[cnt] = t%2;
			t/=2;
			cnt --;
		}
		cnt = 11;
		t = minu;
		while(t)
		{
			rec[cnt] = t%2;
			t/=2;
			cnt --;
		}
		cnt = 17;
		t = sec;
		while(t)
		{
			rec[cnt] = t%2;
			t/=2;
			cnt --;
		}
		printf("%d ",ttt++);
		int aa = 0,bb=6,cc=12;
		for(int i=0;i<6;i++)
		{
			printf("%d%d%d",rec[aa],rec[bb],rec[cc]);
			aa ++;bb ++;cc++;
		}
		printf(" ");
		for(int i=0;i<18;i++)
			printf("%d",rec[i]);
		printf("\n");
	}
}
