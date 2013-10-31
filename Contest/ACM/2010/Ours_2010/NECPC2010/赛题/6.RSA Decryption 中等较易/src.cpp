#include <stdio.h>

#define WIN

#ifdef WIN
#define LONG __int64
#else
#define LONE long long
#endif

LONG r,s,t,m,n,nn;

LONG find(LONG tmp)
{
	if(tmp == 1)
	{
		return m%r;
	}
	LONG temp = find(tmp/2)%r;
	if(tmp%2 == 0)
	{
		return (temp*temp)%r;
	}
	else
	{
		return (((temp*temp)%r)*(m%r))%r;
	}
}

int main()
{
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
	LONG temp;
#ifdef WIN
	while(scanf("%I64d %I64d %I64d", &r, &t, &m) != EOF)
#else
	while(scanf("%lld %lld %lld", &r, &t, &m) != EOF)
#endif
	{
		temp = 1;
		n = find(t);
#ifdef WIN
		printf("%I64d\n",n);
#else
		printf("%lld\n",n);
#endif
	}
}
