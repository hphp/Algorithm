#include <stdio.h>

int main()
{
	char s[1000];
	int a, b, c;
	while (scanf("%s", s) != EOF)
	{
		a = b = c = 0;
		int i = 0;
		while (s[i]=='O')
		{
			a++;
			i++;
		}
		if (s[i] != 'Z')
			goto wrong;
		i++;
		
		while (s[i]=='O')
		{
			b++;
			i++;
		}
		if (s[i] != 'J')
			goto wrong;
		i++;
		
		while (s[i]=='O')
		{
			c++;
			i++;
		}
		if (s[i] != '\0')
			goto wrong;
		
		if (a+b==c && b>=1)
			goto yes;
		else
			goto wrong;
	wrong:
		printf("Wrong Answer\n");
		continue;
	yes:
		printf("Accepted\n");
		continue;			
	}
}
