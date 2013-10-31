#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int a[4][8] = 
{
	{1,2,3,4,5,6,7,8},
	{1,2,3,4,9,10,11,12},
	{
		1, 2, 5, 6, 9, 10, 13 ,14
	},
	{1, 3, 5, 7, 9, 11, 13 , 15}
};
int sign[16];
int stm[6];

class NumberMagicEasy
{
	public:
		int theNumber(string answer)
		{
			//			cout << answer << endl;
			for(int j=0;j<4;j++)
			{
				stm[j] = 0;
				for(int i=0;i<8;i++)
				{
					stm[j] = stm[j] | (1<<(a[j][i]-1));
				}
			}
			for(int i=0;i<16;i++)
				sign[i] = 0;

			for(int i=0;i<4;i++)
			{
				if(answer[i] == 'Y')
				{
					for(int j=0;j<15;j++)
					{
						if(((1<<j) & stm[i]) == (1<<j))
						{
							/*	if(sign[j] == 0)
								sign[j] = 1;*/
						}
						else sign[j] = -1;
					}
				}
				if(answer[i] == 'N')
				{
					for(int j=0;j<15;j++)
					{
						if(((1<<j) & stm[i]) == (1<<j))
						{
							sign[j] = -1;
						}
						else 
						{
							/*if(sign[j] == 0)
							  sign[j] = 1;*/
						}
					}
				}
			}
			int ans = 16;
			for(int i=0;i<15;i++)
				if(sign[i] == 0)
					ans = i+1;
			return ans;
		}
};
/*
   int main()
   {
   char s[19];
   while(scanf("%s",s)!=EOF)	
   {
   string ss = s;
   NumberMagicEasy n = NumberMagicEasy();
   printf("%d\n",n.theNumber(ss));
   }
   return 0;
   }*/
