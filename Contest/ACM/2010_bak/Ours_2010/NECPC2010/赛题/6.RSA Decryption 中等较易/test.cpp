#include<stdio.h>
__int64 f(__int64 a, __int64 b, __int64 c){
	//return a^b (mod c)
	__int64 d;
	__int64 retValue;
	if(b==0)return 1;
	if(b==1)return a;
	d=f(a, b/2, c);
	if(b%2==0){
		retValue = ((d%c)*(d%c))%c;
	}else{
		retValue = ((d%c)*((d*a)%c))%c;
	}
	//printf("****    %I64d (%I64d, %I64d, %I64d)\n",retValue, a, b, c);
	return retValue;
}
int main()
{
	__int64 r, t, m, n;
	bool m_GT_r = false;
	freopen("in.in","r",stdin);
	freopen("test.out","w",stdout);
	while(scanf("%I64d%I64d%I64d",&r,&t,&m)!=EOF)
	{
		m_GT_r=false;
		if(m>r){
			m_GT_r=true;
			m=m%r;
		}
		n=f(m, t, r);
		printf("%I64d",n);
		printf("\n");
		//printf("\n");printf("\n");

	}
	return 0;
}
