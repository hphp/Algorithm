/*
ID: hanjiatong1
PROG: calfflac
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#define N 20010
#define blg(a,b,c) (((a)>=(b)&&(a)<=(c))?1:0)
#define avl(a) (((a)>=0&&(a)<size)?1:0)
#define Max(a,b) ((a)>(b)?(a):(b))

char s[N];
using namespace std;

int cnt = 0,size;
int rec[N];

int equal(char a,char b)
{
	char c,d;
	if(blg(a,'a','z'))
		c = a;
	else c = a-'A'+'a';
	if(blg(b,'a','z'))
		d = b;
	else d = b-'A'+'a';
	return c==d;
}

int MaxSymmetry(int rm,int lm)
{
	int ans = 0;
	int rr = lm-rm-1;
	while(avl(rm) && avl(lm) && equal(s[rec[rm]],s[rec[lm]]))
	{
		ans ++;
		rm --;
		lm ++;	
	}
	return ans*2+rr;
}

int main() {
	
//   ofstream fout ("calfflac.out");
//    ifstream fin ("calfflac.in");
    
    FILE * fin = fopen("calfflac.in","r");
    FILE * fout = fopen("calfflac.out","w");

    
    size = 0;
    while(fgets(s+size, 80 , fin) != NULL)
	{
		size = strlen(s);
	}
	cnt = 0;
	for(int i=0;i<size;i++)
	{
		if(blg(s[i],'a','z')||blg(s[i],'A','Z'))
		{
			rec[cnt++] = i;	
		}
	}
/*	for(int i=0;i<cnt;i++)
		fprintf(fout,"%c",s[rec[i]]);
		fprintf(fout,"\n");*/
	int ans = 1;
	int st = 0;
	int ed = 0;
	for(int i=0;i<cnt;i++)
	{
		if(ans < MaxSymmetry(i,i+1))
		{
			ans = MaxSymmetry(i,i+1);
			st = i - ans/2 + 1;
			ed = i + ans/2 ;
		}
		if(ans < MaxSymmetry(i,i+2))
		{
			ans = MaxSymmetry(i,i+2);
			st = i - ans/2 + 1;
			ed = i + ans/2 + 1;
		}
	}
	fprintf(fout,"%d\n",ans);
	for(int i=rec[st];i<=rec[ed];i++)
		fprintf(fout,"%c",s[i]);
		fprintf(fout,"\n");
    return 0;
}

/*

智慧周  21:41:21
FILE *file = fopen("in.txt", "r");
智慧周  21:41:28
打开一个文件
智慧周  21:41:37
只读打开一个文件
智慧周  21:42:01
FILE *file = fopen("out.txt", "w");
只写打开一个文件
智慧周  21:43:31
从文件读
fscanf(file, "%d", &n);

char *fgets(char *s, int n, FILE *stream);
　　从流中读取n-1个字符，除非读完一行，参数s是来接收字符串，如果成功则返回s的指针，否则返回NULL。
　　
智慧周  21:43:58
fprintf(file, "%d", n)

*/
