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
LL sum[20][MaxN];
int sorted[MaxN];
LL tot[MaxN];

void make_tree(int dep, int l, int r)
{
	if(l == r)	return;
	int mid = (l + r) / 2, same = 0;
	int lCur = l, rCur = mid+1;
	for(int j=l; j<=r; j++)	same += (tree[dep][j] < sorted[mid]);
	same = mid - l + 1 - same;
	for(int j=l; j<=r; j++)
	{
		if(tree[dep][j] < sorted[mid])	
		{
			tree[dep+1][lCur++] = tree[dep][j];
			sum[dep][j] = sum[dep][j-1] + tree[dep][j];	
		}	
		else if(tree[dep][j] == sorted[mid] && same)
		{
			tree[dep+1][lCur++] = tree[dep][j];	
			sum[dep][j] = sum[dep][j-1] + tree[dep][j];
			same --;	
		}
		else	
		{
			tree[dep+1][rCur++] = tree[dep][j];
			sum[dep][j] = sum[dep][j-1];
		}
		num[dep][j] = num[dep][l-1] + lCur - l;	
	}
	make_tree(dep+1, l, mid);
	make_tree(dep+1, mid+1, r);
}

LL get_value(int dep, int L, int H, int l, int r, int k, LL &S)
{
	if(l == r)	return tree[dep][l];
	int Cnt = num[dep][r] - num[dep][l-1];
	int mid = (L + H) >> 1;
	if(Cnt >= k)
	{
		int delta = num[dep][l-1] - num[dep][L-1];
		return get_value(dep+1, L, mid, L+delta, L+delta+Cnt-1, k, S);		
	}
	else	
	{
		S += sum[dep][r] - sum[dep][l-1];
		int delta = (l-L) - (num[dep][l-1]-num[dep][L-1]);
		k -= Cnt;	Cnt = r - l + 1 - Cnt;
		return get_value(dep+1, mid+1, H, mid+1+delta, mid+delta+Cnt, k, S);	
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
		for(int i=1; i<=N; i++)	
		{
			scanf("%d", &tree[0][i]);
			sorted[i] = tree[0][i];
			tot[i] = tot[i-1] + tree[0][i];
		}
		sort(sorted, sorted+N);
		make_tree(0, 1, N);	
		cin >> Q;
		int l, r, mid;
		LL S, ans;
		while(Q --)
		{
			scanf("%d %d", &l, &r);
			ans = S = 0;
			mid = get_value(0, 1, N, l+1, r+1, (r-l)/2+1, S);
			ans = (r-l)/2LL*mid - S;
			S = tot[r+1]-tot[l]-S-mid;
			ans += S - (r-l+1)/2LL*mid;
			printf("%lld\n", ans);
		}
		putchar('\n');
	}
//	cout << "runtime  " << clock() - tim << endl;
	
	return 0;	
}
