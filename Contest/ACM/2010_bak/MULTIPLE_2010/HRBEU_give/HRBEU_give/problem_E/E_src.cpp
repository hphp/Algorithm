#include<stdio.h>
#include<iostream>
#define N 100005
#define INF 10000000
using namespace std;
int r[N],l[N],stack[N],h[N];
typedef struct
{
    int l, r;
    int max;
}Node;
Node node[3 * N];

void built(int l, int r, int step)
{   
    node[step].l = l;
    node[step].r = r;
    if(l == r)
    {   
        node[step].max = h[l];
        return;
    }
    int mid = (l + r) >> 1;
    built(l, mid, 2 * step);
    built(mid + 1, r, 2 * step + 1);
    node[step].max = node[2 * step].max > node[2 * step + 1].max ? node[2 * step].max : node[2 * step + 1].max;
}

void find(int l, int r, int step, int &max_t)
{   
    if(l <= node[step].l && r >= node[step].r)
    {
        if(node[step].max > max_t)
            max_t = node[step].max;
        return;
    }
    int mid = (node[step].l + node[step].r) >> 1;
    if(l <= mid) find(l, r, 2 * step, max_t);
    if(r > mid) find(l, r, 2 * step + 1, max_t);
}

int main()
{
    freopen("E_in.txt", "r", stdin);
    freopen("E_out.txt", "w", stdout);
    
    int n, k, m;
    
    while(scanf("%d%d%d",&n, &m, &k)!=EOF)
    {   
        for(int i = 1; i <= n;i++)
            scanf("%d",&h[i]);
            
        built(1, n, 1);
        int bottom = 1,top=1;
        stack[0] = 0;
        stack[1] = 1;
        h[0] = 0;
        for(int i = 1; i <= n; ++i)
        {    
             while(top >= bottom && (h[i] < h[stack[top]] || h[stack[top]] - h[i] > k)) 
                r[stack[top--]] = i - 1;
             while(bottom <= top && h[i] - h[stack[bottom]] > k)
                r[stack[bottom++]] =i - 1;       
             stack[++top]=i;
        }
        for(int i = bottom; i <= top; ++i)
          r[stack[i]] = stack[top];
        top = 1;
        bottom = 1;
        stack[1] = n;
        for(int i = n - 1; i >= 1; --i)
        {
              while(top >= bottom && (h[i]<h[stack[top]] || h[stack[top]] - h[i] > k))
                 l[stack[top--]]=i+1;
              while(bottom <= top && h[i] - h[stack[bottom]] > k)
                l[stack[bottom++]] = i + 1;
              stack[++top]=i;
        }
        for(int i = bottom; i <= top; ++i)
           l[stack[i]] = stack[top];
        int max_t, ans = 0;
        for(int i = 1; i <= n; ++i)
        {
            max_t = -1;
            find(l[i], r[i], 1, max_t);
            if(max_t - h[i] >= m && r[i] - l[i] + 1 > ans)
            {
                ans = r[i] - l[i] + 1;
            }
        }
        printf("%d\n", ans);
    }
}
