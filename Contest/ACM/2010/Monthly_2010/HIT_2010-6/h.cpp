#include <stdio.h>
#define E 0.0000
int main()
{
	double a, b;
	while(scanf("%lf%lf",&a,&b)!=EOF)
	{
		if(a + E >= b)
			printf("Yes, Mr. Wendy is a ****ing genius!\n");
		else printf("No, Mr. Pian is the real ****ing genius!\n");
	}
}
