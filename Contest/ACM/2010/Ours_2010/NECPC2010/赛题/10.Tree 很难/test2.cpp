#include <stdio.h>

#define N 10010
#define MAX 1<<30

struct Node
{
	int t;
	int len;
	struct Node *next;
};

int n;
int max, sum;
int buf_cnt;
struct Node buf[N*2], *head[N];

void prim(int root)
{
	int wt[N], sign[N];
	for (int i = 0; i <= n; i++)
	{
		wt[i] = MAX;
		sign[i] = 1;
	}

	int v = root, min;
	wt[v] = 0;
	sign[v] = 0;
	for (; v!= 0; v = min)
	{
		for (struct Node *cur = head[v]; cur; cur=cur->next)
		{
			if (sign[cur->t])
			{
				if (wt[v]+cur->len < wt[cur->t])
					wt[cur->t] = wt[v] + cur->len;
			}
		}
		min = 0;
		for (int i = 1; i <= n; i++)
			if (sign[i])
			{
				if (wt[i] < wt[min])
					min = i;
			}

		sign[min] = 0;
	}

	int tmp_max = 0;
	int tmp_num;
	for (int i = 1; i <= n; i++)
		if (tmp_max < wt[i])
		{
			tmp_max = wt[i];
			tmp_num = 1;
		}
		else if (tmp_max == wt[i])
			tmp_num++;

	if (tmp_max > max)
	{
		max = tmp_max;
		sum = tmp_num;
	}
	else if (tmp_max == max)
	{
		sum += tmp_num;
	}
}

int main()
{
	//freopen("in.in","r",stdin);
	//freopen("test2.out","w",stdout);
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 1; i <= n; i++)
		{
			head[i] = NULL;
		}

		buf_cnt = 0;
		for (int i = 1; i < n; i++)
		{
			int w, v, len;
			scanf("%d %d %d", &w, &v, &len);
			struct Node *cur = &buf[buf_cnt++];
			cur->t = v;
			cur->len = len;
			cur->next = head[w];
			head[w] = cur;
			
			cur = &buf[buf_cnt++];
			cur->t = w;
			cur->len = len;
			cur->next = head[v];
			head[v] = cur;
		}

		max = 0, sum = 0;
		for (int i = 1; i <= n; i++)
			prim(i);

		printf("%d %d\n", max, sum/2);
	}
}
