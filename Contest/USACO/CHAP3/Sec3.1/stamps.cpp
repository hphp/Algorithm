/*
ID: hanjiatong1
PROG: stamps
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#define K 210
#define CNT 2010011
#define N 54
#define Max(a,b) ((a)>(b)?(a):(b))
using namespace std;
bool exist[CNT][2] = {0};
int sure[CNT];
int k,n,v[N];
void init()
{
	for(int i=0;i<CNT;i++)
		sure[i] = -1;
	sure[0] = 0;
}

int main() {
    ofstream fout ("stamps.out");
    ifstream fin ("stamps.in");
    fin >> k >> n;
    int mx = 0;
    for(int i=0;i<n;i++)
    {
    	fin >> v[i];
    	mx = Max(v[i],mx);
	}
    int cnt = 0;
    init();
    mx *= k;
/*    for(int kk=0;kk<k;kk++)
    {
		for(int j=1;j<=mx;j++)
		{
			for(int i=0;i<n;i++)
			{
				if(j-v[i] >= 0 && exist[j-v[i]][0])
					exist[j][1] = 1;
			}
		}
		for(int i=0;i<=mx;i++)
		{
			exist[i][0] = exist[i][1] , exist[i][1] = 0;
			if(exist[i][0])
				sure[i] = 1;
		}
	}
	int i=1;
	for(;i<=mx;i++)
		if(sure[i]==0)
			break;
	fout << i-1 << endl;*/
    while(1)
    {
		int mn = k;
		for(int i=0;i<n;i++)
			if(cnt - v[i] >= 0 && sure[cnt-v[i]] < mn && sure[cnt-v[i]] >= 0)
				mn = sure[cnt-v[i]];
		if(mn < k)
			sure[cnt] = mn +1;
		bool flag = 0;
		if(sure[cnt]!=-1)
			flag= 1;
		if(flag ==0)break;
		cnt++;
	}
	fout << cnt-1 << endl;
    return 0;
}
/*
09:40-10:14
���˼���˼·
��������Щû�б�Ҫ��Ĵ����ݣ��Ͳ������ˡ�
��exist[i][j]��ʾ�ճ�i��j���Ƿ����
����һ����һά�����˷ѵ��ġ�Ҳ��֪����ô��ģ���û�뵽����
��ô�ܿ�ʼ�������ŵ��ء�
Ȼ�����ݳ����ˡ� 
10:22
-10:32

���ַ������鿪�����ˣ������˹������飬������Ҫ���������
�����ء���ʱ�ˡ�
ͻȻ�뵽��¼i��ʱ��ֻ��Ҫ��¼�õ���С�ĸ��������ˡ�
�Ҿͺ��ˡ�
��Ȼ����������
���ݹ����� 
������Щ���������ģ�����һ��Ҫ�ó���ķ�����
������һ���������ص㣬Ҫ�����ص�ȥѡ�����������ǡ� 
*/

