#include<stdio.h>
#include<string.h>
const int MAX=22;
const int MOD=1000000007;
typedef __int64 lld;

int ret[MAX][MAX];
int mat[MAX][MAX];
void multi(int a[MAX][MAX],int b[MAX][MAX],int n)
{
	int i,j,k;
	lld c[MAX][MAX]={0};
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			for(k=0;k<n;k++)
			{
				c[i][j]+=(lld)a[i][k]*(lld)b[k][j];
				c[i][j]%=MOD;
			}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			a[i][j]=(lld)c[i][j];
}
int main()
{
	int i,x,y,z,n;
	//freopen("save.in","r",stdin);
	//freopen("save.out","w",stdout);
	while(scanf("%d%d%d%d",&x,&y,&z,&n)!=EOF)
	{
		
		memset(ret,0,sizeof(ret));
		memset(mat,0,sizeof(mat));
		for(i=0;i<z;i++)
			ret[i][i]=1;
		for(i=x-1;i<y;i++)
			mat[0][i]++;
		for(i=1;i<z;i++)
			mat[i][i-1]++;
		while(n)
		{
			if(n&1)multi(ret,mat,z);
			multi(mat,mat,z);
			n>>=1;
		}
		lld ans=0;
		for(i=1;i<z;i++)
			ans+=(lld)ret[i][0];
		printf("%I64d\n",ans%MOD);
	}
	return 0;
}
