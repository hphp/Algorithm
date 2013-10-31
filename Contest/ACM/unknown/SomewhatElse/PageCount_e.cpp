#include <stdio.h>
#include <string.h>
#define number(a) ((((a)>='0') && ((a)<='9'))?1:0)
#define hy(a) (((a)=='-')?1:0)
#define S 101000

char s[S];
char rs[S];
int sign[S];
int main()
{
	int page;
	while(scanf("%d",&page)!=EOF)
	{
		if(!page)break;
		for(int i=0;i<=page;i++)
			sign[i] = 0;
		getchar();
		gets(s);
		int c = 0;
		int size = strlen(s);
		int cc = 0;
		while(c <= size)
		{
			if((s[c] == ',')||(c == size))
			{
				rs[cc] = '\0';
			//	printf("%s\n",rs);
				int r[2] = {0};
				int cur =0;
				for(int k=0;k<cc;k++)
				{
					if(rs[k] == '-')
					{
						cur++;
					}
					else
					{
						if(number(rs[k]))
						{
							r[cur] *= 10;
							r[cur] += (rs[k]-'0');
						}
					}
				}
				if(cur == 0)
					r[1] = r[0];
		//		printf("hi %d %d\n",r[0],r[1]);
				if(r[0] <= r[1])
				{
					for(int i=r[0];(i<=r[1])&&(i<=page);i++)
						sign[i] = 1;
				}
				cc = 0;
			}
			else if(number(s[c]) || hy(s[c]))
			{
				rs[cc++] = s[c];
			}
			c ++;
		}
		int ans = 0;
		for(int i=1;i<=page;i++)
			if(sign[i])
				ans ++;
		printf("%d\n",ans);
	}
	return 0;
}
/*

2011-01-23
-16:04
1
1   2 - 23  , 1-2,1
20
1   2 - 23  , 1-2,
-16:15 AC.
*/

