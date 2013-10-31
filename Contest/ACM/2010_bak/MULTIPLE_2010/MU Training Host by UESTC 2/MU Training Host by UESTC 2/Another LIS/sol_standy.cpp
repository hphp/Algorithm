#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MaxN = 100010;

int tree[MaxN];
int pos[MaxN];
int N;

int find_Kth(int k)
{
	int idx = 0;
	for(int i=18; i>=0; i--)
	{
		idx |= 1 << i;
		if(idx<=N && tree[idx]<k)	k -= tree[idx];
		else	idx ^= 1 << i;
	}	
	return idx + 1;
}

int read(int k)
{
	int ret = 0;
	while(k)
	{
		ret = max(ret, tree[k]);
		k -= k & -k;	
	}	
	return ret;
}

void update(int k, int v, bool flag)
{
	while(k <= N)
	{
		if(flag)	tree[k] = max(tree[k], v);
		else		tree[k] += v;
		k += k & -k;	
	}	
}

void find_pos()
{
	for(int i=1; i<=N; i++)	tree[i] = i & -i;
	for(int i=N; i>0; i--)
	{
		pos[i] = find_Kth(pos[i]+1);
		update(pos[i], -1, 0);	
	}
}

void solve()
{
	memset(tree, 0, sizeof(tree));
	int preLIS = 0;
	for(int i=1; i<=N; i++)
	{
		preLIS = max(preLIS, read(pos[i])+1);
		printf("%d\n", preLIS);
		update(pos[i], read(pos[i])+1, 1);	
	}	
}

int main()
{
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
//	int tim = clock();
	
	int T;	cin >> T;
	for(int cas=1; cas<=T; cas++)
	{
		cin >> N;
		for(int i=1; i<=N; i++)	
			scanf("%d", pos+i);
		printf("Case #%d:\n", cas);
		find_pos();
		solve();
		putchar('\n');	
	}
//	cout << "runtime  " << clock()-tim << endl;
	
//	while(1);
	return 0;	
}
