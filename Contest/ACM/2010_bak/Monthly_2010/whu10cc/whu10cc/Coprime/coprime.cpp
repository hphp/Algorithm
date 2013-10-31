/*
 * Author: xay
 * Created Time:  2010-3-28 20:29:10
 * File Name: coprime.cpp
 * Description: 
 */
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long lint;
const int maxint = -1u>>1;
const int mm = (int)sqrt(1e9)+1;
vector<int> prime, p;
bool used[32000] = {0};

void initprime() {
    prime.clear();
    prime.push_back(2);
    for (int i = 3; i < mm; i += 2) {
        if (used[i]) continue;
        prime.push_back(i);
        for (int j = i * i; j < mm; j += i) used[j] = true;
    }
}
void resolve(vector<int> &p, int m1, int m2) {
    p.clear();
    int m = (int)max(sqrt(double(m1)), sqrt(double(m2)));
    for (int i = 0; i < (int)prime.size() && prime[i] <= m; ++i) {
        if (m1 % prime[i] == 0 || m2 % prime[i] == 0) {
            p.push_back(prime[i]);
            while (m1 % prime[i] == 0) m1 /= prime[i];
            while (m2 % prime[i] == 0) m2 /= prime[i];
        }
    }
    if (m1 > m2) swap(m1, m2);
    if (m1 > 1) p.push_back(m1);
    if (m2 > 1 && m2 != m1) p.push_back(m2);
}
void dfs(int dep, lint now, lint mid, lint &res) {
    if (dep == p.size()) {
        res += mid / now;
        return;
    }
    dfs(dep + 1, now, mid, res);
    dfs(dep + 1, now * p[dep], -mid, res);
}
int main() {
    initprime();
    int t, ca = 0;
    scanf("%d", &t);
    while (t--) {
        printf("Case %d: ", ++ca);
        int m1, m2, k;
        scanf("%d%d%d", &m1, &m2, &k);
        resolve(p, m1, m2);
        lint low = 1, high = (1uLL<<63) - 2uLL, ans = -1;
        while (low <= high) {
            lint mid = ((unsigned long long)low + (unsigned long long)high) / 2, res = 0;
            dfs(0, 1, mid, res);
            if (res >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}

