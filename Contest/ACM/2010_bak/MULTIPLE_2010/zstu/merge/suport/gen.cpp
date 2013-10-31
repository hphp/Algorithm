#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;
const int MAX=1000000000;
void swap(int &x,int &y)
{
	int t=x;
	x=y;
	y=t;
}
int main()
{
	int x,y,z,n;
	freopen("save.in","w",stdout);
	printf("1 2 3 4 1000000000\n");
	int T=10;
	int i,p=1;
	for(i=0;i<10;i++)
	{
		if(p<1000000000)
			p*=10;
		n=rand()*rand()%p+1;
		if(n<p/10)n+=p/10;
		x=rand()%20+1;
		y=rand()%20+1;
		z=rand()%20+1;
		if(y>z)swap(y,z);
		if(x>z)swap(x,z);
		if(x>y)swap(y,x);
		if(z==y)y--;
		if(y<x)x--;
		printf("%d %d %d %d\n",x,y,z,n);
	}
	return 0;
}
