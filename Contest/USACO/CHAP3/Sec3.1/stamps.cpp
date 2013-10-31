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
想了几个思路
首先是有些没有必要求的大数据，就不求算了。
用exist[i][j]表示凑成i用j个是否可行
诶，一看那一维就是浪费掉的。也不知道怎么想的，就没想到。。
怎么能开始不想最优的呢。
然后数据超掉了。 
10:22
-10:32

这种方法数组开不下了，就用了滚动数组，但是又要求大数据了
后来呢。超时了。
突然想到记录i的时候，只需要记录用的最小的个数就行了。
我就汗了。
果然是这样。。
数据过掉。 
发现有些题是这样的，他不一定要用常规的方法，
但是有一定的数据特点，要根据特点去选择解决方案才是。 
*/

