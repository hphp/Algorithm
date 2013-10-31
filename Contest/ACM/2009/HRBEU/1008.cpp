#include<stdio.h>
#include <queue>
#define N 100100
using namespace std;
int n,rec[N];

struct Node
{
	int value;
	const bool operator<(Node a)const
	{
		if(value>a.value)	
			return 0;
			return 1;
	}
};

int main()
{
	while(scanf("%d",&n)!=EOF)	
	{
		int flag,x;
		priority_queue <Node> p_q;
		for(int i=0;i<n;i++)	
		{
			scanf("%d%d",&flag,&x);
			if(flag==0)
			{
				int cnt=0;
				while(!p_q.empty())
				{
					Node a=p_q.top();
					if(a.value<=x)
						break;
					p_q.pop();
					rec[cnt]=a.value;
					cnt++;
				}
				printf("%d\n",cnt);
				for(int j=0;j<cnt;j++)
				{
				//	printf("%d\n",rec[j]);
					Node a={rec[j]};
					p_q.push(a);
				}
			}
			else
			{
				Node a={x};
				p_q.push(a);	
			}
		}
	}return 0;
}
