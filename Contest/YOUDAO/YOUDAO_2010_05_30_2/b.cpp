#include <stdio.h>
#define MOD 10000

int pow(int cur,int p)
{
	if(p == 0)
		return 1;
	if(p%2 == 0)
	{
		int tmp = (pow(cur,p/2)%MOD);
		tmp = (tmp*tmp)%MOD;
		return 	tmp;
	}
	else
	{
		int tmp = (pow(cur,p/2)%MOD);
		tmp = ((tmp*tmp)%MOD);
		tmp = (tmp*cur)%MOD;
		return 	tmp;
	}
}

char s[300];
int mid,n;

int get(int st)
{
	if(st > mid)
		return 0;
	int tmp = s[st]-'a';
	int ans = ((tmp)*(pow(26,mid-st)))%MOD;
//	printf("%d %d %d\n",st,tmp,ans);
	ans %= MOD;
	ans += get(st+1);
	ans %= MOD;
	return ans;
}

int main()
{
//	while(scanf("%d",&n)!=EOF)
	{
		scanf("%d",&n);
		mid = n/2;
		if(n%2!=0)
			mid++;
		scanf("%s",s+1);
		if(n == 1)
		{
			printf("%d\n",s[1]-'a'+1);
		//	continue;
		}
		else
		{
		//1 --- n ;
		int ans = get(1);
/*		for(int i=1;i<=mid;i++)
		{
			int tmp = s[i]-'a'-1;
			ans += (tmp * pow(26,mid-i))%MOD;
			ans %= MOD;
			ans += get(i+1);
		}*/
		int st = mid,ed = mid+1;
		if(n%2!=0)
			st --;
		int flag = 1;
		while(st >= 1 && ed <=n)
		{
			if(s[st] < s[ed])
			{
			//	printf("%c%c",s[st],s[ed]);
				flag = 1;
				break;	
			}
			else if(s[st] > s[ed])
			{
				flag = 0;
				break;
			}
			st --;
			ed ++;
		}
		if(flag == 1)
//		if(st<1 && ed > n)
		{
		//	printf("%d\n",ans);
			ans ++;
		}
		ans %= MOD;
		printf("%d\n",ans);
	}
	}
}
