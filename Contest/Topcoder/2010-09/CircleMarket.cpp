#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>

using namespace std;



class CircleMarket
{
	public :
	int makePurchases(vector <int> openTime, vector <int> closeTime, int travelTime)	
	{
		int size = openTime.size();
		int time = 0;
		int ans = 0;
		for(int i=0;i<size;i++)
		{
			if(time >= openTime[i] && time <= closeTime[i])
			{
				ans ++;	
			}
			time += travelTime;
		}
		return ans;
	}
};
/*
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		vector<int>oT,cT;
		int t,a;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a);
			oT.push_back(a);
		}
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a);
			cT.push_back(a);
		}
		scanf("%d",&t);
		CircleMarket c = CircleMarket();
		printf("%d\n",c.makePurchases(oT,cT,t));
	}
}*/
/*
19:13
3
999999 2 4
1000000 22 44
2
*/

