/*
�ѵ�i���������Li��Ri���ѱ�i->j���Li->Rj�������Ͱ�ͼ�����һ������ͼ�����ѷ��֣�����ͼ������һ���걸ƥ���Ӧ��ԭ���һ��tours��������������ƥ�䣬���Ǳ���Ľ����
*/
#include <stdio.h>
#include <string.h>
#define maxn 200
#define maxm 1000000
#define maxr 10000000

long n/*������*/,m/*����*/;
//����ÿ���㣬info��infor�ֱ�ָ�����������ı߱�͵��������ı߱� 
//����ÿ���ߣ�next��nextr�ֱ�ָ�򡰳����� ���߱�͡�����ı߱����һ����
//from��to��costָһ���ߵ���㣬�յ�ͳ��� 
long info[maxn],next[maxm],infor[maxn],nextr[maxm],from[maxm],to[maxm],cost[maxm],p;
//���� 
long lf[maxn],rf[maxn];
//flag��ʾ��߽ڵ��Ƿ��Ѹǣ�used��ʾ��߽ڵ�ʱ���ѷ��ʣ�used2��ʾ�ұ߽ڵ��Ƿ��ѷ��ʣ�op��ʾ�ұ߽ڵ����ĸ���߽ڵ�ƥ�䣬ft��ʾƥ��Ĵ��ۣ�����ͳ�ƣ� 
long flag[maxn],used[maxn],used2[maxn],op[maxn],ft[maxn];

//�����ҿ�����·����ǰ�ڵ�����ߵ�now 
long dfs (long now) {
    long i;
    
    used[now] = 1;
    
    //�ҵ�һ��δ�ǵ㣬���ɿ�����·�� 
    for (i=info[now];i!=-1;i=next[i])
        if (lf[now] + rf[to[i]] == cost[i] && op[to[i]] == -1) {
            op[to[i]] = now;
            ft[to[i]] = cost[i];
            flag[now] = 1;
            return 1;
            }
    //��һ�η�ƥ��ߺ�һ��ƥ��߼��뽻������������ܷ�ͨ���µ���ĵ�õ�������· 
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
        
        //���룬��ͼ 
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
        
        //���ó�ʼ����        
        for (i=0;i<n;i++) {
            lf[i] = maxr;
            for (j=info[i];j!=-1;j=next[j])
                if (cost[j] < lf[i])
                    lf[i] = cost[j];
            rf[i] = 0;
            }
        
        //��ʼ��������е�δƥ�� 
        memset(flag,0,sizeof(flag));
        memset(op,-1,sizeof(op));
        
        //����ÿ���㣬��ʼƥ�� 
        for (cs=0;cs<n;cs++) {
            memset(used,0,sizeof(used));
            memset(used2,0,sizeof(used2));
            while (!dfs(cs)) {
                //���ƥ�䲻�ɹ������޸Ķ��� 
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
        //ͳ�Ʋ���� 
        a = 0;
        for (i=0;i<n;i++)
            a += ft[i];
        printf("%ld\n",a);
        }
    
    return 0;
    }
