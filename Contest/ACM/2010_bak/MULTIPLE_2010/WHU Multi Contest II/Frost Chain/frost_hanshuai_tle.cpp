/*
 * Author: OpenLegend
 * Created Time:  2010-8-18 19:41:30
 * File Name: fr.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
int n, D, x[5], y[5], h[5];
double dp[1<<15][5], tmp[1<<15][5];
int main() {
    freopen ("frost.in", "r", stdin);
    freopen ("frost_hanshuai.out", "w", stdout);
    while(scanf("%d%d", &n, &D) != EOF){
        vector<int> vec[5];
        for(int i = 0; i < 5; i ++) scanf("%d%d", &x[i], &y[i]);
        for(int i = 0; i < 5; i ++){
            for(int j = 0; j < 5; j ++){
                if((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]) <= D*D){
                    vec[i].push_back(j);
                    //printf("%d %d\n", i, j);
                }
            }
        }
        for(int i = 0; i < 5; i ++) scanf("%d", &h[i]);
        int mask = (1<<15)-1;
        memset(dp, 0, sizeof(dp));
        vector<int> vi;
        for(int i = mask; i >= 0; i --){
            bool over = false;
            for(int j = 0; j < 5; j ++){
                int hp = (i>>(j*3))&7;
                if(hp > h[j]){
                    over = true; break;
                }
            }
            if(!over) vi.push_back(i);
        }
        for(int i = 0; i < 5; i ++){
            int mc = 0, t;
            for(int j = 0; j < 5; j ++){
                t = h[j];
                if(i == j) t --;
                mc |= (t<<(j*3));
            }
            //printf("%d %d\n", mc, i);
            dp[mc][i] = 1.0 / 5;
        }
        for(int step = 0; step < n; step ++){
            memset(tmp, 0, sizeof(tmp));
            for(vector<int>::reverse_iterator it = vi.rbegin(); it != vi.rend(); it++){
                int i = *it;
                for(int j = 0; j < 5; j ++){
                    int tc = 0;
                    for(int tk = 0; tk < (int)vec[j].size(); tk ++){
                        int k = vec[j][tk];
                        if(k == j) continue;
                        int hp = (i>>(3*k))&7;
                        if(hp == 0) continue;
                        tc ++;
                    }
                    if(tc == 0) tmp[i][j] += dp[i][j];
                    for(int tk = 0; tk < (int)vec[j].size(); tk ++){
                        int k = vec[j][tk];
                        if(k == j) continue;
                        int hp = (i>>(3*k))&7;
                        if(hp == 0) continue;
                        int it = i - (1<<(3*k));
                        tmp[it][k] += dp[i][j]/tc;
                    }
                }
            }
            memcpy(dp, tmp, sizeof(tmp));
        }
        double ans[5];
        memset(ans, 0, sizeof(ans));
        for(int i = 0; i < (1<<15); i ++){
            for(int j = 0; j < 5; j ++){
                for(int k = 0; k < 5; k ++){
                    int hp = (i>>(3*k))&7;
                    if(hp == 0) ans[k] += dp[i][j];
                }
            }
        }
        for(int i = 0; i < 5; i ++){
            printf("%.3lf", ans[i]);
            if(i == 4) printf("\n");
            else printf(" ");
        }
    }
    return 0;
}

