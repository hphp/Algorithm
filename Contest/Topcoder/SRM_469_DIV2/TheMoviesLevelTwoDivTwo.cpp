#include <vector>
using namespace std;
//typedef vector<int> vint;

	int vst[8];
	int rec[8];
	int n;
	int ansk=-1;
	int anss[9] = {0};
class TheMoviesLevelTwoDivTwo
{
	public:
	void dfs(int c,int v,vector<int>l,vector<int> s)
	{
		rec[c] = v;
		bool avl = 1;
		if(c > ansk)
		{
			double start = 74;
			int sec = 0;
			for(int i=0;i<=c;i++)
			{
				if(s[rec[i]] > l[rec[i]])
				{
					double down = l[rec[i]];
					start -= down;
					if(start < -0.5)
					{avl= 0 ; break;}
					sec += l[rec[i]];
				}
				else
				{
					double down = s[rec[i]];
					start -= down;
					if(start < -0.5){
						avl = 0;
						break;
					}
					start += 47;
					start -= (l[rec[i]]-s[rec[i]]);
					if(start < -0.5)
					{
						avl = 0;break;	
					}
					sec += l[rec[i]];
				}
			}
			if(avl)
			{
				for(int i=0;i<=c;i++)
					anss[i] = rec[i];
				ansk = c;
			}
		}
		if(!avl)return;
		for(int i=0;i<n;i++)
			if(!vst[i])
			{
				vst[i] = 1;
				dfs(c+1,i,l,s);
				vst[i] = 0;
			}
	}

	public:
	vector <int> find(vector<int> l, vector<int> s)
	{
		n = l.size();
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				vst[j] = 0;
			vst[i] = 1;
			dfs(0,i,l,s);
		}
			vector<int> rans;
		for(int j=0;j<n;j++)
			vst[j] = 0;
		for(int i=0;i<=ansk;i++)
		{
			rans.push_back(anss[i]);
			vst[anss[i]] =1 ;
		}
		for(int j=0;j<n;j++)
			if(!vst[j])
				rans.push_back(j);
		return rans;
	}
};
