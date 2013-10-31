#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>

using namespace std;
//flag 4 : 0The egg
//The chicken
//Ambiguous
//The oracle is a lie
//

string ans[4];
char s[4][20] = {
	"The egg","The chicken","Ambiguous","The oracle is a lie"
	};

class ChickenOracle
{
	public:
	string theTruth(int n, int eggCount, int lieCount, int liarCount)	
	{
		for(int i=0;i<4;i++)
			ans[i] = s[i];
		int flag[4] = {1,1,1,1};
		int x,y,z,w;
		int truth = eggCount;
		int part = truth + liarCount+lieCount-n ;
		if((part <= n) && (part>= 0) && ((part%2)== 0))
		{
			w = part/2;
			if(liarCount >= w)
			{
				y = liarCount-w;
				if((y >= 0)&&( y <= liarCount)&&(truth >= w))
				{
					x = truth - w;	
					if((x >= 0)&&(x <=truth)&&(lieCount >= w))
					{
						z = lieCount - w;
						if((z >= 0)&&(z <= lieCount));
						else flag[0] = 0;
					}
					else flag[0] = 0;
				}
				else flag[0] = 0;
			}
			else flag[0] = 0;
		}
		else flag[0] = 0;
		
		truth = n-eggCount;
		part = truth + liarCount+lieCount-n ;
		
		if((part <= n) && (part>= 0) && ((part%2)== 0))
		{
			w = part/2;
			if(liarCount >= w)
			{
				y = liarCount-w;
				if((y >= 0)&&( y <= liarCount)&&(truth >= w))
				{
					x = truth - w;	
					if((x >= 0)&&(x <=truth)&&(lieCount >= w))
					{
						z = lieCount - w;
						if((z >= 0)&&(z <= lieCount));
						else flag[1] = 0;
					}
					else flag[1] = 0;
				}
				else flag[1] = 0;
			}
			else flag[1] = 0;
		}
		else flag[1] = 0;
		
		
		if(flag[0] == 1 && flag[1] == 1)
		{
			flag[2] = 1;
		}
		else flag[2] = 0;
		if(flag[0] == 0 && flag[1] == 0)
		{
			flag[3] = 1;
		}
		else flag[3] = 0;
		if(flag[2])
		{
			return ans[2];
		}
		if(flag[3])
			return ans[3];
		for(int i=0;i<2;i++)
			if(flag[i])
				return ans[i];
		return ans[3];
	}
};

/*int main()
{
	int a,b,cc,d;
	while(scanf("%d%d%d%d",&a,&b,&cc,&d)!=EOF)
	{
		ChickenOracle c = ChickenOracle();
		cout << c.theTruth(a,b,cc,d) << endl;
	}
}*/
/*
10
10
0
0

60
40
0
30

60
20
5
25

1000
500
250
250
*/
