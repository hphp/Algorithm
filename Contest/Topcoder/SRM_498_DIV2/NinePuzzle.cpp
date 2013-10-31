#include<string>
#include<map>
using namespace std;

int sz[10] = {2,4,4,4,6,4,2,4,4,2};
int mv[10][8] = 
{
	{2,3},
	{1,3,4,5},
	{1,2,5,6},
	{2,5,7,8},
	{2,3,4,6,8,9},
	{3,5,9,10},
	{4,8},
	{4,5,7,9},
	{5,6,8,10},
	{6,9}
};

char stdd[10] = {"RGBY"};
int p5[11];
void init()
{
	p5[0] = 1;
	for(int i=1;i<11;i++)
		p5[i] = p5[i-1]*5;
}

//int queue[20000000];

class NinePuzzle
{
/*	int bfs(int sstm, int estm)
	{
		map<int,int> step;
		int s = 0 ; 
		int e = 1;
		queue[s] = sstm;
		step[sstm] = 1;
		while(s < e)
		{
			int cstm = queue[s];
			if(cstm == estm)
				return step[cstm]-1;
			int tmp = cstm;
			int cc = 0;
			int rec[13];
			while(tmp)
			{
				int c = tmp%5;
				rec[cc] = c;
				tmp/=5;
				cc ++;
			}
			int nn;
			for(int i=0;i<cc;i++)
				if(!rec[cc])
					nn = cc;
			for(int i=0;i<sz[nn];i++)
			{
				int nx = mv[nn][i]-1;
				int nstm = cstm-rec[nx]*p5[nx] + rec[nx]*p5[nn];
				if(step[nstm] == 0)
				{
					step[nstm] = step[cstm]+1;
					queue[e++] = nstm;
				}
			}
			s ++;
		}
		return -1;
	}*/
	int rec[2][4];
	public:
		int getMinimumCost(string init,string goal)
		{
/*			init();
			int len = init.length();
			int istm = 0;
			for(int i = 0 ; i < len ; i ++)
			{
				int cur = 0;
				for(int j=0;j<4;j++)
					if(init[i] == stdd[j])
						cur = j+1;
				istm*=5;
				istm += cur;
			}
			len = goal.length();
			int fstm = 0;
			for(int i = 0 ; i < len ; i ++)
			{
				int cur = 0;
				for(int j=0;j<4;j++)
					if(goal[i] == stdd[j])
						cur = j+1;
				fstm*=5;
				fstm += cur;
			}
			int ans = bfs(istm,fstm);
			*/
			for(int i=0;i<2;i++)
				for(int j=0;j<4;j++)
					rec[i][j] = 0;
			for(int i=0;i<init.length();i++)
			{
				if(init[i]!='*')
				{
					int r = 0;
					for(int j=0;j<4;j++)
						if(init[i] == stdd[j])
							r = j;
					rec[0][r] ++;
				}
			}
			for(int i=0;i<goal.length();i++)
			{
				if(goal[i]!='*')
				{
					int r = 0;
					for(int j=0;j<4;j++)
						if(goal[i] == stdd[j])
							r = j;
					rec[1][r] ++;
				}
			}
			int ans = 0;
			for(int j=0;j<4;j++)
			{
				if(rec[1][j] > rec[0][j])	
					ans += rec[1][j]-rec[0][j];
			}
			return ans;
		}
};
