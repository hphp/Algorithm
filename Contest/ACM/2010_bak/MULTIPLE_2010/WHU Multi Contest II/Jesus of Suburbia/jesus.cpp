#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <fstream>

#define Loop 14121413LL
#define cin fin
#define cout fout

using namespace std;


class cube
{
    public:
        int s[10],b[10];
        cube()
        {memset(s,0,sizeof(s));memset(b,0,sizeof(b));}
};

int n,m;
int CN;
cube C[50005];
cube D[50005];
cube t;
int DN;
long long ans;

void insD(cube tmp)
{
    long i;
    for(i=0;i<m;i++) if(tmp.s[i]>=tmp.b[i]) return ;
    D[++DN]=tmp;
}

void broke(cube p,cube q)
{
    long i;
    t=p;
    cube tmp;
    for(i=0;i<m;i++)
    {
        if(t.s[i]<=q.s[i] && q.s[i]<=t.b[i])
        {
            tmp=t;
            tmp.b[i]=q.s[i];
            insD(tmp);
            t.s[i]=q.s[i];
        }
        if(t.s[i]<=q.b[i] && t.b[i]>=q.b[i])
        {
            tmp=t;
            tmp.s[i]=q.b[i];
            insD(tmp);
            t.b[i]=q.b[i];
        }
    }
}

bool check(cube p,cube q)
{
    long i;
    for(i=0;i<m;i++)
        if(p.s[i]>=q.b[i] || p.b[i]<=q.s[i]) return 0;
    return 1;
}

void insert(cube p)
{
    long i;
    DN=0;
    for(i=1;i<=CN;i++)
        if(check(C[i],p))broke(C[i],p);
        else D[++DN]=C[i];
    CN=0;
    C[++CN]=p;
    for(i=1;i<=DN;i++)
        C[++CN]=D[i];
}


void init()
{
    long i,j;
    CN = 0;
    DN = 0;
    long long k;
    cube tmp;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<m;j++)
            scanf("%d",&tmp.s[j]);
        for(j=0;j<m;j++)
            scanf("%d",&tmp.b[j]);
        insert(tmp);
    }
    ans = 0;
    for(i=1;i<=CN;i++)
    {
        k=1;
        for(j=0;j<m;j++)
            k=(long long)k*(long long)(C[i].b[j]-C[i].s[j])%Loop;
        ans=(ans+k)%Loop;
    }
    printf("%I64d\n",ans);
}

int main()
{
    freopen ("jesus.out", "w", stdout);
    while(scanf("%d%d",&n,&m)!=EOF)
        init();
    return 0;
}
