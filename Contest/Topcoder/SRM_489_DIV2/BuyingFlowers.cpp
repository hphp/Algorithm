#include <vector>
#include <stdio.h>
#include <math.h>
using namespace std;
#define N 160100
#define MAX (1<<28)
#define Min(a,b) ((a)<(b)?(a):(b))
#define abss(a) ((a)<0?(-(a)):(a))
int el[N],er[N];
int n,m;
/*int np[N] = {0};
int cnt,rec[N];
int l[N];
void prime_init()
{
	for(int i=2;i<N;i++)
	{
		for(int j=2;i*j<N;j++)
			if(!np[j])
				np[i*j] = 1;
	}
	for(int i=1;i<N;i++)
		if(!np[i])
			rec[cnt++] = i;
	int cur = 0;
	for(int i=1;i<N;i++)
	{
		if(i >= rec[cnt-1])
		{
			l[i] = cnt-1;
			continue;
		}
		while(i > rec[cur+1] && cur < cnt-1)
			cur++;
		if(i < rec[cur+1] && i >= rec[cur])
			l[i] = cur;
	}
}
*/

int comput(int cur)
{
	int ll = (int)sqrt(cur*1.0);
	for(int i = ll ; i >= 1 ; i --)
		if((cur % i) == 0)
		{
			//printf("hello cur%d /i%d i%d\n",cur,cur/i,i);
			return abss(cur/i - i);
		}
	return MAX;
}
class BuyingFlowers
{
	public:
		int buy(vector<int> r,vector<int>l)
		{
			int n = r.size();
			int stm = 1<<n;
			for(int i=1;i<stm;i++)
			{
				el[i] = 0;
				er[i] = 0;
				for(int j=0;j<n;j++)
					if(i &(1<<j))
					{
						el[i] += l[j];
						er[i] += r[j];
					}
			}
		//	prime_init();
/*			int n = r.size();
			int sr = 0;
			for(int i=0;i<n;i++)
				sr += r[i];
			for(int i=0;i<=sr;i++)
				er[i] = 0;
			er[0] = 1;
			for(int i=0;i<n;i++)
				for(int j=sr-r[i];j>=0;j--)
					if(er[j])
						er[j+r[i]] = 1;
			int m = l.size();
			int sl = 0;
			for(int i=0;i<m;i++)
				sl += l[i];
			for(int i=0;i<=sl;i++)
				el[i] = 0;
			el[0] = 1;
			for(int i=0;i<m;i++)
				for(int j=sl-l[i];j>=0;j--)
					if(el[j])
						el[j+l[i]] = 1;
*/
			int ans = MAX;
			for(int i=0;i<stm;i++)
			{
				if((i > 0) && (er[i]  == el[i]))
				{
					//printf("hei %d r:%d l %d\n",i,er[i],el[i]);
					int t = comput(er[i] + el[i]);
					ans = Min(ans,t);
				}
				if((el[i] == er[i] + 1 ) || (er[i] == el[i] + 1))
				{
					//printf("hei %d r%d l%d\n",i,er[i],el[i]);
					int t = comput(er[i] + el[i]);
					ans = Min(ans,t);
				}
			}
			if(ans == MAX)
				ans = -1;
			return ans;
		}
};
/*
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		vector <int> r,l;
		for(int i=0;i<n;i++)
		{
			int a;
			scanf("%d",&a);
			r.push_back(a);
		}
		for(int i=0;i<m;i++)
		{
			int a;
			scanf("%d",&a);
			l.push_back(a);
		}
		BuyingFlowers b = BuyingFlowers();
		//printf("%d\n",b.buy(r,l));
	}
	return 0;
}*/
