#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#define MAX (1<<28)
#define Max(a,b) ((a)>(b)?(a):(b))
using namespace std;
#define S 510
char s[S];
typedef long long Int;
Int bit[S][S];
int mx[S][S];
int n;
char cur[59] = "";
int contain[S][S][26];
class SubAnagrams
{
	public:
		int maximumParts(vector <string> sW)
		{
			s[0] = '\0';
			s[1] = '\0';
			int n = sW.size();
			for(int i=0;i<n;i++)
			{
				cur[0] = '\0';
				for(int j=0;j<sW[i].length();j++)
					cur[j] = sW[i][j];
				cur[sW[i].length()] = '\0';
				strcpy(s+1+strlen(s+1),cur);
			}
//			printf("%s\n",s+1);
			int len = strlen(s+1);
			for(int i=1;i<=len;i++)
			{
				for(int j=i;j<=len;j++)
				{
					bit[i][j] = 0;
					for(int k=0;k<26;k++)
						contain[i][j][k] = 0;
					for(int k=i;k<=j;k++)
					{
//						Int c = 1<<(s[k]-'A');
//						bit[i][j] = bit[i][j] | c;
						contain[i][j][s[k]-'A'] ++;
					}
//					printf("%lld ",bit[i][j]);
				}
//				printf("\n");
			}
			for(int i=0;i<=len;i++)
				for(int j=0;j<=len;j++)
					mx[i][j] = -MAX;
			for(int i=1;i<=len;i++)
				mx[i][1] = 1;
			int fff[S];
			for(int i=0;i<S;i++)
				fff[i] = 1;
			for(int i=2;i<=len;i++)
			{
				for(int j=2;j<=i;j++)
				{
					int k = j-1;
					for(k=j-1;k>=fff[j];k--)
					{
						bool flag = 0;
						for(int l = 0 ; l < 26; l ++)
							if(contain[j][i][l] < contain[k][j-1][l])
							{
								flag = 1;break;
							}
						if(!flag)
							mx[i][j] = Max(mx[i][j],mx[j-1][k] + 1);
						else break;
					/*	if((bit[k][j-1] & bit[j][i]) == bit[k][j-1])
							*/
					}
					fff[j] = k;
				}
			}
			int ans = -MAX;
			int last = -1;
			for(int j=1;j<=len;j++)
			{
				if(mx[len][j] > ans)
					last = j;
				ans = Max(ans,mx[len][j]);
			}
		/*	int f = len;
			while(f > 0)
			{
				for(int j=last;j<=f;j++)
					printf("%c",s[j]);
				printf("\n%d %d\n",last,f);
				int nlast = -1;
				for(int k=1;k<last;k++)
					if(mx[last-1][k] + 1 == mx[f][last])
						nlast = k;
				f = last-1;
				last = nlast;
			}*/
			return ans;
		}
};
/*
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		vector <string> v;
		for(int i=0;i<n;i++)	
		{
			scanf("%s",s);
			string c = s;
			v.push_back(c);
		}
		SubAnagrams sa = SubAnagrams();
		printf("%d\n",sa.maximumParts(v));
	}
}*/
