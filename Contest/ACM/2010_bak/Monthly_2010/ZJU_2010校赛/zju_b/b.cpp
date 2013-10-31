#include <stdio.h>
#include <string.h>

char arr[52][7][17];
char s[18];

int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	int pos = 0;
	int rec = pos;
	while(rec<26)
	{
		for(int row=0;row<7;row++)
		{
			pos = rec;
			int end = 6;
			for(int j=0;j<end&&pos<26;j++)
			{
				scanf("%s",s);
//				printf("%s ",s);
				int size = strlen(s);
				for(int i=0;i<size;i++)
				{
					int flag = 0;
					arr[pos][row][i] = s[i];
				}
				arr[pos][row][size] = '\0';
				pos++;
			}
//			printf("\n");
		}
		rec = pos;
	}
	printf("\n");
	printf("{\n");
	for(int i=0;i<rec;i++)
	{
		printf("\t{\n");
		for(int j=0;j<7;j++)
		{
			printf("{\"");
			for(int k=0;k<16;k++)
				printf("%c",arr[i][j][k]);
			printf("\"");
			printf("}");
			if(j!=6)
			printf(",");
			printf("\n");
		}
		printf("\n\t},\n");
		printf("\n");
	}
	printf("}\n");
	return 0;
}
