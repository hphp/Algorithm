/**********************************************************************
Author: hanshuai
Created Time:  2010-3-23 11:05:25
File Name: no.cpp
Description: 
**********************************************************************/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cassert>
#include <vector>
#include <iostream>

using namespace std;
typedef long long LL;
const int maxn = 105;
const LL MOD = 100003;
//0为个数 1为和 2为平方和
//sum为包含13的数, p10为0到10的k次方
LL sum[3][maxn], p10[3][maxn];
void fix(LL& v){
    v %= MOD;
    if(v < 0) v += MOD;
}
int main() {
    //init
    LL inv2 = 1, inv6 = 1;
    for(int i = 0; i < MOD-2; i ++){
        inv2 = inv2*2%MOD;
        inv6 = inv6*6%MOD;
    }
    memset(sum, 0, sizeof(sum));
    for(int i = 0; i < maxn; i ++){
        if(i==0){
            p10[0][i] = 1;
        }else p10[0][i] = (p10[0][i-1]*10)%MOD;
        LL n = (p10[0][i] - 1 + MOD)%MOD;
        p10[1][i] = n*(n+1)*inv2%MOD;
        p10[2][i] = n*(n+1)*(2*n+1)%MOD*inv6%MOD;
//        printf("i = %d 0 = %I64d 1 = %I64d 2 = %I64d\n", i, p10[0][i], p10[1][i], p10[2][i]);
    }
    //i:after 13, j:before 13.  
    for(int i = 0; i+2 < maxn; i ++){
        for(int j = 0; i+j+2 < maxn; j ++){
            
            LL a0 = p10[0][j], a1 = p10[1][j]*p10[0][i+2], a2 = p10[2][j]*p10[0][i+2]*p10[0][i+2];
            LL b0 = 1, b1 = 13*p10[0][i], b2 = 169*p10[0][i]*p10[0][i];
            LL c0 = p10[0][i]-sum[0][i], c1 = p10[1][i] - sum[1][i], c2 = p10[2][i] - sum[2][i];
            
            fix(a0); fix(a1); fix(a2);
            fix(b0); fix(b1); fix(b2);
            fix(c0); fix(c1); fix(c2);
//            printf("i = %d j = %d\n%I64d %I64d %I64d\n%I64d %I64d %I64d\n%I64d %I64d %I64d\n", 
//                    i, j, a0, a1, a2, b0, b1, b2, c0, c1, c2);
            
            int toL = i+j+2;
            //0
            sum[0][toL] += a0*b0*c0;
            //1
            sum[1][toL] += (a1*b0*c0+a0*b1*c0+a0*b0*c1)%MOD;
            //2
            LL p1 = (a2*b0*c0 + a0*b2*c0 + a0*b0*c2)%MOD;
            LL p2 = ((a1*b1*c0 + a0*b1*c1 + a1*b0*c1)*2)%MOD;
            sum[2][toL] += p1 + p2;
            
            fix(sum[0][toL]); fix(sum[1][toL]), fix(sum[2][toL]);
        }
    }
//    for(int i = 0; i < maxn; i ++){
//        printf("i = %d sum0 = %I64d sum1 = %I64d sum2 = %I64d\n", i, sum[0][i], sum[1][i], sum[2][i]);
//    }
    int test, n, cas = 0;
    scanf("%d", &test);
    while(scanf("%d", &n) != EOF){
        test --;
        printf("Case %d: %d\n", ++cas, (int)sum[2][n]);
    }
    assert(test == 0);
    return 0;
}

