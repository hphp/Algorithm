#include <stdio.h>
#define NN 10100

int L[NN],R[NN];
int Head;

class LockersDivTwo
{
	public:
		int lastOpened(int N)
		{
			for(int i=1;i<=N;i++)
			{
				L[i] = i-1;
				R[i] = i+1;
			}
			L[1] = -1;
			R[N] = -1;
			int Head = 1;
			int cnt = 1;
			int last = -1;
			while(Head != -1)
			{
				int tmp = Head;
				last = Head;
				int cc = cnt+1;
				while(tmp != -1)
				{
//					printf("%d ",tmp);
					if(cc == cnt+1)
					{
						cc = 0;
						if(tmp == Head)
							Head = R[tmp];
						R[L[tmp]] = R[tmp];
						L[R[tmp]] = L[tmp];
					}
					tmp = R[tmp];
					cc ++;
				}
//				printf("\n");
				cnt ++;
			}
			return last;
		}
};
/*
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		LockersDivTwo l = LockersDivTwo();
		printf("%d\n",l.lastOpened(n));
	}
}*/
