#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
struct ss
{
	double x,y;
	int sign;
};
bool cmp(ss t1,ss t2)
{
return t1.sign>t2.sign;
}
ss a[20];
double flag[300000],map[20][20],b[20];
double dis(int i,int j)
{
return sqrt((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y));
}
int main()
{
int N;
while(scanf("%d",&N)!=EOF&&N)
{
for(int i=0;i<(1<<N);i++)
flag[i]=-1;
int sum=0;
for(int i=0;i<N;i++)
{
scanf("%lf%lf%d",&a[i].x,&a[i].y,&a[i].sign);
}
sort(a,a+N,cmp);
for(int i=0;i<N;i++)
for(int j=i+1;j<N;j++)
map[i][j]=map[j][i]=dis(i,j);

int k=N;
for(int i=0;i<N;i++)
{
if(a[i].sign) sum+=(1<<i);
else {k=i;break;} 
}

flag[sum]=0;
if(k==N) {printf("0.000000\n");continue;}
if(k<=1) {printf("No Solution\n");continue;}
for(int i=sum;i<(1<<N);i++)
{
if(flag[i]==-1) continue;
for(int j=k;j<N;j++)
{
if(i&(1<<j)) continue;
int nm=0;
for(int xx=0;xx<N;xx++)
{
if(i&(1<<xx))b[nm++]=map[xx][j];
} 
sort(b,b+nm);
int x=i+(1<<j);
if(flag[x]==-1||flag[x]>flag[i]+b[0]+b[1])
flag[x]=flag[i]+b[0]+b[1];
}
}
int xx=(1<<N)-1;
if(flag[xx]!=-1)
printf("%.6lf\n",flag[xx]);
else printf("No Solution\n");
}
}
