#include<stdio.h>

int t[30] = {12, 22, 9, 24, 0, 11, 25, 21, 4, 15, 18, 5, 14, 1, 23, 16, 6, 3, 20, 17, 8, 19, 13, 10, 2, 7};
int s[30];
char st[100];

int main()
{
	for (int i = 0; i < 26; i++)
	{
		s[t[i]] = i;
	} 
	while (gets(st))
	{
		for (int i = 0; st[i]; i++)
		{
			if (st[i] >= 'A' && st[i] <= 'Z')
			{
				st[i] = s[st[i] - 'A'] + 'A';
			}
			else if (st[i] >= 'a' && st[i] <= 'z')
			{
				st[i] = s[st[i] - 'a'] + 'a';
			}
		}
		puts(st);
	}
	return 0;
}
