#include <cstdio>
#include <cstring>
#define N 121
#define M 31
#define MAX 121*31

int s[M],mat[N][M],ansq[N],u[MAX],d[MAX],l[MAX],r[MAX],c[MAX];
int nbmat[M][4],cntd[M];

void build(int n,int m)
{
    r[0]=1;
    l[0]=m;
    for(int i=1;i<=m;i++)
    {
        l[i]=i-1;
        r[i]=(i+1)%(m+1);
        c[i]=d[i]=u[i]=i;
        s[i]=0;
    }
    int size=m;
    for(int i=1;i<=n;i++)
    {
        int rp=0;
        for(int j=1;j<=m;j++)
            if(mat[i-1][j-1])
            {
                size++;
                d[u[j]]=size;
                u[size]=u[j];
                d[size]=j;
                u[j]=size;
                if(!rp)
                {
                    rp=size;
                    l[size]=size;
                    r[size]=size;
                }
                else
                {
                    l[size]=l[rp];
                    r[size]=rp;
                    r[l[rp]]=size;
                    l[rp]=size;
                }
                c[size]=j;
                s[j]++;
            }
    }
}

inline void cover(int pc)
{
    r[l[pc]]=r[pc];
    l[r[pc]]=l[pc];
    for(int i=d[pc];i!=pc;i=d[i])
        for(int j=r[i];j!=i;j=r[j])
        {
            u[d[j]]=u[j];
            d[u[j]]=d[j];
            s[c[j]]--;
        }
}

inline void resume(int pc)
{
    for(int i=u[pc];i!=pc;i=u[i])
        for(int j=l[i];j!=i;j=l[j])
        {
            d[u[j]]=j;
            u[d[j]]=j;
            s[c[j]]++;
        }
    l[r[pc]]=pc;
    r[l[pc]]=pc;
}

int ans;

void dfs(int dep)
{
    if(!r[0])
    {
        ans=dep;
        return;
    }
    if(dep+1>=ans)
        return;
    int pc,mins=N;
    for(int i=r[0];i;i=r[i])
        if(mins>s[i])
        {
            mins=s[i];
            pc=i;
        }
    cover(pc);
    for(int rp=d[pc];rp!=pc;rp=d[rp])
    {
        for(int i=r[rp];i!=rp;i=r[i])
            cover(c[i]);
        dfs(dep+1);
        for(int i=l[rp];i!=rp;i=l[i])
            resume(c[i]);
    }
    resume(pc);
}

int main()
{
    int n,m;
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(nbmat,0,sizeof(nbmat));
        memset(mat,0,sizeof(mat));
        memset(cntd,0,sizeof(cntd));
        int a,b;
        for(int j=0;j<m;j++)
        {
            scanf("%d%d",&a,&b);
            nbmat[a-1][cntd[a-1]++]=b-1;
            nbmat[b-1][cntd[b-1]++]=a-1;
        }
        int cntr=0;
        for(int i=0;i<n;i++)
            for(int j=(1<<cntd[i])-1;j>=0;j--)
            {
                mat[cntr][i]=1;
                for(int k=0;k<cntd[i];k++)
                    if((1<<k)&j)
                        mat[cntr][nbmat[i][k]]=1;
                cntr++;
            }
        ans=n;
        build(cntr,n);
        dfs(0);
        printf("%d\n",ans);
    }
    return 0;
}

