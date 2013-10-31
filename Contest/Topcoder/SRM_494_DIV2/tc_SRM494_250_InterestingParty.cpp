#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
#define N 110

string rec[N];

class InterestingParty
{
	public:
	int bestInvitation(vector <string> first, vector <string> second)
	{
		int n = first.size();
		int cnt = 0;
		for(int i=0;i<n;i++)
		{
			int j;
			for(j=0;j<cnt;j++)
			{
				if(first[i] == rec[j])
					break;
			}
			if(j == cnt)
			{
				rec[cnt++] = first[i];
			}
		}
		for(int i=0;i<n;i++)
		{
			int j;
			for(j=0;j<cnt;j++)
			{
				if(second[i] == rec[j])
					break;
			}
			if(j == cnt)
			{
				rec[cnt++] = second[i];
			}
		}
		int mx = 1;
		for(int i=0;i<cnt;i++)
		{
			int count = 0;
			for(int j=0;j<n;j++)
			{
				int aa = 0;
				if(rec[i] == first[j])
					aa = 1;
				if(rec[i] == second[j])
					aa = 1;
				count += aa;
			}
			if(count > mx)
				mx = count;
		}
		return mx;
	}
};
/*
2011-01-23
01:02 - 01 : 11 - > submit -- the result is ok .
*/
