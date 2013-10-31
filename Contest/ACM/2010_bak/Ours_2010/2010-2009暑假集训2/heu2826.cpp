#include <stdio.h>
#include <math.h>
#define N 302
#define E 0.000001

int n;
struct P
{
	double x,y;	
}p[2][N];

struct Vec
{
	double x,y;	
};

int mv[2][2] = {{-1,1},{1,-1}};

int next(int cur)
{
	if(cur > n)	
		return 1;
	if(cur < 1)
		return n;
	return cur;
}

double dis(Vec a)
{
	return sqrt(a.x*a.x+a.y*a.y);
}

Vec getVec(int f,int i,int j)
{
	Vec ans = {p[f][j].x-p[f][i].x,p[f][j].y-p[f][i].y};
//	printf("%d %d %d\n",f,i,j);
//	printf("vec : %.2lf %.2lf %.2lf %.2lf\n",p[f][i].x,p[f][i].y,p[f][j].x,p[f][j].y);
	return ans;	
}

double DP(Vec a,Vec b)
{
	return (a.x*b.x + a.y*b.y);
}

int Nequal(double a , double b)
{
	if(a - E <= b && a + E >= b)
		return 1;
		return 0;	
}

int Similar(int s1,int s2,int flag)
{
	int cc = 0;
	while(cc <=  n)
	{
		Vec a1 = getVec(0,s1,next(s1+mv[0][0]));
		Vec b1 = getVec(0,s1,next(s1+mv[0][1]));
		Vec a2 = getVec(1,s2,next(s2+mv[flag][0]));
		Vec b2 = getVec(1,s2,next(s2+mv[flag][1]));
	//	printf("%d %d :: (%.2lf,%.2lf) (%.2lf,%.2lf) (%.2lf,%.2lf) (%.2lf,%.2lf)\n",s1,s2,a1.x,a1.y,b1.x,b1.y,a2.x,a2.y,b2.x,b2.y);
		
		double da1 = dis(a1);
		double db1 = dis(b1);
		double da2 = dis(a2);
		double db2 = dis(b2);
		
		if(! Nequal(DP(a1,b1)*da2*db2,DP(a2,b2)*db1*da1))
		{
		//	printf("hei %d %d %lf %lf\n",s1,s2,DP(a1,b1)*da2*db2,DP(a2,b2)*db1*da1);
			return 0;
		}
		if(! Nequal(da1*db2,db1*da2))
		{
		//	printf("hei2 %d %d %lf %lf\n",s1,s2,da1*db2,db1*da2);
			return 0;
		}
		cc ++;
		s1 = next(s1+mv[0][1]);
		s2 = next(s2+mv[flag][1]);
	}
//	printf("%d %d\n",s1,s2);
	return 1;
}

char ans[2][10] = {"Yes","No"};



int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<2;i++)
			for(int j=1;j<=n;j++)
				scanf("%lf%lf",&p[i][j].x,&p[i][j].y);
		int flag = 1;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<2;j++)
			{
				if(Similar(1,i,j))
					flag = 0;
			}
			if(flag == 0)break;
		}
		printf("%s\n",ans[flag]);
	}
	return 0;
}

/*
3
0 0
1 1
0 1
0 0
2 2
0 2
3
0 0
1 1
0 1
0 0
2 2
0 1
3
0 0
1 1
0 1
0 0
2 2
0 2
3
0 0
1 1
0 1
0 0
0 2
-2 2
3
0 0
1 1
0 1
0 0
0 2
2 2
*/
