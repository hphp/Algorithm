/*
 * Author: OpenLegend
 * Created Time:  2010-7-15 14:38:58
 * File Name: test.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
using namespace std;
typedef long long LL;
const int maxn = 50005;
double eps = 1e-8;
int sgn(double v){
    return (v>eps)-(v<-eps);
}
pair<double, double> a[maxn];
double p[maxn], tmp[maxn];
LL ans;
void merge(int l, int r){
    if(l >= r) return;
    int mid = (l + r)/2;
    merge(l, mid);
    merge(mid+1, r);
    //printf("l = %d r = %d ans = %I64d\n", l, r, ans);
    int cc = 0, t1 = l, t2 = mid + 1;
    while(t1 <= mid || t2 <= r){
        if((t1 <= mid) && (t2 > r || p[t1]-p[t2] < 0)){
            tmp[cc++] = p[t1++];
        }else{
            tmp[cc++] = p[t2++];
            ans += (mid-t1+1);
        }
    }
    if(cc-1+l != r) while(1);
    for(int i = 0; i < cc; i ++) p[i+l] = tmp[i];
}
int main() {
    int n;
    double l, r;
    freopen ("life.in", "r", stdin);
    freopen ("life_hanshuai.out", "w", stdout);
    while(scanf("%d", &n) != EOF){
        scanf("%lf%lf", &l, &r);
        int cc = 0, tc = 0;
        for(int i = 0; i < n; i ++){
            double x1, y1, x2, y2;
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            if(sgn(x1-x2) == 0){
                if(sgn(l-x1) < 0 && sgn(r-x1) > 0) tc ++;
                continue;
            }
            a[cc].first = y2 - (y2-y1)/(x2-x1)*(x2-l);
            a[cc++].second = y2 - (y2-y1)/(x2-x1)*(x2-r);
        }
        sort(a, a+cc);
        for(int i = 0; i < cc; i ++){
            //printf("%lf %lf\n", a[i].first, a[i].second);
            p[i] = a[i].second;
        }
        ans = 0;
        merge(0, cc-1);
        fprintf (stderr, "done\n");
        //printf("%d %d\n", tc, cc);
        ans += (LL)tc*cc;
        printf("%I64d\n", ans);
    }
    return 0;
}

