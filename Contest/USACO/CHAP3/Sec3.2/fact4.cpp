/*
ID: hanjiatong1
PROG: fact4
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int cnt[2];
int rec[5000];

int main() {
    ofstream fout ("fact4.out");
    ifstream fin ("fact4.in");
    int n;
    fin >> n;
    cnt[0] = cnt[1] = 0;
    for(int i=1;i<=n;i++)
    {
		rec[i] = i;
		while(rec[i]%5==0)
		{
			cnt[0]++;
			rec[i]/=5;
		}
		while(rec[i]%2==0)
		{
			cnt[1]++;
			rec[i]/=2;
		}
	}
	int ans = 1;
	if(cnt[0]>cnt[1])
	{
		ans = 5;	
	}
	if(cnt[1] > cnt[0])
	{
		while(cnt[1]>cnt[0])
		{
			ans *= 2;
			ans %= 10;
			cnt[1]--;
		}
	}
	for(int i=1;i<=n;i++)
		ans *= rec[i] , ans %= 10;
		
	fout << ans << endl;
    
    return 0;
}
/*
15:19
 ��ɼ������
 
 15:25
 ������
 15��43
 ��ɴ��⡣ʵ���ǣ��е�����ˣ�Ҳ���ܿ�ʼ�������ⶼ��ˮ�⡣ 
*/
