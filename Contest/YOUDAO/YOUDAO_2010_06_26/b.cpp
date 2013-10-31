#include <stdio.h>
#include <vector>
#define FB {flag = 0 ; break;}
#include <algorithm>
#define NN 110
#define MM 110
#define QQ 1010

struct Dish
{
	int p,tc,te,td;
}dish[NN];

struct DoD
{
	int u,v;
};
/*struct COOK
{
	vector<DoD> can;
}cook[MM];*/

struct Want
{
	int g,h;
};
struct CSTM
{
	int come;
	std::vector<Want> want;
}cstm[QQ];
//Want wlim[QQ][M];
int n,m,q;
//int can[MM][NN],will[MM][NN];
struct PlanD
{
	int id,tc,ts;
};
struct Plan
{
	int iff;
	std::vector<PlanD> pd;
}plan[QQ];

struct DOCOOK
{
	int id,tc,ts;
}dcc[QQ*MM];
bool cmp(DOCOOK a , DOCOOK b)
{
	if(a.tc < b.tc)
		return 1;
	if(a.tc > b.tc)
		return 0;
	if(a.id < b.id)
		return 1;
	return 0;
}
struct CookDo
{
	std::vector<DOCOOK> dc;
}cookdo[QQ];

int mxdo[MM][NN];

int main()
{
	int a,b,c,d,e,u,v,g,h;
	while(scanf("%d%d%d",&n,&m,&q)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d%d",&dish[i].p,&dish[i].tc,&dish[i].te,&dish[i].td);
			//printf("%d\n",dish[1].tc);
		}
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				mxdo[i][j] = 0;
		for(int i=0;i<m;i++)
		{
			scanf("%d",&a);
			for(int j=0;j<a;j++)
			{
				scanf("%d%d",&u,&v);
				mxdo[i][u] = v;
			}
		}
		for(int i=0;i<q;i++)
		{
			scanf("%d",&cstm[i].come);
			scanf("%d",&e);
			cstm[i].want.clear();
			for(int j=0;j<e;j++)
			{
				scanf("%d%d",&g,&h);
				Want w = {g,h};
				cstm[i].want.push_back(w);
			}
		}
		int x;
		scanf("%d",&x);
		for(int i=0;i<m;i++)
			cookdo[i].dc.clear();
		for(int i=0;i<q;i++)
		{
			scanf("%d",&plan[i].iff);
			plan[i].pd.clear();
			if(plan[i].iff==0)continue;
			int ss = cstm[i].want.size();
			for(int j=0;j<ss;j++)
			{
				int id,tc,ts;
				scanf("%d%d%d",&id,&tc,&ts);
				int did = cstm[i].want[j].g;
				DOCOOK dc = {did,tc,ts};
				cookdo[id].dc.push_back(dc);
				PlanD pp = {id,tc,ts};
				plan[i].pd.push_back(pp);
			}
		}
		int sum =0;
		int flag = 1;
		for(int i=0;i<q;i++)
			if(plan[i].iff)
				for(int j=0;j<cstm[i].want.size();j++)
					sum += dish[cstm[i].want[j].g].p;
		if(sum != x)
			flag = 0;
		else
		{
			//Õë¶Ô¹Ë¿Í£º
			for(int i=0;i<q;i++)	
			{
				if(plan[i].iff)
				{
					int ss = cstm[i].want.size();
					int t = cstm[i].come;
					int sss = 0;
					for(int j=0;j<ss;j++)
					{
						int did = cstm[i].want[j].g;
						//int id = plan[i].pd[j].id;
						int ts = plan[i].pd[j].ts;
						int tc = plan[i].pd[j].tc;
						if(ts < t)
						{
							flag = 0;break;	
						}
						if(ts > t + cstm[i].want[j].h)
						{
							flag = 0 ;break;}
						if(dish[did].tc > ts-tc)
						{
				//printf("cst: %d dish:%d j %d %d %d %d\nchushi\n",i,did,j,dish[did].tc,ts,tc);
							flag = 0;break;		
						}
							if(dish[did].td < ts - (tc + dish[did].tc))
							{
								flag = 0;break;	
							}
						t = ts + dish[cstm[i].want[j].g].te;
						sss += dish[cstm[i].want[j].g].p;
					}
					if(flag == 0)
					{
						break;
					}
					sum += sss;
				}
			}
//			if(flag == 1 && sum != x)
			{
//				flag = 0;
			}
			if(flag == 1)
			{
				//³øÊ¦£º
				for(int i=0;i<m;i++)
				{
					int ss = cookdo[i].dc.size();
					for(int j=0;j<ss;j++)
					{
						dcc[j] = cookdo[i].dc[j];
					}
					std::sort(dcc,dcc+ss,cmp);
					int t = -1;
					int id = -1;
					int te = -1;
					int cnt = 0 ;
					for(int j=0;j<ss;j++)
					{
						if(t == -1)
						{
							t = dcc[j].tc;
							te = t + dish[dcc[j].id].tc;
							id = dcc[j].id;
							if(mxdo[i][id] < 1)
							{
								FB		
							}
							cnt = 1;
						}
						else
						{
							if(dcc[j].tc == t)
							{
								if(dcc[j].id != id)	
								{
									flag = 0;break;	
								}
								else
								{
									cnt ++ ; 
									if(mxdo[i][id] < cnt)
									{
				//printf("chushi\n");
										flag = 0 ; break;}
								}
							}
							else 
							{
								if(dcc[j].tc >= te)
								{
									t = dcc[j].tc;
									id = dcc[j].id;
									te = t + dish[id].tc;
									cnt = 1;
									if(mxdo[i][id] < cnt)
									{FB}
								}
								else 
								{
				//printf("chushi\n");
									flag = 0; break;	
								}
							}
						}
					}
				}
			}
			if(flag == 1)
				printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
