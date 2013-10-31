#include<cstdio>
#include<cstring>

char a[100001], b[100001];

int lim, mark;

void getNext(char a[])
{
	int i, j, k, len;
	len = strlen(a);
	j = 0; k = -1;
	for(i = 1; i < len; i ++)
	{
		if(a[i] > a[j])
		{
			break;
		}
		else if(a[i] == a[j])
		{
			if(k == -1)k = i;
			j ++;
		}
		else {
			k = -1;
			j = 0;
		}
	}
	if(k == -1)k = i;
	lim = k;
}

void KMP(char a[], char b[])
{
	int i, j, k, len;
	len = strlen(a);
	getNext(b);
	j = 0; k = -1;
	for(i = 0; i < len; i ++)
	{
		if(a[i] > b[j])
		{
			break;
		}
		else if(a[i] == b[j])
		{
			if(k == -1)k = i;
			j ++;
			if(j == lim){
				k = -1;
				j = 0;
			}
		}
		else {
			k = -1;
			j = 0;
		}
	}
	if(k == -1)k = i;
	for(i = 0; i < k; i ++)
	{
		putchar(a[i]);
	}
	printf("%s", b);
	puts(a+i);
}

int main()
{
	while(scanf("%s %s", a, b)!=EOF)
	{
		KMP(a, b);
	}
	return 0;
}
