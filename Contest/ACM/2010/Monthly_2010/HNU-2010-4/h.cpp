#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 1000

char s[N];
char tran[N]={
'e','n','y','r','i','l',
//a,b,c,d,e,f
'q','z','u','c','x','f',
//g,h,i,j,k,l
'a','w','m','j','p','t',
//m,n,o,p,q,r
'k','v','s','h','b','o',
//s,t,u,v,w,x
'd','g'
//y,z
};

int main()
{
//	freopen("h.in","r",stdin);
//	freopen("h.out","w",stdout);
	while(gets(s))
	{
		int size = strlen(s);
		for(int i=0;i<size;i++)
		{
			if(s[i]>='a'&&s[i]<='z')
			printf("%c",tran[s[i]-'a']);
			else if(s[i]>='A'&&s[i]<='Z')
			printf("%c",tran[s[i]-'A']-'a'+'A');
			else printf("%c",s[i]);
		}
		printf("\n");
	}
}
