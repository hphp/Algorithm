#include <vector>
using namespace std;
#define STM 65538
#define MAX (1<<28) 
#define N 18 
#define M 53 
int mn[STM];
int lst[STM];
int tail;
struct State 
{
	int lu,rd;
}state[N*N];
int cs;
int mnc[STM];
int plan[STM],cp;

class SquaresCovering
{
	public:
		int minCost(vector<int> x,vector<int> y,vector<int> c,vector<int> s)
		{
			int n = x.size();
			int cs = 0;
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					if(x[i] <= x[j])
						if(y[i] >= y[j])
							state[cs].lu = i,state[cs].rd = j , cs++;
			int m = c.size();
			int stm = (1<<(n+1));
			for(int i=0;i<stm;i++)
				mnc[i] = MAX , mn[i] = 0;
			for(int i=0;i<cs;i++)
				for(int j=0;j<m;j++)
				{
					int lu = state[cs].lu;
					int rd = state[cs].rd;
					int cstm  = (1<<lu) + (1<<rd);
					for(int k=0;k<n;k++)
					{
						if(((x[k]-x[lu]) <= s[j]) && (y[k]-y[rd] <= s[j]))
							cstm += (1<<k);
					}
					if(mnc[cstm] > c[j])
						mnc[cstm] = c[j];
				}
			for(int i=0;i<stm;i++)
				if(mnc[i] < MAX)
					plan[cp++] = i;
			tail = 0;
			lst[tail++] = 0;
			mn[0] = 0;
			for(int i=0;i<cp;i++)
			{
				int ct = tail;
				for(int jj=0;jj<ct;jj++)	
				{
					int j = lst[jj];
					if(mn[j|plan[i]] == MAX)
					{
						lst[tail++] = j|plan[i];
						mn[j|plan[i]] = mn[j] + mnc[plan[i]];
					}
					else if(mn[j] + mnc[plan[i]] < mn[j|plan[i]])
					{
						mn[j|plan[i]] = mn[j] + mnc[plan[i]];
					}
				}
			}
			return mn[stm-1];
		}
};
