#include <stdio.h>
#include <string>
#include <iostream>
#include <string.h>
using namespace std;

class PalindromesCount
{
	private:
		bool pa(char ss[])
		{
			int s = 0;
			int e = strlen(ss)-1;
			while(s <= e)
			{
				if(ss[s] != ss[e])
					break;
				s++;
				e--;
			}
			if(e % 2 == 1 && s == e + 1)
				return 1;
			if(e%2 == 0 && s == e + 2)
				return 1;
				return 0;
		}
	public:
		int count(string A, string B)		
		{
			int sa = A.length();
			int sb = B.length();
			char s[110];
			int cnt =0;
			for(int i=0;i<=sa;i++)
			{
				int cc = 0;
				while(cc < i)
				{
					s[cc] = A[cc];
					cc ++;
				}
				int ccc = 0;
				while(ccc < sb)
				{
					s[cc] = B[ccc];
					cc ++;
					ccc ++;
				}
				ccc = i;
				while(ccc < sa)
				{
					s[cc++] = A[ccc++];
				}
				s[cc] = '\0';
			//	printf("%s\n",s);
				if(pa(s))
					cnt ++;
			}
			return cnt;
		}
};
/*
int main()
{
	PalindromesCount pc = PalindromesCount();
	string A , B;
	while(cin >> A >> B)
	{
		printf("%d\n",pc.count(A,B));
	}
}

*/
