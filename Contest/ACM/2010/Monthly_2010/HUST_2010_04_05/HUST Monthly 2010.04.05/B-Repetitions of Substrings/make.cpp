#include <stdio.h>
#include <cstring>
#include <time.h>
#include <stdlib.h>

int main()
{
	srand(time(0));
	int n = 100000;

	//small cases
	puts("abcabc 2");
	puts("acmac 3");
	puts("abababab 2");
	puts("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa 20");
	puts("abaaaaaaaaaaaaaaaaaazaaaaaaaaabaaaaaaaaabaaaaaaaaaa 1");
	puts("abababababababababababababababab 10");
	puts("azsdfetrggggggggojigegnegegemacmacmacmacmewfiowfnegtr 3");
	puts("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa 20");
	puts("abcdefgd 1");
	puts("aaaaaaaaaaaa 12");
	puts("rt 2");

	//case 1
	for(int i=0; i<n; ++i) printf("a");
	printf(" 2\n");

	//case 2
	for(int i=0; i<n; ++i) printf("a");
	printf(" 1\n");

	//case 3 to 5
	for(int t=0; t<3; ++t)
	{
		for(int j=0; j<n; ++j)
		{
			int a = rand() % 26;
			printf("%c", 'a' + a);
		}
		int k = rand() % n + 1;
		printf(" %d\n", k);
	}

	return 0;
}

