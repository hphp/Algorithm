#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>

using namespace std;
#define N 810
#define K 9
typedef long long Int;
Int C[N][K] = {0},SC[N][K] = {0},A[N][K] = {0}, P[N][K] = {0};

void booling()
{
	C[0][0] = 1;
	for(int i=1;i<=N;i++)
	{
		C[i][0] = 1;
		A[i][0] = 1;
		P[i][0] = 1;
		for(int j=1;j<=i&&j<K;j++)
		{
			C[i][j] = C[i-1][j]+C[i-1][j-1];
			SC[i][j] = SC[i][j-1]+C[i][j];
			A[i][j] = A[i][j-1]*(i-j+1);
			P[i][j] = P[i][j-1]*i;
		}
	}
}

struct Node
{
	Int r;
	char s[1000];
}node[N];

bool cmp(Node a, Node b)
{
	if(a.r < b.r)
		return 1;
	if(a.r > b.r)
		return 0;
	if(strcmp(a.s,b.s)<0)
		return 1;
		return 0;	
}

class Lottery
{
	public:
		vector <string> sortByOdds(vector <string> rules)
		{
			booling();
			int s = rules.size();
			char s1[10],s2[10],ss[100],rr[101];
			int a,b;
			for(int i=0;i<s;i++)
			{
				int ll = rules[i].length();
				for(int j=0;j<ll;j++)
				{
					ss[j] = rules[i][j];
				}
				ss[ll] = '\0';
//				printf("%s\n",ss);
				int j=0;
				for(;j<ll;j++)
					if(ss[j]!=':')
					{
						rr[j] = ss[j];
					}
					else break;
				rr[j] = '\0';
				strcpy(node[i].s,rr);
//				printf("hello rr %s %s\n",rr,node[i].s);
				sscanf(ss+j,": %d %d %s %s",&a,&b,s1,s2);
//				printf("%s:%d*%d*%s*%s\n",node[i].s,a,b,s1,s2);
				if(s1[0] == 'F')
				{
					if(s2[0] == 'F')
						node[i].r = P[a][b];
					else node[i].r = A[a][b];
				}
				else if(s1[0] == 'T')
				{
					if(s2[0] == 'T')
					{
						node[i].r = C[a][b];
					}
					else if(s2[0] == 'F')
					{
						Int sum =0;
						for(int j=1;j<=b;j++)
							sum += (C[a][j]*C[b-1][j-1]);
						node[i].r = sum;	
					}
				}
			}
			sort(node,node+s,cmp);
			vector<string> ans;
			for(int i=0;i<s;i++)
			{
				string aa = node[i].s;
				ans.push_back(aa);
			}
			return ans;
		}		
};
/*
int main()
{
	booling();
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)	
	{
		printf("%I64d\n",C[a][b]);
		Int sum =0;
		for(int i=1;i<=b;i++)
			sum += (C[a][i]*C[b-1][i-1]);
		printf("%I64d\n",sum);
	}
}*/
