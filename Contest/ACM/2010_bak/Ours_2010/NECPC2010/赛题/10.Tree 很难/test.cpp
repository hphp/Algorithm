#include <stdio.h>
typedef int LONG;

const int N = 10005;

int g[N][N];
int n;
LONG ans;
int ansNum;
bool flag[N];

struct Node
{
	int next[N];
	int degree;
	int maxNum;
	LONG max;
};
Node node[N];

bool input()
{
	int i,a,b,l;
	
	if(scanf("%d",&n)!=EOF)
	{
		ans = ansNum =0;
		for(i=1; i<=n; ++i)
		{
			node[i].degree = 0;
			node[i].max = node[i].maxNum = 0;
			flag[i] = false;
		}
		for(i=0; i<n-1; ++i)
		{
			scanf("%d %d %d",&a, &b, &l);
			node[a].degree ++;
			node[a].next[node[a].degree] = b;
			node[b].degree ++;
			node[b].next[node[b].degree] = a;
			g[a][b] = g[b][a] = l;
		}
		return true;
	}
	return false;
}

void find(int now)
{
	flag[now] = true;
	node[now].max = 0;
	node[now].maxNum = 0;
	if(node[now].degree == 1)
	{
		node[now].maxNum = 1;
		//printf("%d\n",node[now].maxNum);
		return;
	}
	
	int i,j,max1AllNum, max2AllNum, max1NumList[N], tempNum, num;
	LONG max1, max2, temp;
	num = 0;
	max1 = max2 = max1AllNum = max2AllNum = max1NumList[0] = temp = tempNum = 0;
	
	for(i=1; i<=node[now].degree; ++i)
	{
		j = node[now].next[i];
		//printf("%d\n",j);
		if(flag[j])
		{
			continue;
		}
		num ++;
		find(j);
		temp = node[j].max + g[now][j];
		tempNum = node[j].maxNum;
		//printf("%d %d %d\n", node[j].degree,temp,tempNum);
		if(temp > max1)
		{
			max2 = max1;
			max2AllNum = max1AllNum;
			max1 = temp;
			max1AllNum = tempNum;
			max1NumList[0] = 1;
			max1NumList[max1NumList[0]] = tempNum;
		}
		else if(temp == max1)
		{
			max1AllNum += tempNum;
			max1NumList[0] ++;
			max1NumList[max1NumList[0]] = tempNum;
		}
		else if(temp > max2)
		{
			max2 = temp;
			max2AllNum = tempNum;
		}	
		else if(temp == max2)
		{
			max2AllNum += tempNum;
		}
	}
	if(num >= 2)
	{
		
		if(max1NumList[0] >= 2)
		{
			if(max1*2 >= ans)
			{
				
				//ans = max1*2;
				
				if(max1*2>ans)
				{
					ansNum = 0;
				}
				ans = max1*2;
				//printf("%d %d\n", ans, ansNum);
				for(i=1; i<=max1NumList[0]; ++i)
				{
					for(j=i+1; j<=max1NumList[0]; ++j)
					{
						ansNum += max1NumList[i]*max1NumList[j];
					}
				}
			}
		}
		else
		{
			if(max1 + max2 >= ans)
			{
				if(max1+max2>ans)
				{
					ansNum = 0;
				}
				ans = max1+max2;
				ansNum += max1AllNum*max2AllNum;
			}
		}
	}
	
	node[now].max = max1;
	node[now].maxNum = max1AllNum;
}

void slove()
{
	int i;
	for(i=1; i<=n; ++i)
	{
		if(node[i].degree > 1)
		{
			break;
		}
	}
	//printf("%d\n",i);
	find(i);
}

void print()
{
	printf("%d %d\n", ans, ansNum);
}

int main()
{
	freopen("in.in","r",stdin);
	freopen("test.out","w",stdout);
	while(input())
	{
		slove();
		print();
	}
}
