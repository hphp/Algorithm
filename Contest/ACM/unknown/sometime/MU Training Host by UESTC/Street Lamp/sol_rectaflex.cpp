#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<time.h>
using namespace std;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
#define MOD 1000000007
#define INF 999999999

char map[205][25];
int N,M;
bool is_in(int x,int y)
{
	if(x<0||x>=2*N-1||y<0||y>=2*M-1)
		return 0;
	return 1;
}

int s_r[210];
int nxt_r[210];
int row;
struct L
{
	int s;//记录开关的状态
	int cnt;
	int next;
}lp[2][2000];
int head[2][1050],top[2];
int r[220][12];
int change(int s,int c)//灯的状态，开关的状态
{
	int ret=s;
	for(int i=0;i<M;i++)
		if(  c&(1<<i) )
			ret^=r[row][i];
	return ret;
}
void insert(int w,int l,int c,long long cnt)//开关状态，灯的状态
{
	lp[c][top[c]].s=w;
	lp[c][top[c]].next=head[c][l];
	lp[c][top[c]].cnt=cnt;
	head[c][l]=top[c];
	top[c]++;
}
void update(int w,int l,int c,int cnt)
{
	int i;
	for(i=head[c][l];i!=-1;i=lp[c][i].next)
	{
		if(lp[c][i].s==w)
		{
			//lp[c][i].cnt=(lp[c][i].cnt+cnt)%MOD;
			if(cnt<lp[c][i].cnt)
				lp[c][i].cnt=cnt;//修改最小值
			break;
		}
	}
	if(i==-1)
		insert(w,l,c,cnt);
}
int cal_one(int x)
{
	x = (x & 0x55555555) + ((x >> 1) & 0x55555555);
	x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
	x = (x & 0x0F0F0F0F) + ((x >> 4) & 0x0F0F0F0F);
	x = (x & 0x00FF00FF) + ((x >> 8) & 0x00FF00FF);
	x = (x & 0x0000FFFF) + ((x >> 16) & 0x0000FFFF);
	return x;
} 
int rt[120],lt[120];
int main()
{
	int i,j,k;
	freopen("A.in","r",stdin);
	int T;
	int case_cnt=0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&M);
		gets(map[0]);
		//memset(mat,0,sizeof(mat));
		for(i=0;i<2*N-1;i++)
			gets(map[i]);
		memset(rt,0,sizeof(rt));
		memset(lt,0,sizeof(lt));
		int sx,sy,tx,ty,sid,tid;
		//memset(r,0,sizeof(r));
		/*for(i=0;i<M;i++)
		{
			int temp=1<<i;
			if(i>0)
				temp|=1<<(i-1);
			if(i<M-1)
				temp|=1<<(i+1);
			r[i]=temp;
		}*/
		for(i=0;i<N;i++)
		{
			int temp;
			for(j=0;j<M;j++)
			{
				temp=1<<j;
				if(j>0 && map[2*i][2*j-1]=='-')
					temp|=1<<(j-1);
				if(j<M-1&&map[2*i][2*j+1]=='-')
					temp|=1<<(j+1);
				r[i][j]=temp;
			}
		}
		for(i=0;i<N;i++)
		{
			int temp=0;
			int to=0;
			for(j=M-1;j>=0;j--)
			{
				temp*=2;
				to*=2;
				rt[i]*=2,lt[i]*=2;
				if(map[2*i][2*j]=='o')
					temp+=1;
				if(i<N-1&&map[2*i+1][2*j]=='|')
					to+=1;
				if(i<N-1&&j>0&&map[2*i+1][2*j-1]=='\\')
					rt[i]+=1;
				else if(i<N-1&&j>0&&map[2*i+1][2*j-1]=='/')
					lt[i]+=1;
				else if(i<N-1&&j>0&&map[2*i+1][2*j-1]=='X')
				{
					rt[i]+=1,lt[i]+=1;
				}
			}
			s_r[i]=temp;
			lt[i]/=2;
			nxt_r[i]=to;
		}
		int mask=(1<<M)-1;
		memset(head[0],-1,sizeof(head[0]));
		top[0]=0;
		row=0;
		int one;
		for(i=0;i<=mask;i++)
		{
			//insert(i,change(s_r[0],i),0,1);
			one=cal_one(i);
			update(i,change(s_r[0],i),0,one);
		}
		int c=0;
		int res=INF;
		int cur2,pre2;
		
		for(i=1;i<N;i++)
		{
			row=i;
			int pre=0,cur=0;
			c=1-c;
			memset(head[c],-1,sizeof(head[c]));
			top[c]=0;
			for(j=0;j<=mask;j++)//枚举当前开关的状态
			{
				one=cal_one(j);
				pre=cur=0;
				cur=change(s_r[i],j);//当前这一排灯的状态
				
				pre=(j&nxt_r[i-1])^( (j&rt[i-1])>>1) ^ ((j&lt[i-1])<<1);//前一排灯的状态			
				for(k=head[1-c][pre];k!=-1;k=lp[1-c][k].next)
				{
					cur2=cur^( (lp[1-c][k].s&nxt_r[i-1])^( (lp[1-c][k].s&(rt[i-1]>>1))<<1) ^ ((lp[1-c][k].s&(lt[i-1]<<1))>>1) );
					update(j,cur2,c,lp[1-c][k].cnt+one);
				}
			}
		}
		for(i=head[c][0];i!=-1;i=lp[c][i].next)
		{
			//res=(res+lp[c][0].cnt)%MOD;;
			if(lp[c][i].cnt<res)
				res=lp[c][i].cnt;
		}
		printf("Case %d: ",++case_cnt);
		if(res<INF)
			printf("%d\n",res);
		else
			puts("-1");
	}
	//printf("%d\n",clock());
}
