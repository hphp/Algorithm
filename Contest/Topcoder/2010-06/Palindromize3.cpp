#include<stdio.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;
#define L 30

struct Rec
{
	int id;
	int v;	
}rec[L];

bool cmp(Rec a, Rec b)
{
	if(a.v > b.v)
		return 1;
	if(a.v < b.v)
		return 0;
	if(a.id < b.id)
		return 1;
		return 0;
}

class Palindromize3
{
	public:
		string getPalindrome(string s)
		{
			int len = s.length();
			int mid = len/2;
			int lst = len-1;
			for(int i=0;i<L;i++)
			{
				rec[i].id = i , rec[i].v=0;
//				for(int j=0;j<len;j++)
//					map[j][i] = 0;
			}
			for(int i=0;i<mid;i++)
			{
				if(s[i] != s[lst])
				{
					rec[s[i]-'a'].v++;
					rec[s[lst]-'a'].v++;
//					map[s[i]-'a'][i]=1;
//					map[s[lst]-'a'][lst]=1;
				}
				lst --;
			}
			sort(rec,rec+L,cmp);
			int cnt = 0;
			while(cnt < L)
			{
				int id = rec[cnt].id;
				int lst = len-1;
				for(int i=0;i<mid;i++)
				{
					if(s[i]-'a' == id)
					{
						s[lst]=id+'a';
					}
					else if(s[lst]-'a' == id)
					{
						s[i]=id+'a';
					}
					lst--;
				}
				cnt ++;
			}
		//	cout << s << endl;
			return s;
		}
};

/*
int main()
{
	string s;
	while(cin >> s)
	{
		Palindromize3 p = Palindromize3();
		cout << p.getPalindrome(s) << endl;
	}
	return 0;
}
*/
