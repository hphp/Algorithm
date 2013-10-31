#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#define zbwmqlw
#define PI 3.141592653589793238463
#define MP(x,y) make_pair(x,y)
#define PB(x) push_back(x)
#define fill(x,y) memset((x),(y),sizeof(x))
#define lch(x) (((x)<<1)+1)
#define rch(x) (((x)<<1)+2)
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define two(x) (1<<(x))

#define PROBNAME "sequence"
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::sort;
using std::pair;
using std::swap;
using std::priority_queue;
using std::vector;
using std::make_pair;
using std::lower_bound;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const int inf = 0x3f3f3f3f;
const LL infLL = 0x3f3f3f3f3f3f3f3fLL;
const double eps = 1e-7;
template<class T> inline void checkmin(T &a, const T &b) 
{if (b < a) a = b;}
template<class T> inline void checkmax(T &a, const T &b) 
{if (b > a) a = b;}

int p[50], c[50];
int h[100005];
int sfac[100005];
int sinv[100005];
int prime[405];
bool isprime[405];
int cp, n, K, mo, testcase, m0, m1, a0, a1, extra, ID, len, T;

void exgcd(int a, int b, int &x, int &y)
{
	if (b == 0) {
		x = 1; y = 0;
		return;
	} else {
		exgcd(b, a % b, y, x);
		y -= a / b * x;
	}
}

int power(int x, int y, int m)
{
	int r = 1;
	for (; y > 0; y >>= 1) {
		if (y & 1) 
			if (m == -1) r *= x; else r = (LL)r * x % m; 
		if (m == -1) x *= x; else x = (LL)x * x % m;
	}
	return r;
}

int calc_fac(int x)
{
	if (x <= 1) return 1;
	int d = x / m1;
	int r = x % m1;
	LL ans = power(sfac[m1 - 1], d, m1);
	ans = ans * sfac[r] % m1;
	extra += x / p[ID];
	ans = ans * calc_fac(x / p[ID]) % m1;
	return ans;
}

int calc_inv(int x)
{
	if (x <= 1) return 1;
	int d = x / m1;
	int r = x % m1;
	LL ans = power(sinv[m1 - 1], d, m1);
	ans = ans * sinv[r] % m1;
	extra -= x / p[ID];
	ans = ans * calc_inv(x / p[ID]) % m1;
	return ans;
}

int getinv(int a, int m)
{
	int x, y;
	exgcd(a, m, x, y);
	x %= m;
	x += (x < 0) * m;
	return x;
}

int getans()
{
	sfac[0] = sinv[0] = 1;
	for (int i = 1; i < m1; ++i) {
		sfac[i] = sfac[i - 1];
		sinv[i] = sinv[i - 1];
		if (i % p[ID] != 0) {
			sfac[i] = (LL)sfac[i] * i % m1;
			sinv[i] = (LL)sinv[i] * getinv(i, m1) % m1;
		}
	}
	h[0] = 1;
	h[1] = 0;
	len = 2;
	while (1) {
		h[len] = ((LL)(len - 1) * (h[len - 1] + h[len - 2])) % m1;
		if (h[len - 1] == 1 && h[len] == 0 && len % m1 == 1) {
			--len;
			break;
		}
		++len;
	}
	LL ret = h[(n - K) % len];
	extra = 0;
	ret = ret * calc_fac(n) % m1;
	ret = ret * calc_inv(n - K) % m1;
	ret = ret * calc_inv(K) % m1;
	ret = ret * power(p[ID], extra, m1) % m1;
	return ret;
}

void work()
{
	scanf("%d%d%d", &n, &K, &mo);
	cp = 0;
	if (mo == 1) {
		printf("Case %d: 0\n", ++T);
		return;
	}
	for (int i = 1; i <= prime[0] && prime[i] * prime[i] <= mo; ++i) if (mo % prime[i] == 0) {
		p[++cp] = prime[i];
		c[cp] = 0;
		for (; mo % prime[i] == 0; mo /= prime[i]) ++c[cp];
	}
	if (mo > 1) {
		p[++cp] = mo;
		c[cp] = 1;
	}
	for (ID = 1; ID <= cp; ++ID) {
		m1 = power(p[ID], c[ID], -1);
		a1 = getans();
		if (ID == 1) {
			a0 = a1;
			m0 = m1;
		} else {
			int k, l;
			exgcd(m0, m1, k, l);
			k *= a1 - a0;
			a0 = (a0 + k * m0) % (m0 * m1);
			m0 *= m1;
			a0 += (a0 < 0) * m0;
		}
	}
	printf("Case %d: %d\n", ++T, a0);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen(PROBNAME".in", "r", stdin);
	freopen(PROBNAME".out", "w", stdout);
#endif
	scanf("%d", &testcase);
	fill(isprime, 1);
	for (int i = 2; i <= 20; ++i) if (isprime[i]) for (int j = i + i; j <= 400; j += i) isprime[j] = false;
	for (int i = 2; i <= 400; ++i) if (isprime[i]) prime[++prime[0]] = i;
	while (testcase--) work();
}
