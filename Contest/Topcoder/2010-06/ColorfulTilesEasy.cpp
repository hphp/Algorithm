#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
#define MAX (1<<20)
char st[5] = {"RGBT"};

int getcc(string c , int k)
{
	for(int i=0;i<4;i++)
		if(c[k] == st[i])
			return i;
	return -1;
}
int mn[100][5];

int Min(int a,int b)
{
	return (a < b ? a : b);	
}

class ColorfulTilesEasy
{
	public:
		int theMin(string room)
		{
			int len = room.length();
			mn[0][0] = 0;
			for(int i=1;i<=len;i++)
				for(int j=0;j<4;j++)
					mn[i][j] = MAX;
			for(int i=0;i<4;i++)
				mn[1][i] = 1;
			mn[1][getcc(room,0)] = 0;
			for(int i=2;i<=len;i++)
			{
				int cur = getcc(room,i-1);
				for(int j=0;j<4;j++)
				{
					if(j != cur)
					{
						mn[i][cur] = Min(mn[i][cur],mn[i-1][j]);
					}
				}
				for(int j=0;j<4;j++)
					for(int k=0;k<4;k++)
						if(j!=k)
						{
							mn[i][j] = Min(mn[i-1][k]+1,mn[i][j]);
						}
			}
		}	
};
