#include<iostream>
#include<algorithm>
#include<time.h>
using namespace std;
const int MAX = 510;
bool flag[MAX][MAX];
int main()
{
	freopen("A_in.in","w",stdout);
	srand((unsigned int)time(0));
	int N,M;
	N=5 , M=3;
	printf("5 3\n");
	printf("2 3 4 5 2\n");
	printf("1 5 3 6 4\n");
	printf("1 2 3\n2 3 5\n3 4 2\n");
	
	printf("6 4\n");
	printf("1 1 1 1 1 1\n");
	printf("1 2 1 2 3 4\n");
	printf("1 2 1\n2 3 1\n4 5 1\n3 6 1\n");
	for(int j=1;j<=5;j++)
	{
		memset(flag,false,sizeof(flag));
		N = rand()%30+20,M = rand()%100;
		printf("%d %d\n",N,M);
		for(int i=1;i<=N;i++)
			printf("%d%c",rand()%200+1,i==N?'\n':' ');
		for(int i=1;i<=N;i++)
			printf("%d%c",rand()%200+1,i==N?'\n':' ');
		for(int i=1;i<=M;i++)
		{
			int x=rand()%N+1,y=rand()%N+1;	
			while(x==y||flag[x][y])
			x=rand()%N+1,y=rand()%N+1;
			flag[x][y]=flag[y][x]=true;
			printf("%d %d %d\n",x,y,rand()%200+1);
		}
	}
	N=500,M=124750;
	printf("500 124750\n");
	for(int i=1;i<=N;i++)
		printf("%d%c",rand()%200+1,i==N?'\n':' ');
	for(int i=1;i<=N;i++)
		printf("%d%c",rand()%200+1,i==N?'\n':' ');
	for(int i=1;i<=N;i++)
		for(int j=1+i;j<=N;j++)
		printf("%d %d %d\n",i,j,rand()%200+1);
	for(int j=1;j<=5;j++)
	{
		memset(flag,false,sizeof(flag));
		N = rand()%200+300,M = rand()%10000;
		printf("%d %d\n",N,M);
		for(int i=1;i<=N;i++)
			printf("%d%c",rand()%200+1,i==N?'\n':' ');
		for(int i=1;i<=N;i++)
			printf("%d%c",rand()%200+1,i==N?'\n':' ');
		for(int i=1;i<=M;i++)
		{
			int x=rand()%N+1,y=rand()%N+1;	
			while(x==y||flag[x][y])
			x=rand()%N+1,y=rand()%N+1;
			flag[x][y]=flag[y][x]=true;
			printf("%d %d %d\n",x,y,rand()%200+1);
		}	
	}
}
