#include <string>
#define Min(a,b) ((a)<(b) ? (a):(b))
using namespace std;

class DoorsGame
{
	private:
	public:
		int determineOutcome(string,int);
};

int DoorsGame::determineOutcome(string s,int f)
{
	int size = s.size();
	int c = 0 , d1 = 0 , d2 = 0;
	for(char cc = 'A' ; cc <= 'P' ; cc++)
	{
		int x = 0 , y = 0;
		for(int i=0;i<f;i++)
			if(cc == s[i])x = 1;
		for(int i=f;i<size;i++)
			if(cc == s[i])y = 1;
		if(x+y == 2) c ++;
		else
		{
			d1 += x;
			d2 += y;	
		}
	}
//	printf("%d %d %d\n",d1,d2,c);
	if(c == 0)
	{
		if(d1 <= d2)
			return d1+d1-1;
		else return -2*d2;
	}
	else
	{
		if(d1 == d2)
			return 0;
		else
		{
			if(d1 < d2)
			{
				if(d2 - d1 >= c)	
					return 2*(d1+c) - 1;
				else return 0;
			}
			else
			{
				if(d1 - d2 <= c)
					return 0;
				else return -2*(d2+c);
			}
		}
	}
}
/*
int main()
{
	char s[20];
	int n;
	while(scanf("%s%d",s,&n)!=EOF)
	{	
		DoorsGame a = DoorsGame();
		printf("%d\n",a.determineOutcome(s,n));
	}
	return 0;
}
*/
