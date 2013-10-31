/**********************************************************************
Author: hanshuai
Created Time:  2010/8/17 22:24:32
File Name: easy.cpp
Description: 
**********************************************************************/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef vector<pair<double,double> > VDD;
const int maxn = 1005;
const double pi = acos(-1.0);
double p[maxn];
pair<int,int> a[maxn];
double solve(VDD vec){
    int n = vec.size(), j = 0;
    double mc = 0, ret = 0, tc = 0;
    for(int i = 0; i < n; i ++){
        tc += log(1-vec[i].second);
        while(j < i + n){
            double delta = vec[j%n].first - vec[i].first;
            if(delta < 0) delta += 2*pi;
            if(delta > pi) break;
            mc += log(1-vec[j%n].second);
            ++j;
        }
        mc -= log(1-vec[i].second);
        ret += exp(mc) * vec[i].second;
    }
    ret += exp(tc);
    return ret;
}
int main() {
    freopen("convex.out", "w", stdout);
    int n, t;
    while(scanf("%d", &n) != EOF){
        assert(1 <= n && n <= 1000);
        for(int i = 0; i < n; i++){
            scanf("%d%d", &a[i].first, &a[i].second);
            assert(a[i].first >= 1 && a[i].first <= 100000);
            assert(a[i].second >= 1 && a[i].second <= 100000);
            scanf("%d", &t);
            assert(t >= 0 && t < 100);
            p[i] = ((double)t)/100;
        }
        double ans = 0;
        for(int i = 0; i < n; i ++){
            VDD vec;
            for(int j = 0; j < n; j ++){
                if(i == j) continue;
                double v = atan2(a[j].second-a[i].second, a[j].first-a[i].first);
                vec.push_back(make_pair(v, p[j]));
            }
            sort(vec.begin(), vec.end());
            ans += p[i] * solve(vec);
        } 
        printf("%.2lf\n", ans);
    }
    return 0;
}

