#include <stdio.h>

int n, ans;
int matrix[201][201]; 
int sumOfMatrix[201][201];
bool flag;

void input()
{
	int i, j;
	for(i=0; i<n ;i++)
	{
		for(j=0; j<n; j++)
		{
			scanf("%d",&matrix[i][j]);
			sumOfMatrix[i][j] = 0;
		}
	}
}

void solve()
{
	int i,j,k,l;
	int sum;
	int temp;
	flag = false;
	for(i=0; i<n; ++i)
	{
		for(j=0; j<n; ++j)
		{
			for(k=0; k<=i; ++k)
			{
				sumOfMatrix[j][k] += matrix[j][i];
			}
		}
		for(k=0; k<=i; ++k)
		{
			sum = 0;
			temp = 0;
			for(j=0; j<n; ++j)
			{
				sum += sumOfMatrix[j][k];
				while(sum >ans)
				{
					sum -= sumOfMatrix[temp++][k];
				}
				if(sum == ans)
				{
					flag = true;
					return;
				}
			}
		}
	}
}

void output()
{
	if(flag)
	{
		printf("yes\n");
	}
	else
	{
		printf("no\n");
	}
}

int main()
{
	freopen("KArray.in","r",stdin);
	freopen("test.out","w",stdout);
	while(scanf("%d %d",&n, &ans) != EOF)
	{
		input();
		solve();
		output();
	}
} 
