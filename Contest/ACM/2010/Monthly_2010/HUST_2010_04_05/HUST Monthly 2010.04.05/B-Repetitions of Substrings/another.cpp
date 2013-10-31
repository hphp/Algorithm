#include <stdio.h>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;
#define maxl 200010
#define ll long long
#define SIZE 65535

struct node
{
	int l, r;
	node *next;
}
adj[SIZE], memo[maxl * 5];

int mset;
set< pair<int, int> > st;
set< pair<int, int> > :: iterator it;
char S[maxl];
int head[maxl], next[maxl], rank[maxl], b[maxl], L[maxl], list[maxl], height[maxl];
int f[maxl][20];
int n, k, tot;
bool vis[maxl];
long long ans;

int find(int l, int r)
{
	int idx = ((long long)l * n + r) % SIZE;
	node *ptr = adj[idx].next;

	while(ptr)
	{
		if(ptr->l == l && ptr->r == r) return 1;
		ptr = ptr->next;
	}

	ptr = &memo[mset++];
	ptr->l = l, ptr->r = r;
	ptr->next = adj[idx].next;
	adj[idx].next = ptr;

	return -1;
}

bool cmp(int i, int j){ return S[i] < S[j]; }

void suffix_sort(int n)
{
	for(int i=0; i<n; ++i) list[i] = i;
	sort(list, list+n, cmp);
	b[list[0]] = 0;
	for(int i=1; i<n; ++i)
	{
		if(S[list[i]]==S[list[i-1]]) b[list[i]] = b[list[i-1]];
		else b[list[i]] = i;
	}

	int j;
	for(int h=1; h<n; h<<=1)
	{
		for(int i=0; i<n; ++i) head[i] = next[i] = -1;
		for(int i=n-1; i>=0; --i)
		{
			if(list[i])
			{
				j = list[i] - h; if(j < 0)  j += n;
				next[j] = head[b[j]]; head[b[j]] = j;
			}
		}
		j = n - h; next[j] = head[b[j]]; head[b[j]] = j;
		for(int i=0, k=0; i<n; ++i)
		{
			if(head[i] >= 0) for(j=head[i]; j>=0; j=next[j]) list[k++] = j;
		}
		for(int i=0; i<n; ++i)
		{
			if(i>0 && list[i]+h<n && list[i-1]+h<n && b[list[i]]==b[list[i-1]] && b[list[i]+h]==b[list[i-1]+h])
				rank[list[i]] = rank[list[i-1]];
			else rank[list[i]] = i;
		}
		for(int i=0; i<n; ++i) b[i] = rank[i];
	}
}

void get_height(int n)
{
	height[0] = 0;
	for(int i=0; i<n; ++i) rank[list[i]] = i;
	for(int h=0, i=0; i<n; ++i)
	{
		if(rank[i] > 0)
		{
			int j = list[rank[i] - 1];
			while(S[i+h]==S[j+h] && S[i+h]!='$') ++h;
			height[rank[i]] = h;
			if(h > 0) --h;
		}
	}
}

int rmq_ready(int n)
{
	for(int i=0; i<n; ++i) f[i][0] = i;
	for(int j=1; (1<<j)<=n; ++j)
	{
		for(int i=0; (i+(1<<j)-1)<n; ++i)
		{
			int k = i + (1<<(j-1));
			if(height[f[i][j-1]] < height[f[k][j-1]])
				f[i][j] = f[i][j-1];
			else f[i][j] = f[k][j-1];
		}
	}
}

int LCP(int i, int j)
{
	if(i==j) return tot - list[i];

	if(i > j)
	{
		i ^= j; j ^= i; i ^= j;
	}

	int log = L[j - i];
	int k = j - (1<<log) + 1;
	return min(height[f[i+1][log]], height[f[k][log]]);
}

void init()
{

	strcat(S, "$");
	for(int i=0; i<n; ++i) S[i + n + 1] = S[n - 1 - i];
	S[2 * n + 1] = '$';
	S[2 * n + 2] = 0;

	tot = 2 * n + 2;
	n = n + 1;

	for(int i=1; i<=tot; ++i)
	{
		int j = 0;
		while((1<<j) <= i) ++j;
		j--;
		L[i] = j;
	}

	suffix_sort(tot);
	get_height(tot);
	rmq_ready(tot);

}

long long solve()
{
	ans = 0;

	if(k == 1) return (long long)(n - 1) * n / 2;

	//puts(S);
	mset = 0;
	for(int i=0; i<SIZE; ++i) adj[i].next = NULL;

	for(int l=1; l<n; ++l)
	{
		for(int i=0; i+l<n-1; i+=l)
		{
			int j = i + l;


			if(S[i] != S[j]) continue;

			int right = i + LCP(rank[i], rank[j]) - 1;
			int left = i - LCP(rank[n + n - 2 - i], rank[n + n - 2 - j]) + 1;

			if(left <= i - l) continue;


			int len = right - left + 1 + l;
			int d = len / l;

			if(d >= k)
			{
				if(find(left, right + l) != -1) continue;
				long long tmp = ( (ll)(len + 1) * (d - k + 1) - ((ll)l * (k + d) * (d - k + 1) / 2) );
				ans += tmp;
				//printf("n %d %d %d %d %d %d %lld\n", i, j, left, right, len, l, tmp);

				/*
				for(int x=left; x<=right+l; ++x) printf("%c", S[x]);
				printf(" %d %d %d %lld\n", l, left, right + l, tmp);
				*/
			}
		}
	}

	return ans;
}

int main()
{
	while(scanf("%s%d", S, &k) != EOF)
	{
		n = strlen(S);
		if(k == 1) printf("%lld\n", (long long)(n + 1) * n / 2);
		else
		{
			init();
			printf("%lld\n", solve());
		}
	}
	return 0;
}

