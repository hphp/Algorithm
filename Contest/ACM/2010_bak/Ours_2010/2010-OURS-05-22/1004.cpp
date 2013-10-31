#include <stdio.h>

int byte;


int div(int a,int b)
{
	return a/b + (a%b==0?0:1);	
}

int getAns()
{
	int cmp = div(byte,2);
	int code = cmp + div(cmp,2);
	return div(code,1860000);
}

int main()
{
	int tt = 1;
	while(scanf("%d",&byte)!=EOF)
	{
		if(!byte)break;
		int ans = getAns();
		printf("File #%d\nJohn needs %d floppies.\n\n",tt++,ans);
	}
	return 0;
}
