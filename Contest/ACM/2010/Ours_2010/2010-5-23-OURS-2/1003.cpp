#include <stdio.h>
#include <string.h>
int k;

int getSHI(char s[])
{
	int size = strlen(s);
	int cur = 0;
	for(int i=0;i<size;i++)
	{
		cur *= 2;
		cur += s[i]-'0';
	}
	return cur;
}

int a[2];
void getOnes(int cur)
{
	a[0] = a[1] = 0;
	while(cur)
	{
		a[cur%2] ++;
		cur/=2;
	}
}

int main()
{
	char s[100];
	while(scanf("%s%d",s,&k)!=EOF)
	{
		int cur = getSHI(s);
		printf("%d\n",cur);
		int mul = cur/k;
		getOnes(cur);
		int cone = a[1] ;
		int czero = a[0] ;
		printf("%d %d\n",cone,czero);
		while(1)
		{
		//	if(mul*k >= cur)
			getOnes(mul*k);
			printf("%d %d\n",a[0],a[1]);
			if(a[1] >= cone && a[0] >= czero)
				break;
			mul ++;
		}
		printf("%d\n",mul);
	}
}
