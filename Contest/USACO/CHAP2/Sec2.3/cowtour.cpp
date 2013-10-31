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
#define N 200
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define sp(a) ((a)*(a))
#include <string.h>
#define Dis(i,j) (sqrt(sp(p[i].x-p[j].x)+sp(p[i].y-p[j].y)))
#define E 0.000000


using namespace std;
double MAX = 10000000000000000000000.0;
struct Point
{
	double x,y;
}p[N];
double mnmnk;

int n;
double dis[N][N];
double mndis[N][N];
double mx[N];

void init()
{
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			dis[i][j] = mndis[i][j] = MAX;
}
/*
������ 
*/
int vst[N];
    ofstream fout ("cowtour.out");
   ifstream fin ("cowtour.in");

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
		mnmnk = Max(mx[st],mnmnk);
		mn = cur;
		cur = 0;	
		for(int i=1;i<=n;i++)
			if(!vst[i])
			{
				if(mndis[st][mn] + dis[mn][i] < mndis[st][i])
				{
					mndis[st][i] = 	mndis[st][mn] + dis[mn][i];
				}
				if(mndis[st][i] < mndis[st][cur])
					cur = i;
			}
	}
}

int main() {
    
    fin >> n;
    init();
	for(int i=1;i<=n;i++)   
	{
		int a,b;
		fin >> p[i].x >> p[i].y;
	//	fout << p[i].x << " " << p[i].y << endl;
	}
	int a;
	int meet[N][N];
	char s[N];
	for(int i=1;i<=n;i++)
	{
		fin >> s;
		if(strlen(s) != n)
			while(1);
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
	mnmnk = 0;
	for(int i = 1; i <=n; i ++)
	{
		SP(i);
	/*	for(int j=1;j<=n;j++)
			fout << dis[i][j] <<  " ";
			//fout << setprecision(8) << mndis[i][j] <<  " ";
		fout << endl;*/
	
	}
	double mnmn = MAX;
	//fout << mnmnk << endl;
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
		{
			double cur = Dis(i,j);
			if(mndis[i][j] == MAX)
				mnmn = Min(mnmn , Max(mnmnk,cur + mx[i] + mx[j]));
	//		fout << mnmn << endl ;
		}
	fout<<setiosflags(ios::left)<<setiosflags(ios::fixed) <<setprecision(6)<<mnmn<<endl;
    return 0;
}
/*
2010-09-06
06:30-08:59
������˺ö�� ��ʵһ�㶼���ѣ���֪��Ϊʲôǰ���ζ�û�ж�����
Ӣ�ĵĶ���Ӧ�ó��� �ͻ�Խ��Խ��
����ofstream������ȵ����⣬�����ҵ���������ˡ���˵����c++�����ذ�
��ν�����������˼·ȷʵ�ǹ���
���������е���
���;����� ������ ����ַ���

����������ҿ�ʼ��ʱ��û����͸�� �Ǻ������������ʱ�������׵ġ���ʼһֱ��Ϊ�Ǹ�ʽ֮���
���½�����󣬱Ͼ�ǰ�漸�����ݶ����ˡ�����Ҳ���ɺϰɡ���


*/
