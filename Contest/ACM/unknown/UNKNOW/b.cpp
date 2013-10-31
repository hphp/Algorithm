#include <stdio.h>
#include <string.h>
#define N 21
#define L 27
#define Q 100010

struct Trie
{
	int value;
	int count;
	Trie * father;
	Trie * son[26];
}backup[N*Q];

Trie * start[N][L][Q]={NULL};
Trie * root=NULL;
int n,length,size,tt,m;
char s[N];
int cnt[N][L];

void init(void)
{
	tt=0;
	for(int i=0;i<N;i++)
		for(int j=0;j<L;j++)
			for(int k=0;k<Q;k++)
			start[i][j][k]=NULL;
	backup[tt].father=NULL;
	for(int i=0;i<26;i++)
	backup[tt].son[i]=NULL;
	root = &backup[tt++];
}

void push(char s[])
{
	int size=strlen(s);
	if(size>length)
		length=size;
	Trie * curp = root;
	for(int i=0;i<size;i++)
	{
		if(curp->son[s[i]-'a']==NULL)
		{
			backup[tt].father=curp;
			for(int j=0;j<26;j++)
			backup[tt].son[j]=NULL;
			backup[tt].count=1;
			backup[tt].value=s[i]-'a';
			curp->son[s[i]-'a']=&backup[tt];
			//if(cnt[i][s[i]-'a']==Q-1)
			//	Trie *newer = memset(sizeof(*Trie));
	//			start[i][s[i]-'a'][cnt[i][s[i]-'a']]=newer;
			start[i][s[i]-'a'][cnt[i][s[i]-'a']++]=&backup[tt++];
		}
		else
		{
//			printf("%s %d\n",s,i);
			curp->son[s[i]-'a']->count++;
		}
		curp=curp->son[s[i]-'a'];
	}
/*	if(start[cur][value]==NULL)
	{
		backup[tt].value=value;
		backup[tt]
		start[cur][value]	=&backup[tt++];
	}*/
}

int find(char s[],int pos)
{
	int size=strlen(s);
	int anss=0;
	for(int i=0;i<cnt[pos][s[0]-'a'];i++)
	{
	Trie * curp=start[pos][s[0]-'a'][i];
	if(curp==NULL)
		continue;
	int ans=curp->count;
	for(int i=1;i<size;i++)
	{
		if(curp->son[s[i]-'a']==NULL)
			break;
		curp=curp->son[s[i]-'a'];
		if(curp->count<ans)
			ans=curp->count;
	}
	anss+=ans;
	}
	return anss;
}

int main()
{
	scanf("%d",&n);
	init();
	for(int i=0;i<n;i++)
	{
		scanf("%s",s);
		push(s);
	/*	size= strlen(s);
		for(int j=0;j<size;j++)
		{
			push(j,s[j]-'a');
		}*/
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%s",s);
		int count=0;
		for(int j=0;j<length;j++)
		{
			int temp = find(s,j);
				count+=temp;
		}
		printf("%d\n",count);
	}
	return 0;
}
