#include <stdio.h>
#include <string>
#include <iostream>
#include <map>
using namespace std;
#define S 311
typedef __int64 Int;

string Tran(Int base10,int base)
{
	char str[S];
	char a[S];
	int cnt =0;
	while(base10)
	{
		int tmp = base10%base;
		
		a[cnt] = (tmp < 10) ? (tmp+'0'): (tmp -10 + 'A');
		
		base10 /= base;
		
		cnt++;
	}
	a[cnt] = '\0';
	for(int i=cnt-1;i>=0;i--)
	{
		str[cnt-1-i] = a[i];
	}
	str[cnt] = '\0';
	string ans = str;
	return ans;
}

int size,k;


Int SUM(int st,int ed,string str)
{
	Int sum =0;
	for(int i=st ; i <= ed; i ++)
	{
		sum *= 10;
		sum += str[i]-'0';
	}
//	cout << str << endl;
//	printf("helolo %d %d %d\n",st,ed,sum);
	return sum;
}

map <Int,int> best;

int dp(Int);

int dfs(int st,int curp,string str,Int add)
{
//	cout << str << endl;
	int size = str.length();
	if(curp > k && st == size)
	{
	//	printf("%I64d\n",add);
		return dp(add);
	}
	if(st > size || curp > k)return 2;
	for(int i=st;i<size;i++)
	{
		int tmp = dfs(i+1,curp+1,str,add+SUM(st,i,str));
		if(tmp == 1)
			return 1;
	}
	return 2;
}

int dp(Int cur)
{
	if(best[cur] != 0)
	{
	//	printf("%I64d %d\n",cur,best[cur]);
		return best[cur];
	}
	string str = Tran(cur,10);
	if(dfs(0,1,str,0) == 1)
	{
		best[cur] = 2;
		return 2;
	}
	best[cur] = 1;
	return 1;
}


int main()
{
	Int n;
	while(scanf("%I64d%d",&n,&k)!=EOF)	
	{
		best.clear();
		printf("%d\n",dp(n)-1);
	}
	return 0;
}
