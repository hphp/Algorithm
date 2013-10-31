#include <stdio.h>
#define abss(a) ((a)>0 ? (a):(-(a)))

char sign[3] = {"AB"};
 
int main()
{
	int a,b,c;
	int test;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d %d %d",&c,&a,&b);
		int flag = 0;
		if(abss(c-a) > abss(c-b))
			flag = 1-flag;
			printf("%c\n",sign[flag]);
	}	
	return 0;
}
