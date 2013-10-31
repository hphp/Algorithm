#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

void gen(int len, int ratio)
{
	for (int i = 0; i < len; i++)
	{
		if (rand() % 100 < ratio)
			putchar('C');
		else
			putchar('J');
	}
	putchar('\n');
}

int main()
{
	srand(8909);
	freopen("f:\\necklace.in", "w", stdout);
	printf("50\n");
	for (int i = 0; i < 44; i++)
		gen(50, i + 56);
	for (int i = 0; i <= 10; i+=2)
		gen(1000000, i * 5 + 50);
	fclose(stdout);
    return 0;
}


