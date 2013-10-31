#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//#define BUG
__int64 prime[1000000];
__int64 number[1000000];
int num;
void find()
{
	num=0;
	int i,j;
	for(i=2; i<50000; ++i)
	{
		if(number[i] == 0)
		{
			prime[num++] = i;
			for(j=2; j*i <50000; ++j)
			{
				number[i*j] = 1;
			}
		}
	}
}
int main()
{
#ifndef BUG
	freopen("in.in","w",stdout);
#endif
	find();
	__int64 p,q;
	__int64 r, s, t, n, m;
	__int64 temp;
	__int64 tt;
	__int64 tmp;
	int nn = 100;
	__int64 i,j;
	bool f;
	while(nn--)
	{
		f = false;
		p = prime[rand()%num];
		q = prime[rand()%num];
		while(q == p)
		{
			q = prime[rand()%num];
		}
		r = q*p;
#ifdef BUG
		printf("p=%I64d\nq=%I64d\nr=%I64d\n",p,q,r);
#endif		

		tmp = rand()%100+1;
		temp = (q-1)*(p-1)*(__int64)tmp+1LL;
#ifdef BUG
		printf("tmp=%I64d\ntemp=%I64d\n", tmp, temp);
#endif			
		for(i=7;i<10000;i++)
		{
			if(temp%i == 0)
			{
				f = true;
				s = i;
				t = temp/s;
				break;
			}
		}
		if(!f)
		{
			//printf("no\n");
			continue;
		}
		
		tmp = rand()%100+1;
		
		n = rand()%r;
		tt = 1;
		for(i=0; i<s ; ++i)
		{
			tt *= n;
			if(tt>r)
			{
				tt %= r;
			}
		}
		tt %= r;
		m = tt + r*tmp;
		
		printf("%I64d %I64d %I64d\n", r, t, m);
		
	}
#ifndef BUG
	//system("pause");
#endif
}
