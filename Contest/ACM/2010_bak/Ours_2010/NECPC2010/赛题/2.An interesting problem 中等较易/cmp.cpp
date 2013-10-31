#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char s[10005][100000];
char ss[100000];

int main()
{
	freopen("test.out","r",stdin);
	freopen("cmp.out","w",stdout);
	int i=0;
	while(scanf("%s", s[i++]) != EOF);
	freopen("out.out","r",stdin);
	i = 0;
	while(scanf("%s", ss) != EOF)
	{
		if(strcmp(ss, s[i++]) != 0)
		{
			printf("on my god\n");
			return 0;
		}
	}
	printf("ok\n");
}
