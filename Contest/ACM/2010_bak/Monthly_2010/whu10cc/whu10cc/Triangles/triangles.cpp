/**********************************************************************
Author: hanshuai
Created Time:  2010/4/13 13:35:03
File Name: triangles.cpp
Description: 
**********************************************************************/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cassert>
#include <iostream>

using namespace std;
typedef long long LL;
const LL MOD = 1000000007;
LL a[1005], n, m;
LL fix(LL v){
    return (v%MOD+MOD)%MOD;
}
LL S1(LL v){
    return (v*(v+1)/2)%MOD;
}
LL S2(LL v){
    LL tmp1 = v*(v+1), tmp2 = 2*v+1;
    if(tmp1%2 == 0) tmp1 /= 2;
    else tmp2 /= 2;
    if(tmp1%3 == 0) tmp1 /= 3;
    else tmp2 /= 3;
    tmp1 %= MOD; tmp2 %= MOD;
    return (tmp1*tmp2)%MOD;
}
//the number of triangle when v is the longest stick
LL calLS(LL v){
    v -= 3;
    if(v <= 0) return 0;
    LL b = v%2, num = (v-b)/2+1;
    return ((v+b)*num/2)%MOD;
}
//calculate the answer when m = 0.
LL calAll(){
    LL ret = 0, n2 = n/2;
    if(n&1) ret = calLS(n);
    ret += 2*S2(n2)-5*S1(n2)+3*n2;
    return fix(ret);
}
//calculate the number of triangle contains v-th stick
LL cal(LL v){
    LL ret = calLS(v);
    ret += (n-v)*(v-1) - (min(2*v-1,n)-v);
    return fix(ret);
}
//calculate the number of triangle contains v1-th and v2-th sticks
LL cal(LL v1, LL v2){
    LL ret = v1 - 1;
    if(v1 > v2 - v1) ret --;
    ret += min(v1+v2-1, n) - v2;
    return fix(ret);
}
//the number of the missed sticks between L and R inclusive.
LL bet(LL L, LL R){
    return lower_bound(a, a+m, R+1) - lower_bound(a, a+m, L);
}
LL solve(){
    //the number of the triangle contains exactly i sticks
    LL num1 = 0, num2 = 0, num3 = 0;
    for(int i = 0; i < m; i ++){
        num1 = (num1 + cal(a[i])) % MOD;
        for(int j = i + 1; j < m; j ++){
            num2 = (num2 + cal(a[i], a[j]))%MOD;
            num3 = (num3 + bet(a[j]+1, a[i]+a[j]-1))%MOD;
        }
    }
    num2 = fix(num2-3*num3);
    num1 = fix(num1-2*num2-3*num3);
    return fix(calAll()-num1-num2-num3);
}
int main() {
    int test, cas = 0;
    scanf("%d", &test);
    while(cin >> n >> m){
        test --;
        assert(1<=n && n <= 1000000000);
        assert(0<=m && m <= 1000);
        for(int i = 0; i < m; i ++){
            cin >> a[i];
            assert(1<=a[i] && a[i] <= n);
        }
        sort(a, a+m);
        for(int i = 1; i < m; i ++) assert(a[i-1] != a[i]);
        cout << "Case " << (++cas) << ": " << solve() << endl;
    }
    assert(test == 0);
    return 0;
}

