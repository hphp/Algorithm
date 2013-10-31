#include <iostream>
using namespace std;

const int kind = 26;
struct node
{
    node *fail;       //ʧ��ָ��
    node *next[kind]; //Tireÿ���ڵ��26���ӽڵ㣨���26����ĸ��
    int count;        //�Ƿ�Ϊ�õ��ʵ����һ���ڵ�
    int id;           // �õ�ĵ���id
    node()            //���캯����ʼ��
    {
        fail=NULL;
        count=0;
        id=0;
        memset(next,0,sizeof(next));
    }
}*q[500001];          //���У���������bfs����ʧ��ָ��
int head,tail;        //���е�ͷβָ��
int cnt[151];
const int MAXN = 1 << 10;
const int MAXM = 1 << 10;
const int INF = 0x3fffffff;
class network
{
public:
    void init( int _n, int _s, int _t );		// ��ʼ�������磬n���ڵ㣬Դ��_s�����_t
    inline void addEdge( int a, int b, int c );		// ��ӻ�(a, b)��r[a, b] = c
    int maxFlow();					// �����
private:
    const static int MAXV = 20001;    			// �������ж�����
    const static int MAXE = 800001;        		// �������б�����Ϊʵ��ֵ��2��
    struct node
    {
        int v, f;       				// v ��һ����  f ��������
        node *pair, *next;     				// pair ��Ӧ�ķ����
    };
    node pool[ MAXE ], *pp, *path[ MAXV ], *adj[ MAXV ], *cur[ MAXV ];	// path��¼�������·  adj��¼������  cur��¼��ǰ��
    int n, s, t, d[ MAXV ], num[ MAXV ], pred[ MAXV ];
    inline node *create( int v, int f, node *next )
    {
        pp->v = v;
        pp->f = f;
        pp->next = next;
        return pp++;
    }
    void calDis();					// ���������d
    void augment( int & );				// ���²�������
};
void network::init( int _n, int _s, int _t )
{
    n = _n;
    s = _s;
    t = _t;
    pp = pool;
    pred[ s ] = -1;
    memset( adj, 0, n * sizeof( adj[ 0 ] ) );
    memset( cur, 0, n * sizeof( int ) );
    memset( num, 0, n * sizeof( int ) );
    for ( int i = 0; i < n; i++ )
        d[ i ] = n;
}

void network::addEdge( int a, int b, int c )
{
    adj[ a ] = create( b, c, adj[ a ] );
    adj[ b ] = create( a, 0, adj[ b ] ); //����߶�Ӧ����Ϊ0
    adj[ a ]->pair = adj[ b ];
    adj[ b ]->pair = adj[ a ];
}
void network::calDis()
{
    int que[ MAXV ];
    int head = -1, tail = 0;
    int u;
    d[ t ] = 0;
    que[ tail ] = t;
    while ( head < tail )
    {
        u = que[ ++head ];
        for ( node *p = adj[ u ]; p; p = p->next )
        {
            if ( p->f == 0 && d[ p->v ] == n )
            {
                d[ p->v ] = d[ u ] + 1;
                num[ d[ p->v ] ]++;
                que[ ++tail ] = p->v;
            }
        }
    }
    return;
}

void network::augment( int &sum )
{
    int mini = INF;
    for ( int u = t; u != s; u = pred[ u ] )
       mini = mini < path[ u ]->f ? mini : path[ u ]->f;
    sum += mini;
    for ( int u = t; u != s; u = pred[ u ] )
    {
        path[ u ]->f -= mini;
        path[ u ]->pair->f += mini;
    }
}
int network::maxFlow()
{
    bool update;
    int u = s, res = 0;

    calDis();
    for ( int i = 0; i < n; i++ )
       cur[ i ] = adj[ i ];
    while ( d[ s ] < n )
    {
        update = false;
        for ( node *p = cur[ u ]; p; p = p->next )
        {
            if ( d[ p->v ] + 1 == d[ u ] && p->f > 0 )
            {
                update = true;
                pred[ p->v ] = u;
                path[ p->v ] = p;
                cur[ u ] = p;
                u = p->v;	// ��ǰ������
                if ( u == t )
                {
                    augment( res );
                    u = s;
                }
                break;
            }
        }
        if ( !update )
        {
            if ( --num[ d[ u ] ] == 0 )	// ��϶�Ż�
                break;
            cur[ u ] = adj[ u ];
            d[ u ] = n;
            for ( node *p = adj[ u ]; p; p = p->next )	// �ر��
                if ( p->f > 0 && d[ u ] > d[ p->v ] + 1 )
                    d[ u ] = d[ p->v ] + 1;
            if ( d[ u ] < n )
                num[ d[ u ] ]++;
            if ( u != s )				// �����˲���
                u = pred[ u ];
        }
    }
    return res;
}
network net;
void insert(char *str,int id,node *root)
{
    node *p=root;
    int i=0,index;
    while (str[i])
    {
        index=str[i]-'a';
        if (p->next[index]==NULL) p->next[index]=new node();
        p=p->next[index];
        i++;
    }
    p->count++;
    p->id=id;
}
void build_ac_automation(node *root)
{
    int i;
    root->fail=NULL;
    q[head++]=root;
    while (head!=tail)
    {
        node *temp=q[tail++];
        node *p=NULL;
        for (i=0;i<26;i++)
        {
            if (temp->next[i]!=NULL)
            {
                if (temp==root) temp->next[i]->fail=root;
                else
                {
                    p=temp->fail;
                    while (p!=NULL)
                    {
                        if (p->next[i]!=NULL)
                        {
                            temp->next[i]->fail=p->next[i];
                            break;
                        }
                        p=p->fail;
                    }
                    if (p==NULL) temp->next[i]->fail=root;
                }
                q[head++]=temp->next[i];
            }
        }
    }
}
void query(node *root,char str[])
{
    int i=0,index;
    node *p=root;
    while (str[i])
    {
        index=str[i]-'a';
        while (p->next[index]==NULL && p!=root) p=p->fail;
        p=p->next[index];
        p=(p==NULL)?root:p;
        node *temp=p;
        while (temp!=root && temp->count!=-1)
        {
            cnt[temp->id]+=temp->count;
            temp=temp->fail;
        }
        i++;
    }
}
struct S
{
    int v;
    int c;
    char word[51];
}s[151];
int valuep[151];
char p[151][1001];
int main()
{
    int cas,n,m,N,s2,t,c=1,sum=0;

    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    scanf("%d",&cas);
    while(cas--)
    {
        sum=0;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
           scanf("%d%d%s",&s[i].v,&s[i].c,s[i].word);
        for(int i=0;i<m;i++)
           scanf("%s",p[i]);
        head=tail=0;
        node *root = new node();
        for(int i=0;i<n;i++)
           insert(s[i].word,i,root);
        build_ac_automation(root);
        N=n+m+2;
        s2=N-2;
        t=N-1;
        net.init(N,s2,t);
        for(int i=0;i<m;i++)
        {
            memset(cnt,0,sizeof(cnt));
            query(root,p[i]);
            valuep[i]=0;
            for(int j=0;j<n;j++)
            {
                valuep[i]+=cnt[j]*s[j].v;
                if(cnt[j]!=0)
                   net.addEdge(i,m+j,INF);
            }
        }
        for(int i=0;i<m;i++)
        {
            net.addEdge(s2,i,valuep[i]);
            sum+=valuep[i];
        }
        for(int i=0;i<n;i++)
           net.addEdge(m+i,t,s[i].c);
        printf("Case %d: %d\n",c++,sum-net.maxFlow());
    }
    return 0;
}
