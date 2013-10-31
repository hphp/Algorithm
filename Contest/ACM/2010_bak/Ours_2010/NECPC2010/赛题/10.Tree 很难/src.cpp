#include <stdio.h>

#define N 10010

struct Node
{
	int t;
	int len;
	struct Node *next;
};

struct Sign
{
	int flag;
	int max;
	int num;
	int max_path;
	int num_path;
};

int n;
int buf_cnt;
struct Node buf[N*2], *head[N];
struct Sign sign[N];

int dp(int root)
{
	sign[root].flag = 0;

	int p[2] = {0, 0};
	int num[2] = {1, 1};
	int tol = 1, first_num = 1;

	int son_max = -1, son_num = 0;
	for (struct Node *cur = head[root]; cur != NULL; cur = cur->next)
	{
		if (sign[cur->t].flag == 0)	
			continue;

		dp(cur->t);

		int a = sign[cur->t].max_path + cur->len;
		int b = sign[cur->t].num_path;
		
		if (a > p[0])
		{
			p[1] = p[0];
			num[1] = num[0];
			p[0] = a;
			num[0] = b;
			tol = num[0] * num[1];
			first_num = 1;
		}
		else if (a == p[0])
		{
			if (first_num == 1)
				tol = 0;
			tol += num[0] * b;
			num[0] += b;
			first_num++;
		}
		else if (a > p[1])
		{
			p[1] = a;
			num[1] = b;
			if (first_num == 1)
			{
				tol = num[0] * num[1];
			}
		}
		else if (a == p[1])
		{
			num[1] += b;
			if (first_num == 1)
				tol += num[0] * b;
		}

		if (son_max < sign[cur->t].max)
		{
			son_max = sign[cur->t].max;
			son_num = sign[cur->t].num;
		}
		else if (son_max == sign[cur->t].max)
			son_num += sign[cur->t].num;
	}
	

	int cur_max = p[0] + p[1];
	int cur_num = tol;
	if (first_num > 1)
	{
		cur_max = 2 * p[0];
	}

	
	if (cur_max < son_max)
	{
		cur_max = son_max;
		cur_num = son_num;
	}
	else if (cur_max == son_max)
	{
		cur_num += son_num;
	}

	sign[root].max = cur_max;
	sign[root].num = cur_num;

	sign[root].max_path = p[0];
	sign[root].num_path = num[0];
	
	//printf("%d, %d %d, %d %d\n", root, sign[root].max, sign[root].num, sign[root].max_path, sign[root].num_path);
}

int main()
{
	//freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 1; i <= n; i++)
		{
			head[i] = NULL;
			sign[i].flag = 1;
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

		dp(1);

		printf("%d %d\n", sign[1].max, sign[1].num);
	}
}
