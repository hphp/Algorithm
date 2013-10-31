#include <stdio.h>

int main()
{
	char a[23],b;
	while(scanf("%s",a)!=EOF)
	{
		printf("%d\n",a[0]-'A');	
	}
	return 0;
}
