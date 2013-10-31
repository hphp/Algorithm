#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> a;
int main()
{
    int sum;
    int n,i,j,k,tmp,z;
    //freopen("data.in","r",stdin);
    z=0;
    //freopen("data.out","w",stdout);
    while(scanf("%d",&n)!=EOF)
    {
        a.clear();
        for(i=0;i<n;i++)
        {
            scanf("%d",&j);
            a.push_back(j);
        }
        sort(a.begin(),a.end());
        //a.erase(unique(a.begin(),a.end()),a.end());//del duplicate ones nearby.sort required
        sum=0;
        for(i=0;i<a.size();i++)
        {
            k=0;tmp=a[i];
            if (i>0&&a[i]==a[i-1]) continue;
                while (tmp)//lowbit
                {
                    k++;
                    tmp=(tmp&(tmp-1));
                }
            if (k%2==0) {sum=sum^(2*a[i]+1);}
            else {sum=sum^(2*a[i]);}
        }
        //printf("%d\n",sum);
        if (sum>0) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
