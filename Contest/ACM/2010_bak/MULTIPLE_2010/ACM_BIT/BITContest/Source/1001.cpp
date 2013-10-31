/*
把点i拆成两个点Li和Ri，把边i->j拆成Li->Rj，这样就把图拆成了一个二分图。不难发现，二分图的任意一个完备匹配对应了原题的一组tours。这样，求出最佳匹配，就是本题的结果。
*/
#include <stdio.h>
#include <string.h>
#define maxn 200
#define maxm 1000000
#define maxr 10000000

long n/*顶点数*/,m/*边数*/;
//对于每个点，info和infor分别指向这个点出发的边表和到达这个点的边表 
//对于每条边，next和nextr分别指向“出发的 ”边表和“到达”的边表的下一条边
//from，to，cost指一条边的起点，终点和长度 
long info[maxn],next[maxm],infor[maxn],nextr[maxm],from[maxm],to[maxm],cost[maxm],p;
//顶标 
long lf[maxn],rf[maxn];
//flag表示左边节点是否已盖，used表示左边节点时候已访问，used2表示右边节点是否已访问，op表示右边节点与哪个左边节点匹配，ft表示匹配的代价（便于统计） 
long flag[maxn],used[maxn],used2[maxn],op[maxn],ft[maxn];

//深搜找可增光路，当前节点在左边的now 
long dfs (long now) {
    long i;
    
    used[now] = 1;
    
    //找到一个未盖点，构成可增广路！ 
    for (i=info[now];i!=-1;i=next[i])
        if (lf[now] + rf[to[i]] == cost[i] && op[to[i]] == -1) {
            op[to[i]] = now;
            ft[to[i]] = cost[i];
            flag[now] = 1;
            return 1;
            }
    //把一段非匹配边和一段匹配边加入交错树，并检查能否通过新到达的点得到可增广路 
    for (i=info[now];i!=-1;i=next[i])
        if (lf[now] + rf[to[i]] == cost[i] && !used[op[to[i]]]) {
            used2[to[i]] = 1;
            if (dfs(op[to[i]])) {
                op[to[i]] = now;
                ft[to[i]] = cost[i];
                flag[now] = 1;
                return 1;
                }
            }
    return 0;
    }

int main () {
    long t,i,j,a,b,c,cs,f;
    
    //freopen("tours.in","r",stdin);
    //freopen("tours.out","w",stdout);
    
    for (scanf("%ld",&t);t>0;t--) {
        
        //输入，构图 
        scanf("%ld%ld",&n,&m);
        
        memset(info,-1,sizeof(info));
        memset(infor,-1,sizeof(infor));
        p = 0;
        
        for (i=0;i<m;i++) {
            scanf("%ld%ld%ld",&a,&b,&c);
            
            a --;
            b --;
            next[p] = info[a];
            nextr[p] = infor[b];
            from[p] = a;
            to[p] = b;
            cost[p] = c;
            info[a] = p;
            infor[b] = p;
            p ++;
            }
        
        //设置初始顶标        
        for (i=0;i<n;i++) {
            lf[i] = maxr;
            for (j=info[i];j!=-1;j=next[j])
                if (cost[j] < lf[i])
                    lf[i] = cost[j];
            rf[i] = 0;
            }
        
        //初始情况是所有点未匹配 
        memset(flag,0,sizeof(flag));
        memset(op,-1,sizeof(op));
        
        //对于每个点，开始匹配 
        for (cs=0;cs<n;cs++) {
            memset(used,0,sizeof(used));
            memset(used2,0,sizeof(used2));
            while (!dfs(cs)) {
                //如果匹配不成功，则修改顶标 
                a = maxr;
                for (i=0;i<n;i++)
                    if (used[i])
                        for (j=info[i];j!=-1;j=next[j])
                            if (!used2[to[j]] && cost[j] - lf[i] - rf[to[j]] < a)
                                a = cost[j] - lf[i] - rf[to[j]];
                for (i=0;i<n;i++)
                    if (used[i])
                        lf[i] += a;
                for (i=0;i<n;i++)
                    if (op[i]!=-1 && used2[i])
                        rf[i] -= a;
                memset(used,0,sizeof(used));
                memset(used2,0,sizeof(used2));
                }
            }
        //统计并输出 
        a = 0;
        for (i=0;i<n;i++)
            a += ft[i];
        printf("%ld\n",a);
        }
    
    return 0;
    }
