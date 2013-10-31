/**********************************************************************
Author: hanshuai
Created Time:  2010/3/30 15:54:52
File Name: string.cpp
Description: 
**********************************************************************/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const LL MOD = 1000000007;
LL mpow(LL x, LL k){
    LL ret = 1;
    while(k){
        if(k&1) ret = (ret*x)%MOD;
        k >>= 1;
        x = (x*x)%MOD;
    }
    return ret;
}
priority_queue<PII, vector<PII>, greater<PII> > que;
int main() {
    freopen("code.out", "w", stdout);
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF){
        assert(n >= 1 && n <= 10000000);
        assert(m >= 0 && m <= 1000);
        while(!que.empty()) que.pop();
        int cc = n;
        for(int i = 0; i < m; i ++){
            int t1, t2;
            scanf("%d%d", &t1, &t2);
            assert(t1 >= 1 && t1 <= n);
            assert(t2 >= 1 && t2 <= n);
            que.push(make_pair(t1, t2));
        }
        while(!que.empty()){
            PII p = que.top(); que.pop();
            cc --;
            while(!que.empty()){
                PII tmp = que.top();
                if(tmp.first != p.first) break;
                que.pop();
                tmp.first = p.second+1;
                if(tmp.first > tmp.second) continue;
                que.push(tmp);
            }
        }
        printf("%d\n", (int)mpow(26, cc));
    }
    return 0;
}

