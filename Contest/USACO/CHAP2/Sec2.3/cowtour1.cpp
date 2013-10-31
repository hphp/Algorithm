/*
ID: hanjiatong1
PROG: cowtour
LANG: C++
*/
#include <iostream>

#include <iomanip>
#include <fstream>
#include <string>
#include <math.h>
#define N 160
#define Min(a,b) ((a)<(b)?(a):(b))
#define sp(a) ((a)*(a))
#define Dis(i,j) (sqrt(sp(p[i].x*1.0-p[j].x*1.0)+sp(p[i].y*1.0-p[j].y*1.0)))
#define E 0.000000


using namespace std;
double MAX = 100000000000.000000;
struct Point
{
	float x,y;
}p[N];

int n;
float dis[N][N];
float mndis[N][N];
float mx[N];

void init()
{
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			dis[i][j] = mndis[i][j] = MAX;
}
/*
¿´´úÂë 
*/
int vst[N];
//    ofstream fout ("cowtour.out");
//   ifstream fin ("cowtour.in");

void SP(int st)
{
	for(int i=0;i<=n;i++)
		vst[i] = 0;
	mndis[st][st] = 0.00000000;
	int cur = st,mn = st;
	while(cur)
	{
		vst[cur] = 1;
		mx[st] = mndis[st][cur];
		mn = cur;
		cur = 0;	
		for(int i=1;i<=n;i++)
			if(!vst[i])
			{
				if(mndis[st][mn] + dis[mn][i]+E < mndis[st][i])
				{
					mndis[st][i] = 	mndis[st][mn] + dis[mn][i]+E;
				}
				if(mndis[st][i] < mndis[st][cur]+E)
					cur = i;
			}
	}
}

int main() {
    
    scanf("%d",&n);
    init();
	for(int i=1;i<=n;i++)   
	{
		int a,b;
		scanf("%d%d",&a,&b);
		p[i].x = a*1.0;
		p[i].y = b*1.0;
	}
	int a;
	int meet[N][N];
	char s[N];
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		for(int j=1;j<=n;j++)
		{
			a = meet[i][j] = s[j-1]-'0';
			if(a)
			{
				dis[i][j] = dis[j][i] = Dis(i,j);
		/*		if(i == 1 && j == 8)
					fout << "strange a " << a << endl;
		*/
			}
		}
	}
	for(int i = 1; i <=n; i ++)
	{
		SP(i);
	
	}
	double mnmn = MAX;
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
		{
			double cur = Dis(i,j);
			if(!meet[i][j])
				mnmn = Min(mnmn , cur + mx[i] + mx[j]);
		}
	printf("%.6lf\n",mnmn);
	system("pause");
    return 0;
}

