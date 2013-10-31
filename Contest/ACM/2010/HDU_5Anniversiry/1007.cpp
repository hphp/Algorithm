#include <stdio.h>
#include <vector>
#define N 10000001
using namespace std;
typedef __int64 Int;
Int rec[N];
int main()
{
	int n,A,B;;
	while(scanf("%d%d%d",&n,&A,&B)!=EOF)
	{
		int head = 1 , tail = 0;
		Int ans = 1;
		Int last = 1;
		for(int i=1;i<=n;i++)
		{
			Int cur = (last*A)%B;
			last = cur;
			while(head <= tail && cur <= rec[tail])
				tail--;
			rec[++tail] = cur;

			while(head < tail && (tail-head > A))
				head ++;
			ans = (rec[head]*ans)%B;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}

/*12:25-12:45*/
