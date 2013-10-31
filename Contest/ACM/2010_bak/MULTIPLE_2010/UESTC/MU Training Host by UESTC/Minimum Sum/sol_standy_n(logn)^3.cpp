#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MaxN = 100010;
const int Inf = 1000000001;
typedef long long LL;

int N, M, Q;
struct SEG
{
	int l, r;
	int dep;	
}seg[MaxN];
int sCnt;
int tree[20][MaxN];
int num[MaxN];
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
	return  num[a] < num[b];	
}

void Lisan()
{
	for(int i=1; i<=N; i++)	r[i] = i;
	sort(r+1, r+N+1, cmp);
	mp[1] = num[r[1]];
	num[r[1]] = M = 1;
	for(int i=2; i<=N; i++)
	{
		if(num[r[i]] != mp[M])	mp[++M] = num[r[i]];
		num[r[i]] = M;	
	}
}

void merge_table(int dep, int l, int r)
{
	int mid = (l+r)/2;
	int i = l, j = mid + 1, k = l;
	while(i <= mid && j <= r)
	{
		if(tree[dep][i] <= tree[dep][j])	tree[dep-1][k++] = tree[dep][i++];
		else	tree[dep-1][k++] = tree[dep][j++];	
	}
	while(i <= mid)	tree[dep-1][k++] = tree[dep][i++];
	while(j <= r)	tree[dep-1][k++] = tree[dep][j++];	
}

void make_table(int dep, int l, int r)
{
	if(r == l)
	{
		tree[dep][l] = num[l];
		return ;
	}	
	make_table(dep+1, l, (l+r)/2);
	make_table(dep+1, (l+r)/2+1, r);
	merge_table(dep+1, l, r);
}

void find_table(int dep, int L, int H, int l, int r)
{
	if(l > H || r < L)	return;
	if(l <= L && r >= H)
	{
		seg[sCnt].l = L;
		seg[sCnt].r = H;
		seg[sCnt++].dep = dep;
		return;	
	}	
	find_table(dep+1, L, (L+H)/2, l, r);
	find_table(dep+1, (L+H)/2+1, H, l, r);
}

int B_search(int x, int K)
{
	int dep = seg[x].dep;
	int low = seg[x].l - 1;
	int hig = seg[x].r + 1;	
	while(low + 1 < hig)
	{
		int mid = (low + hig) / 2;
		if(tree[dep][mid] <= K)	low = mid;
		else	hig = mid;	
	}
	return low - seg[x].l + 1;
}

int B_solve(int k)
{
	int low = 0, hig = Inf, mid;
	while(low + 1 < hig)
	{
		mid = (low + hig) / 2;
		int Cnt = 0;
		for(int i=0; i<sCnt; i++)
		{
			Cnt += B_search(i, mid);
		}	
		if(Cnt >= k)	hig = mid;
		else	low = mid;
	}	
	return hig;
}

int find_Kth(int l, int r, int k)
{
	sCnt = 0;
	find_table(0, 1, N, l, r);
	return B_solve(k);
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
	make_table(0, 1, N);
	LCnt = 0;
	memset(Head, -1, sizeof(Head));
	for(int i=0; i<Q; i++)	
	{
		itv[i].mid = find_Kth(itv[i].l, itv[i].r, (itv[i].r-itv[i].l)/2+1);
		addEdge(itv[i].l-1, i, 0);
		addEdge(itv[i].r, i, 1);
	}
	memset(sum, 0, sizeof(sum));
	memset(sumItv, 0, sizeof(sumItv));
	memset(cnt, 0, sizeof(cnt));
	memset(cntItv, 0, sizeof(cntItv));
	for(int i=1; i<=N; i++)
	{
		update(num[i], mp[num[i]]);
		check(i);
	}
	for(int i=1; i<=N; i++)	sum[i] = sum[i-1]+mp[num[i]];
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
//	freopen("2.out", "w", stdout);
//	int tim = clock();

	int T;	cin >> T;
	for(int cas=1; cas<=T; cas++)
	{
		printf("Case #%d:\n", cas);
		cin >> N;
		for(int i=1; i<=N; i++)	scanf("%d", num+i);
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
