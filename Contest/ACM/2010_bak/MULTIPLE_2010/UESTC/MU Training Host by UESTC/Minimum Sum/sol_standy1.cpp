#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MaxN = 100010;
typedef long long LL;

int N, M, Q;
int tree[20][MaxN];
int num[20][MaxN];
int sorted[MaxN];
int mp[MaxN];
int r[MaxN];
struct Itv
{
	int l, r, mid;	
}itv[MaxN];
struct adjList
{
	int id;
	bool flag;
	int nxt;	
}Lst[MaxN*2];
int Head[MaxN], LCnt;
LL sumItv[MaxN];
int cntItv[MaxN];
int cnt[MaxN];
LL sum[MaxN];
int retCnt;
LL retSum;

bool cmp(int a, int b)
{
	return tree[0][a] < tree[0][b];	
}

void Lisan()
{
	for(int i=1; i<=N; i++)	r[i] = i;
	sort(r+1, r+N+1, cmp);
	mp[1] = tree[0][r[1]];
	tree[0][r[1]] = M = 1;
	for(int i=2; i<=N; i++)
	{
		if(tree[0][r[i]] != mp[M])	mp[++M] = tree[0][r[i]];
		tree[0][r[i]] = M;	
	}
	for(int i=1; i<=N; i++)	sorted[i] = tree[0][r[i]];
}

void make_tree(int dep, int l, int r)
{
	if(l == r)	return;
	int mid = (l + r) / 2, same = 0;
	int lCur = l, rCur = mid+1;
	for(int j=l; j<=r; j++)	same += (tree[dep][j] < sorted[mid]);
	same = mid - l + 1 - same;
	for(int j=l; j<=r; j++)
	{
		if(tree[dep][j] < sorted[mid])	tree[dep+1][lCur++] = tree[dep][j];	
		else if(tree[dep][j] == sorted[mid] && same)
		{
			tree[dep+1][lCur++] = tree[dep][j];	
			same --;	
		}
		else	tree[dep+1][rCur++] = tree[dep][j];
		num[dep][j] = num[dep][l-1] + lCur - l;	
	}
	make_tree(dep+1, l, mid);
	make_tree(dep+1, mid+1, r);
}

int get_value(int dep, int L, int H, int l, int r, int k)
{
	if(l == r)	return tree[dep][l];
	int Cnt = num[dep][r] - num[dep][l-1];
	int mid = (L + H) >> 1;
	if(Cnt >= k)
	{
		int delta = num[dep][l-1] - num[dep][L-1];
		return get_value(dep+1, L, mid, L+delta, L+delta+Cnt-1, k);		
	}
	else	
	{
		int delta = (l-L) - (num[dep][l-1]-num[dep][L-1]);
		k -= Cnt;	Cnt = r - l + 1 - Cnt;
		return get_value(dep+1, mid+1, H, mid+1+delta, mid+delta+Cnt, k);	
	}
}

void addEdge(int x, int i, bool f)
{
	Lst[LCnt].id = i;
	Lst[LCnt].flag = f;
	Lst[LCnt].nxt = Head[x];
	Head[x] = LCnt ++;	
}

void update(int k, int v)
{
	while(k <= M)
	{
		sum[k] += v;
		cnt[k] ++;
		k += k & -k;	
	}	
}

void read(int k)
{
	retSum = retCnt = 0;
	while(k)
	{
		retSum += sum[k];
		retCnt += cnt[k];
		k -= k & -k;	
	}	
}

void check(int i)
{
	int x = Head[i];
	while(x != -1)
	{
		i = Lst[x].id;
		read(itv[i].mid);
		if(Lst[x].flag)	
		{
			sumItv[i] += retSum;
			cntItv[i] += retCnt;	
		}
		else			
		{
			sumItv[i] -= retSum;
			cntItv[i] -= retCnt;	
		}
		x = Lst[x].nxt;
	}		
}

void solve()
{
	Lisan();
	make_tree(0, 1, N);
	LCnt = 0;
	memset(Head, -1, sizeof(Head));
	for(int i=0; i<Q; i++)	
	{
		itv[i].mid = get_value(0, 1, N, itv[i].l, itv[i].r, (itv[i].r-itv[i].l)/2+1);
		addEdge(itv[i].l-1, i, 0);
		addEdge(itv[i].r, i, 1);
	}
	memset(sum, 0, sizeof(sum));
	memset(sumItv, 0, sizeof(sumItv));
	memset(cnt, 0, sizeof(cnt));
	memset(cntItv, 0, sizeof(cntItv));
	for(int i=1; i<=N; i++)
	{
		update(tree[0][i], mp[tree[0][i]]);
		check(i);
	}
	for(int i=1; i<=N; i++)	sum[i] = sum[i-1]+mp[tree[0][i]];
	for(int i=0; i<Q; i++)
	{
		LL mid = mp[itv[i].mid];
		LL ans = (2*cntItv[i]-itv[i].r+itv[i].l-1)*mid;
		ans += sum[itv[i].r]-sum[itv[i].l-1]-2*sumItv[i];
		printf("%lld\n", ans);	
	}	
}

int main()
{
//	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
//	int tim = clock();

	int T;	cin >> T;
	for(int cas=1; cas<=T; cas++)
	{
		printf("Case #%d:\n", cas);
		cin >> N;
		for(int i=1; i<=N; i++)	scanf("%d", &tree[0][i]);
		cin >> Q;
		for(int i=0; i<Q; i++)	
		{
			scanf("%d %d", &itv[i].l, &itv[i].r);
			itv[i].l ++;	itv[i].r ++;	
		}
		solve();
		putchar('\n');
	}
//	cout << "runtime  " << clock() - tim << endl;
	
	return 0;	
}
