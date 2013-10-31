#include <stdio.h>
#include <string.h>
#define MAX 210

struct box{
	int to,c;
	box *s;
}edge[MAX << 1],*h[MAX],*cur;
int w[MAX],dp[3][MAX][MAX];
void addEdge(int x,int y,int c){
	cur->to = y,cur->c = c;
	cur->s = h[x],h[x] = cur++;
}
void dfs(int x,int f){
	w[x] = 1;
	int i,j,c,y,cd;
	for (c = 0;c < 3;c++)
		dp[c][x][1] = 0;
	for (box *p = h[x];p;p = p->s)
		if (p->to != f){
			dfs(y = p->to,x);
			for (i = w[x];i >= 1;i--)
				for (c = 0;c < 3;c++)
					if (dp[c][x][i] > -1)
						for (j = 1;j <= w[y];j++){
							if (dp[0][y][j] > -1){
								cd = dp[c][x][i]+p->c*2+dp[0][y][j];
								if (cd < dp[c][x][i+j] || dp[c][x][i+j] == -1)
									dp[c][x][i+j] = cd;
							}
							if (c < 2 && dp[1][y][j] > -1){
								cd = dp[c][x][i]+p->c+dp[1][y][j];
								if (cd < dp[c+1][x][i+j] || dp[c+1][x][i+j] == -1)
									dp[c+1][x][i+j] = cd;
							}
							if (c == 0 && dp[2][y][j] > -1){
								cd = dp[0][x][i]+p->c*2+dp[2][y][j];
								if (cd < dp[2][x][i+j] || dp[2][x][i+j] == -1)
									dp[2][x][i+j] = cd;
							}
						}
			w[x] += w[y];
		}
}
int main(){
	int T,tc,n,P,x,y,c,i;
	int Q,s,t,d,cP;
	scanf("%d",&T);
	for (tc = 1;tc <= T;tc++){
		memset(h,0,sizeof(h));
		cur = edge;
		scanf("%d%d",&n,&P);
		for (i = 1;i < n;i++){
			scanf("%d%d%d",&x,&y,&c);
			addEdge(x,y,c);
			addEdge(y,x,c);
		}
		memset(dp,-1,sizeof(dp));
		dfs(1,-1);
		for (i = 2;i <= n;i++)
			for (c = 1;c <= w[i];c++)
				if (dp[2][i][c] < dp[2][1][c])
					dp[2][1][c] = dp[2][i][c];
		scanf("%d",&Q);
		printf("Case %d:\n",tc);
		while (Q--){
			scanf("%d",&x);
			s = 0,t = n+1;
			while (s+1 < t){
				d = (s+t) >> 1;
				cP = x*d+dp[2][1][d];
				if (cP <= P) s = d;
				else t = d;
			}
			printf("%d\n",s);
		}
	}
}
