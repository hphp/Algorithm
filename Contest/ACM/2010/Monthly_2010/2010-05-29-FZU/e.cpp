#include <stdio.h>
#include <string.h>
#include <algorithm>
#define N 210

using namespace std;

struct Node
{
	char a;	
}ch[2][N];

bool cmp(Node a , Node b)
{
return a.a < b.a;	
}

int main()
{
	int test;
	scanf("%d",&test);
	int tt = 1;
	int n;
	while(test--)
	{
		scanf("%d",&n);
		getchar();
		for(int i=0;i<n;i++)
		{
			scanf("%c",&ch[0][i].a);
			ch[1][i].a = ch[0][i].a;
		}
		getchar();
		std::sort(ch[0],ch[0]+n,cmp);
		int cnt = 0;
		for(int i=0;i<n;i++)
			if(ch[0][i].a != ch[1][i].a)
				cnt ++;
		printf("Case %d: %d\n",tt++,cnt);
	}
	return 0;
}
