/*
ID: hanjiatong1
PROG: kimbits
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <memory.h>
#include <string>
#define NN 40
using namespace std;
typedef long long Int;
Int size[NN][NN];

ofstream fout ("kimbits.out");
ifstream fin ("kimbits.in");

void dfs(int n,int m,Int l)
{
	if(n ==1 && l == 1)
	{
		fout << "0";
		return;	
	}
	if(n <= 0)return;
	if(m == 0 && size[n][m]>=l)
	{
		fout << "0";
		dfs(n-1,m,l);
		return;
	}
	if(size[n-1][m] >= l)
	{
		fout << "0";
		dfs(n-1,m,l);
	}
	else
	{
		fout << "1";
		dfs(n-1,m-1,l-size[n-1][m]);
	}
}

int main() {
	int N,L;
	Int I;
	while(fin >> N >> L >> I)
	{
	    memset(size,0,sizeof(size));
	    size[1][0] = 1;
	    size[1][1] = 2;
	    for(int j=2;j<=L;j++)
	    	size[1][j] = 2;
//		fout << "shit" << endl;
	    for(int i=2;i<=N;i++)
	    {
			size[i][0] = 1;
	    	for(int j=1;j<=L;j++)
	    		size[i][j] = size[i-1][j-1] + size[i-1][j];
		}
//		fout << "shit" << endl;
//		fout << size[N][L] << endl;
		dfs(N,L,I);
		fout << endl;
	}
    return 0;
}
/*
3 1 2
3 1 3
3 1 4
3 1 5
3 2 1
3 2 2
3 2 3
3 2 4 
3 2 5
3 2 6
3 2 7

��������ȿ��������⡣ 
��Ϊ�������ڼ��ϵĶ�������������1�ĸ���С�ڵ���L�ġ�
2�ˣ�Ҳ��֪������ô��ġ�����˯�߱Ƚ��㣬���Խ����˼·�Ƚ������ɡ�
���˽��ⱨ�棬��֪������ô���¡�
Ȼ����������Լ���ġ�Ч�������������ڱ߽紦���ϻ�����Щ����
����Ϊ�ҵĴ���˼���Ĳ�����
���Ǳ���ǰ����� ohYeah~! 

����һ������ ����Ϊû���뵽������Χ������

�Լ����˺ܶ������ݣ���������׿�г�Ч�ġ�һ��ac���˵ĸо���ˬ

*/
