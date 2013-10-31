#include <stdio.h>

int main()
{
	int a;
	while(scanf("%d",&a)!=EOF)
	{
		for(int i=0;i<a;i++)
			printf("%d",i%10);
			printf("\n");
	}
}
/*
01234567890123456789012345678901234567890123456789
http://jiurl.yeah.net http://jiurl.nease.net
Case 1: 0h0t0t0p0:0/0/0j0i0u0r0l0.0y0e0a0h0.0n0e0t0 1(22,13)0n0e0a0s0e1(23,4) 
*/
